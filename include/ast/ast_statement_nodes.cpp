#include "ast_statement_nodes.hpp"

//Compound Statement
void compound_statement::convertToIL(systemContext& ctx){
    this->block_list->convertToIL(ctx);
}

void block_item_list::convertToIL(systemContext& ctx){
    for(const auto& item : this->branches){
        item->convertToIL(ctx);
    }
}

//IfStatement

void IfStatement::convertToIL(systemContext& ctx){
    // calculate condition expression
    std::string condVar = ctx.getCurrentModule().genTmpVar("cond");
    ctx.getCurrentModule().addVariable(condVar);
    expressionStateInfo condState;
    condState.r = condVar;

    ctx.addExprState(condState);
    if(this->cond == NULL) throw std::runtime_error("cond pointer empty");
    this->cond->convertToIL(ctx);
    ctx.getCurrentModule().addState("ifCondExpr", stateContainer(ctx.getExprState()));
    ctx.purgeExprState();
    //add branch state
    branchStateInfo ifBranch;
    temporaryStateInfo tmpState1; // state placeholder for after first compound statement
    std::string tmpStateName = ctx.getCurrentModule().genStateName("tmp"); //used as a placeholder to jump to
    ifBranch.condVar = condVar;
    ifBranch.jumpLabel = tmpStateName;
    tmpState1.jumpToHere.push_back(ctx.getCurrentModule().addState("ifBranch", stateContainer(ifBranch))); // add cond check state
    
    //print true statement
    if(this->_true == NULL) throw std::runtime_error("_true pointer empty");
    this->_true->convertToIL(ctx);
    std::string lastStateTrue = ctx.getCurrentModule().lastStateName();
    ctx.getCurrentModule().addNamedState(tmpStateName, stateContainer(tmpState1));
    //simple if statement complete, next is for else statement
    if(this->_false != NULL){
        temporaryStateInfo tmpState2; // state placeholder for after second compund
        std::string tmpStateName = ctx.getCurrentModule().genStateName("tmp");
        tmpState2.jumpToHere.push_back(lastStateTrue); //add last state from previous statement to vec: - 1 since previous state is tmp state
        this->_false->convertToIL(ctx);
        ctx.getCurrentModule().addNamedState(tmpStateName, stateContainer(tmpState2));
    }

}


// //WhileStatement
// void WhileStatement::printMips(compilerContext& ctx, std::ostream& stream){
//     std::string startLabel = ctx.generateLabel("start_");
//     std::string endLabel = ctx.generateLabel("end_");
//     ctx.currentFunc()->LoopsLabels.push_back(LoopContext(startLabel, endLabel, ctx.currentFunc()->scopes.size()));
//     stream << startLabel << ":" << std::endl;
//     cond->printMips(ctx, stream);
//     stream << "beq $2, $0, " << endLabel << "\nnop" << std::endl;
//     stmt->printMips(ctx, stream);
//     stream << "j " << startLabel << "\nnop" << std::endl;
//     stream << endLabel << ":" << std::endl;
//     stream << "move $2, $0" << std::endl;
//     ctx.currentFunc()->LoopsLabels.pop_back();
// }

// //Do statement
// void DoStatement::printMips(compilerContext& ctx, std::ostream& stream){
//     std::string startLabel = ctx.generateLabel("start_");
//     std::string endLabel = ctx.generateLabel("end_");
//     std::string doTrueLabel = ctx.generateLabel("doTrue_");

//     ctx.currentFunc()->LoopsLabels.push_back(LoopContext(startLabel, endLabel, ctx.currentFunc()->scopes.size()));

//     stream << doTrueLabel << ":" << std::endl;
//     stmt->printMips(ctx, stream);

//     stream << startLabel << ":" << std::endl;
//     cond->printMips(ctx, stream);

//     stream << "bne $2, 0, " << doTrueLabel << "\nnop" << std::endl;
//     stream << endLabel << ":" << std::endl;

//     stream << "move $2, $0" << std::endl;
//     ctx.currentFunc()->LoopsLabels.pop_back();

// }

// //ForStatement

// void ForStatement::printMips(compilerContext& ctx, std::ostream& stream){
//     std::string startLabel = ctx.generateLabel("start_");
//     std::string endLabel = ctx.generateLabel("end_");
//     std::string iterateLabel = ctx.generateLabel("iterate_");

//     ctx.currentFunc()->LoopsLabels.push_back(LoopContext(iterateLabel, endLabel, ctx.currentFunc()->scopes.size()));

//     if(init != NULL){init->printMips(ctx,stream);}

//     stream << startLabel << ":" << std::endl;
//     if(cond != NULL){cond->printMips(ctx,stream);}
//     stream << "beq $2, $0, " << endLabel << "\nnop" << std::endl;

//     if(stmt != NULL){stmt->printMips(ctx,stream);}

//     stream << iterateLabel << ":" << std::endl;
//     if(iter != NULL){iter->printMips(ctx,stream);}
//     stream << "j " << startLabel << "\nnop" << std::endl;

