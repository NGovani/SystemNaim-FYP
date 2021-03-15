#ifndef AST_BRANCH_NODES_HPP
#define AST_BRANCH_NODES_HPP

#include "ast_base_nodes.hpp"
//---------------------------------------------//
//------------BranchNodeS---------------------//
//        Nodes with branches in them          //
//---------------------------------------------//


//Root node contains all function definitions and declarations (which are global variables)
class translation_unit : public BranchNode{
	public:
	translation_unit(NodePtr p){branches.push_back(p);}
	void printTree(int n) {
		/*for(int i = 0; i < n; i++){
			std::cout<< "|\t" ;
		}*/
		//std::cout << "Translation Unit" <<std::endl;
		for(int i = 0; i < (int)branches.size(); i++){
			branches[i]->printTree(n);
		}
	}
	~translation_unit() {}

	void convertToIL(systemContext& ctx);

};

// declaration_specifier_list : Holds LHS of variable declarations. 
// Example: short int
// Always comes with a init_declarator_list node
class declaration_specifier_list : public BranchNode{
	public:
	declaration_specifier_list(NodePtr p);
	~declaration_specifier_list();

	void printTree(int n) {
		/*for(int i = 0; i < n; i++){
			std::cout<< "|\t" ;
		}*/
		//std::cout << "Declaration Specifier List" << std::endl;
		for(int i = 0; i < (int)branches.size(); i++){
			branches[i]->printTree(n);
		}
	}
	void convertToIL(systemContext& ctx){throw std::runtime_error("declaration_specifier_list not implemented");}
	
};

// init_declarator_list : Holds RHS of variable declarations. 
// Example: x = 2
// Always comes with a declaration_specifier_list node
class init_declarator_list : public BranchNode{
	public:
	init_declarator_list(NodePtr p){branches.push_back(p);} //branches contain init_declarator nodes

	void printTree(int n) {
		/*for(int i = 0; i < n; i++){
			std::cout<< "|\t" ;
		}*/
		//std::cout << "Init Declarator List" << std::endl;
		for(int i = 0; i < (int)branches.size(); i++){
			branches[i]->printTree(n);
		}
	}
	void convertToIL(systemContext& ctx);
	~init_declarator_list() {}
};


// argument_expression_list: Used for function calls
// Example: func(x, 2, y)
class argument_expression_list : public BranchNode{
	public:
	argument_expression_list(NodePtr p);
	void printTree(int n){
		std::cout<< "Arguments: [";
		for(int i = 0; i < (int)branches.size(); i++){
			std::cout << i+1 << ": ";
			branches[i]->printTree(n);
			if(i < (int)branches.size()-1){std::cout<< ", ";}
		}
		std::cout << "]";
	}
	void convertToIL(systemContext& ctx);
};


// function arguments
class parameter_list : public BranchNode{
	public:
	parameter_list(NodePtr p){branches.push_back(p);}
	void printTree(int n){
		for(int i = 0; i < n; i++){
			std::cout<< "|\t" ;
		}
		std::cout<< "Parameters: " << std::endl;
		for(int i = 0; i < (int)branches.size(); i++){
			branches[i]->printTree(n+1);
		}
	}
	void convertToIL(systemContext& ctx);
};

// identifier_list: list of variable
// Wierd function definition type
class identifier_list : public Node{
	public:
	std::vector<std::string> identifiers;
	identifier_list(std::string id){identifiers.push_back(id);}
	void push(std::string id){identifiers.push_back(id);}
	void printTree(int n){
		for(int i = 0; i < n; i++){
			std::cout<< "|\t" ;
		}
		std::cout<< "Idenitifers: ";
		for(int i = 0; i < (int)identifiers.size(); i++){
			std::cout<< identifiers[i] << " " ;
		}
		std::cout << std::endl;
	}
	void convertToIL(systemContext& ctx){throw std::runtime_error("identifier_list not implemented");}

	
};

// initialiser_list : Contains nodes for initialising variables and arrays
class initialiser_list : public BranchNode{
	public:
	initialiser_list(NodePtr p){branches.push_back(p);}
	void printTree(int n){
		for(int i = 0; i < (int)branches.size(); i++){
			branches[i]->printTree(n);
		}
	}
	void convertToIL(systemContext& ctx){throw std::runtime_error("initialiser_list not implemented");}
};

//--- NODES BELOW ARE NOT USED ---//


class struct_declaration_list : public BranchNode {
	public:
	struct_declaration_list(NodePtr p){branches.push_back(p);}
	void printTree(int n){
		for(int i = 0; i < (int)branches.size(); i++){
			branches[i]->printTree(n);
		}
	}

};

class struct_declarator_list : public BranchNode{
	public:
	struct_declarator_list(NodePtr p){branches.push_back(p);}
	void printTree(int n){
		for(int i = 0; i < (int)branches.size(); i++){
			branches[i]->printTree(n);
		}
	}
};

class declaration_list : public BranchNode{
	public:
	declaration_list(NodePtr p){branches.push_back(p);}
	void printTree(int n){
		for(int i = 0; i < (int)branches.size(); i++){
			branches[i]->printTree(n);
		}
	}
	void convertToIL(systemContext& ctx){throw std::runtime_error("declaration_list not implemented");}
};

class enumerator_list : public BranchNode{
	public:
	enumerator_list(NodePtr p){branches.push_back(p);}
	void printTree(int n){
		for(int i = 0; i < (int)branches.size(); i++){
			branches[i]->printTree(n);
		}
	}

};



#endif