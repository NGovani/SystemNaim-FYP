#include "ast_branch_nodes.hpp"




expressionStateInfo handleFuncArg(const std::string& stateName, const std::string& varName, NodePtr child, systemContext& ctx){
    expressionStateInfo returnState = ctx.getExprState();
    expressionStateInfo childState;
    childState.r = ctx.getCurrentModule().genTmpVar(varName);
    if(child == NULL) throw std::runtime_error("child pointer empty");
    ctx.addExprState(childState);
    child->convertToIL(ctx);
    expressionStateInfo& newChildState = ctx.getExprState();
    if(newChildState.cmd == ExpressionOperator::MOV){
        // if it was only a constant or primary expression then assign it straight to one of the operators
        returnState.op1 = newChildState.op1;
    } else{
        // if the child node is an expression, then assign the operand to the return and add a state
        returnState.op1 = newChildState.r;
        ctx.getCurrentModule().addState(stateName, stateContainer(newChildState));
        ctx.getCurrentModule().addVariable(newChildState.r, 32);
    }
    ctx.purgeExprState();

    return returnState;
}
// translation unit

void translation_unit::convertToIL(systemContext& ctx){
    for(auto const& func : this->branches){
        func->convertToIL(ctx);
    }
}

//declaration_sepcifier_list 

declaration_specifier_list::declaration_specifier_list(NodePtr p){branches.push_back(p);}
declaration_specifier_list::~declaration_specifier_list(){}


//init_declarator_list

void init_declarator_list::convertToIL(systemContext& ctx){
    for(const auto& param: this->branches){
        param->convertToIL(ctx);
    }
}

//argument_expression_list

argument_expression_list::argument_expression_list(NodePtr p){branches.push_back(p);}

void argument_expression_list::convertToIL(systemContext& ctx){
    functionCallStateInfo& s = ctx.getFuncState();
    
    for(int i = 0; i < s.inputList.size(); i++){
        expressionStateInfo e;
        std::string arg = s.inputList[i];
        e.r = arg;
        ctx.addExprState(e);
        if(this->branches[i] == NULL) throw std::runtime_error("Arg not present");
        e = handleFuncArg("funcArg", arg + "_tmp", this->branches[i], ctx);
        s.inputs[arg] = e.op1;
        ctx.purgeExprState();
    }
}


// parameter list

void parameter_list::convertToIL(systemContext& ctx){
    std::vector<std::string> param_list;
    for(const auto& param: this->branches){
        ctx.addDecCtx();
        param->convertToIL(ctx);
        param_list.push_back(ctx.getDecCtx().id);
        ctx.purgeDecCtx(); // this pops an element, might be worth resetting the element for speed
    }
    ctx.getDecCtx().funcInputs = param_list;
}
