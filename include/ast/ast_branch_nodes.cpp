#include "ast_branch_nodes.hpp"


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

//argument_declarator_list

argument_expression_list::argument_expression_list(NodePtr p){branches.push_back(p);}


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
