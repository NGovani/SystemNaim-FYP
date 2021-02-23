#include "ast_spec_nodes.hpp"


//declaration

void declaration::convertToIL(systemContext& ctx){
    this->declarator_list->convertToIL(ctx);
}


//declaration_specifiers

declaration_specifiers::declaration_specifiers(std::string s): type_name(s) {}

// void declaration_specifiers::printMips(compilerContext& ctx, std::ostream& stream){
//     if(type_name == "int"){
//         ctx.tempDeclarator.size = 4; //size in bytes
//     }
// }


//init_declarator

void init_declarator::convertToIL(systemContext& ctx){
    ctx.addDecCtx();
    this->declaratorPtr->convertToIL(ctx);
    ctx.getCurrentModule().addVariable(ctx.getDecCtx().id);
    if(this->initialiserPtr != NULL){
        this->initialiserPtr->convertToIL(ctx);
    }
}


//direct_declarator

void direct_declarator::convertToIL(systemContext& ctx){
    ctx.getDecCtx().id = this->identifier; // set declarator context to this identifier so it can be used later
}

//initialiser

void initialiser::convertToIL(systemContext& ctx){
    expressionStateInfo initState; //holds info to initialise variable
    initState.r = ctx.getDecCtx().id;
    initState.cmd = ExpressionOperator::MOV;
    ctx.getExprState() = initState;
    this->assignment->convertToIL(ctx);
    // grab the expression state from the context and add it to the modules states
    ctx.getCurrentModule().addState("init_var", stateContainer(ctx.getExprState()));
    ctx.purgeExprState();
}

//ArrayDeclaration


//function definition
void function_definition::convertToIL(systemContext& ctx){
    this->name->convertToIL(ctx); // add module and inputs to context
    this->statement->convertToIL(ctx); // convert main body to IL
}


//FunctionDeclaration

void FunctionDeclaration::convertToIL(systemContext& ctx){
    ctx.addDecCtx();
    this->funcName->convertToIL(ctx);
    this->argList->convertToIL(ctx);

    declaratorContext tmpCtx = ctx.getDecCtx();

    ctx.addModule(tmpCtx.id, tmpCtx.funcInputs);
    ctx.purgeDecCtx();
}

// parameter_declaration

// simple because we ignore types
void parameter_declaration::convertToIL(systemContext& ctx){
    this->dec->convertToIL(ctx); // usually points to direct declarator so we just add that to ctx
}