//     stream << endLabel << ":" << std::endl;
//     stream << "move $2, $0" << std::endl;
//     ctx.currentFunc()->LoopsLabels.pop_back();
// }


//ReturnStatement

void ReturnStatement::convertToIL(systemContext& ctx){
    expressionStateInfo returnValState; //holds info to initialise variable
    returnValState.r = "d_out";
    returnValState.returnState = true;
    ctx.addExprState(returnValState);
    this->expr->convertToIL(ctx);
    // grab the expression state from the context and add it to the modules states
    ctx.getCurrentModule().addState("return", stateContainer(ctx.getExprState()));
    ctx.purgeExprState();
}


// Expressions Statement

void expression_statement::convertToIL(systemContext& ctx){
    if(this->stmt != NULL)
        this->stmt->convertToIL(ctx);
}

// void ContinueStatement::printMips(compilerContext& ctx, std::ostream& stream){
//     std::vector<LoopContext>::reverse_iterator rit = ctx.currentFunc()->LoopsLabels.rbegin();
//     for(;(*rit).cont.empty();++rit){}  
//     int stackUsed= ctx.currentFunc()->memUsed - ctx.currentFunc()->scopes[(*rit).scopeLvl].stackOffset;
//     stream << "addi $sp, $sp, " << stackUsed << std::endl;
//     stream << "j " << (*rit).cont << " \nnop" << std::endl;
// }

// void BreakStatement::printMips(compilerContext& ctx, std::ostream& stream){
//     int stackUsed= ctx.currentFunc()->memUsed - ctx.currentFunc()->scopes[ctx.currentFunc()->LoopsLabels.back().scopeLvl].stackOffset;
//     stream << "addi $sp, $sp, " << stackUsed << std::endl;
//     stream << "j " << ctx.currentFunc()->LoopsLabels.back().brk << " \nnop" << std::endl;
// }

// void expression_statement::printMips(compilerContext& ctx, std::ostream& stream){
//     if(stmt != NULL){stmt->printMips(ctx,stream);}
// }

// //SwitchStatement

// void SwitchStatement::printMips(compilerContext& ctx, std::ostream& stream){
//     ctx.addToStack(8, stream);
//     storeOperand(18,0,stream); //for test
//     storeOperand(19,4,stream); //for flags
//     int memUsedStore = ctx.currentFunc()->memUsed;
//     if(test != NULL){test->printMips(ctx,stream);}
//     addOperands(18,2,0, stream); //set to test val
//     addOperands(19,0,0, stream); //set to 0
//     std::string skipLabel = ctx.generateLabel("skip_");
//     std::string endLabel = ctx.generateLabel("end_");
//     ctx.currentFunc()->LoopsLabels.push_back(LoopContext(endLabel, ctx.currentFunc()->scopes.size()));
//     ctx.currentFunc()->swtchCtx.push_back(SwitchContext());
//     ctx.currentFunc()->swtchCtx.back().prevLabel = skipLabel;
//     stream << "j " << skipLabel << std::endl;
//     if(stmt != NULL){stmt->printMips(ctx,stream);}
//     if(!(ctx.currentFunc()->swtchCtx.back().prevLabel.empty())){
//         stream << ctx.currentFunc()->swtchCtx.back().prevLabel << ":" << std::endl;
//     }
//     ctx.currentFunc()->swtchCtx.pop_back();
//     stream << endLabel << ":" << std::endl;
//     int switchMem = ctx.currentFunc()->memUsed - memUsedStore;
//     stream << "addi $sp, $sp, " << switchMem << std::endl;
//     ctx.currentFunc()->memUsed = memUsedStore;
//     loadOperand(18,0,stream);
//     loadOperand(19,4,stream);
//     ctx.addToStack(8, stream);
// }

// //CaseStatement

// void CaseStatement::printMips(compilerContext& ctx, std::ostream& stream){
//     int caseVal = 0;
//     stream << ctx.currentFunc()->swtchCtx.back().prevLabel << ":" << std::endl;
//     std::string caseLabel = ctx.generateLabel("case_");
//     ctx.currentFunc()->swtchCtx.back().prevLabel = caseLabel;
//     if(val != NULL){caseVal = val->eval();}
//     stream << "addi $8, $0, " << caseVal << std::endl;
//     stream << "xor $2,$18,$8" << std::endl;            //magically works?
//     stream << "slti $2,$2, 1" << std::endl;
//     stream << "or $2, $2, $19" << std::endl;
//     stream << "beq $0, $2, " << caseLabel << std::endl; //shouldnt print if last one
//     stream << "nop" << std::endl;
//     stream << "addi $19, $0, 1" << std::endl; //set 19 to 1 if you hit this
//     if(stmt != NULL){stmt->printMips(ctx, stream);}
// }

// //DefaultStatement
// void DefaultStatement::printMips(compilerContext& ctx, std::ostream& stream){
//     stream << ctx.currentFunc()->swtchCtx.back().prevLabel << ":" << std::endl;
//     ctx.currentFunc()->swtchCtx.back().prevLabel.clear();
//     if(stmt != NULL){stmt->printMips(ctx, stream);}
// }