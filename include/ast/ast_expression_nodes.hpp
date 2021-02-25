#ifndef AST_EXPRESSION_NODES_HPP
#define AST_EXPRESSION_NODES_HPP

#include "ast_base_nodes.hpp"

//printMips implementations are written in cpp


class primary_expression : public ExpressionNode{
	public:
	std::string identifier;
	primary_expression(std::string s): identifier(s) {}
	void printTree(int n) {
		std::cout << identifier;
	}
	void convertToIL(systemContext& ctx);
};

class constantNode : public ExpressionNode{
	public:
	double init;
	constantNode(double n): init(n) {}
	void printTree(int n) {
		std::cout << init;
	}
	void convertToIL(systemContext& ctx);
	

	int eval();
};

class stringNode : public ExpressionNode{
	public:
	std::string init;
	stringNode(std::string n): init(n) {}
	void printTree(int n) {
		std::cout << init;
	}
	void convertToIL(systemContext& ctx){throw std::runtime_error("stringNode not implemented");}
};

class assignment_expression : public ExpressionNode{
	public:
	ExpPtr left = NULL, right= NULL;
	std::string op;
	assignment_expression(ExpPtr a, std::string b, ExpPtr c): left(a), right(c), op(b) {} 
	void printTree(int n) {
		if(left != NULL){left->printTree(n);}
		std::cout<< " " << op << " " ;
		if(right != NULL){right->printTree(n);}
	}
	void convertToIL(systemContext& ctx){throw std::runtime_error("assignment_expression not implemented");}
	
};	

class conditional_expression: public ExpressionNode{
	public:
	ExpPtr Cond = NULL, TrueExp= NULL, FalseExp= NULL;
	conditional_expression(ExpPtr a, ExpPtr b, ExpPtr c): Cond(a), TrueExp(b), FalseExp(c) {} 
	void printTree(int n) {
		if(Cond != NULL){Cond->printTree(n);}
		std::cout << " ? ";
		if(TrueExp != NULL){TrueExp->printTree(n);}
		std::cout << " : ";
		if(FalseExp != NULL){FalseExp->printTree(n);}
	}
	void convertToIL(systemContext& ctx){throw std::runtime_error("conditional_expression not implemented");}
	

	int eval();
};

class LogicalOrOp: public ExpressionNode{
	public:
	ExpPtr left = NULL, right= NULL;
	LogicalOrOp(ExpPtr a, ExpPtr b): left(a), right(b){} 
	void printTree(int n) {
		if(left != NULL){left->printTree(n);}
		std::cout << " || ";
		if(right != NULL){right->printTree(n);}
	}
	void convertToIL(systemContext& ctx){throw std::runtime_error("LogicalOrOp not implemented");}
	

	int eval();
};

class LogicalAndOp: public ExpressionNode{
	public:
	ExpPtr left = NULL, right= NULL;
	LogicalAndOp(ExpPtr a, ExpPtr b): left(a), right(b){} 
	void printTree(int n) {
		
		if(left != NULL){left->printTree(n);}
		std::cout << " && ";
		if(right != NULL){right->printTree(n);}
	}
	void convertToIL(systemContext& ctx){throw std::runtime_error("LogicalAndOp not implemented");}
	

	int eval();
};

class InclusiveOrOp: public ExpressionNode{
	public:
	ExpPtr left = NULL, right= NULL;
	InclusiveOrOp(ExpPtr a, ExpPtr b): left(a), right(b){} 
	void printTree(int n) {
		if(left != NULL){left->printTree(n);}
		std::cout << " | ";
		if(right != NULL){right->printTree(n);}
	}
	void convertToIL(systemContext& ctx){throw std::runtime_error("InclusiveOrOp not implemented");}
	
	int eval();
};

class ExclusiveOrOp: public ExpressionNode{
	public:
	ExpPtr left = NULL, right= NULL;
	ExclusiveOrOp(ExpPtr a, ExpPtr b): left(a), right(b){} 
	void printTree(int n) {
		if(left != NULL){left->printTree(n);}
		std::cout << " ^ ";
		if(right != NULL){right->printTree(n);}
	}
	void convertToIL(systemContext& ctx){throw std::runtime_error("ExclusiveOrOp not implemented");}
	
	int eval();
};

class AndOp: public ExpressionNode{
	public:
	ExpPtr left = NULL, right= NULL;
	AndOp(ExpPtr a, ExpPtr b): left(a), right(b){} 
	void printTree(int n) {
		if(left != NULL){left->printTree(n);}
		std::cout << " & ";
		if(right != NULL){right->printTree(n);}
	}
	void convertToIL(systemContext& ctx){throw std::runtime_error("AndOp not implemented");}
	
	int eval();
};

class EqualOp: public ExpressionNode{
	public:
	ExpPtr left = NULL, right= NULL;
	EqualOp(ExpPtr a, ExpPtr b): left(a), right(b){} 
	void printTree(int n) {
		if(left != NULL){left->printTree(n);}
		std::cout << " == ";
		if(right != NULL){right->printTree(n);}
	}
	void convertToIL(systemContext& ctx){throw std::runtime_error("EqualOp not implemented");}
	
	int eval();
};

class NotEqualOp: public ExpressionNode{
	public:
	ExpPtr left = NULL, right= NULL;
	NotEqualOp(ExpPtr a, ExpPtr b): left(a), right(b){} 
	void printTree(int n) {
		if(left != NULL){left->printTree(n);}
		std::cout << " != ";
		if(right != NULL){right->printTree(n);}
	}
	void convertToIL(systemContext& ctx){throw std::runtime_error("NotEqualOp not implemented");}
	
	int eval();
};

class GreaterThanOp: public ExpressionNode{
	public:
	ExpPtr left = NULL, right= NULL;
	GreaterThanOp(ExpPtr a, ExpPtr b): left(a), right(b){} 
	void printTree(int n) {
		if(left != NULL){left->printTree(n);}
		std::cout << " > ";
		if(right != NULL){right->printTree(n);}
	}
	void convertToIL(systemContext& ctx){throw std::runtime_error("GreaterThanOp not implemented");}
	
	int eval();
};

class LessThanOp: public ExpressionNode{
	public:
	ExpPtr left = NULL, right= NULL;
	LessThanOp(ExpPtr a, ExpPtr b): left(a), right(b){} 
	void printTree(int n) {
		if(left != NULL){left->printTree(n);}
		std::cout << " < ";
		if(right != NULL){right->printTree(n);}
	}
	void convertToIL(systemContext& ctx){throw std::runtime_error("LessThanOp not implemented");}
	
	int eval();
};

class LessThanEqOp: public ExpressionNode{
	public:
	ExpPtr left = NULL, right= NULL;
	LessThanEqOp(ExpPtr a, ExpPtr b): left(a), right(b){} 
	void printTree(int n) {
		if(left != NULL){left->printTree(n);}
		std::cout << " <= ";
		if(right != NULL){right->printTree(n);}
	}
	void convertToIL(systemContext& ctx){throw std::runtime_error("LessThanEqOp not implemented");}
	
	int eval();
};

class GreaterThanEqOp: public ExpressionNode{
	public:
	ExpPtr left = NULL, right= NULL;
	GreaterThanEqOp(ExpPtr a, ExpPtr b): left(a), right(b){} 
	void printTree(int n) {
		if(left != NULL){left->printTree(n);}
		std::cout << " >= ";
		if(right != NULL){right->printTree(n);}
	}
	void convertToIL(systemContext& ctx){throw std::runtime_error("GreaterThanEqOp not implemented");}
	
	int eval();
};

class LeftShiftOp: public ExpressionNode{
	public:
	ExpPtr left = NULL, right= NULL;
	LeftShiftOp(ExpPtr a, ExpPtr b): left(a), right(b){} 
	void printTree(int n) {
		if(left != NULL){left->printTree(n);}
		std::cout << " << ";
		if(right != NULL){right->printTree(n);}
	}
	void convertToIL(systemContext& ctx);
	
	int eval();
};

class RightShiftOp: public ExpressionNode{
	public:
	ExpPtr left = NULL, right= NULL;
	RightShiftOp(ExpPtr a, ExpPtr b): left(a), right(b){} 
	void printTree(int n) {
		if(left != NULL){left->printTree(n);}
		std::cout << " >> ";
		if(right != NULL){right->printTree(n);}
	}
	void convertToIL(systemContext& ctx);
	
	int eval();
};

class AddOp: public ExpressionNode{
	public:
	ExpPtr left = NULL, right= NULL;
	AddOp(ExpPtr a, ExpPtr b): left(a), right(b){} 
	void printTree(int n) {
		if(left != NULL){left->printTree(n);}
		std::cout << " + ";
		if(right != NULL){right->printTree(n);}
	}
	void convertToIL(systemContext& ctx);
	
	int eval();
};

class SubOp: public ExpressionNode{
	public:
	ExpPtr left = NULL, right= NULL;
	SubOp(ExpPtr a, ExpPtr b): left(a), right(b){} 
	void printTree(int n) {
		if(left != NULL){left->printTree(n);}
		std::cout << " - ";
		if(right != NULL){right->printTree(n);}
	}
	void convertToIL(systemContext& ctx);
	
	int eval();
};

class MultOp: public ExpressionNode{
	public:
	ExpPtr left = NULL, right= NULL;
	MultOp(ExpPtr a, ExpPtr b): left(a), right(b){} 
	void printTree(int n) {
		if(left != NULL){left->printTree(n);}
		std::cout << " * ";
		if(right != NULL){right->printTree(n);}
	}
	void convertToIL(systemContext& ctx);
	
	int eval();
};

class DivOp: public ExpressionNode{
	public:
	ExpPtr left = NULL, right= NULL;
	DivOp(ExpPtr a, ExpPtr b): left(a), right(b){} 
	void printTree(int n) {
		if(left != NULL){left->printTree(n);}
		std::cout << " / ";
		if(right != NULL){right->printTree(n);}
	}
	void convertToIL(systemContext& ctx);
	
	int eval();
};

class  ModulusOp: public ExpressionNode{
	public:
	ExpPtr left = NULL, right= NULL;
	ModulusOp(ExpPtr a, ExpPtr b): left(a), right(b){} 
	void printTree(int n) {
		if(left != NULL){left->printTree(n);}
		std::cout << " % ";
		if(right != NULL){right->printTree(n);}
	}
	void convertToIL(systemContext& ctx){throw std::runtime_error("ModulusOp not implemented");}
	
	int eval();
};

class cast_expression: public ExpressionNode{
    public:
    NodePtr left = NULL;
    ExpPtr right = NULL;
    cast_expression(NodePtr a, ExpPtr b): left(a), right(b){}
    void printTree(int n){
        std::cout << "( ";
        if(left != NULL){left->printTree(n);}
        std::cout << " ) ";
        if(right != NULL){right->printTree(n);}
    }
	void convertToIL(systemContext& ctx){throw std::runtime_error("cast_expression not implemented");}
};

class PreIncOp: public ExpressionNode{
    public: 
    ExpPtr expr = NULL;
    PreIncOp(ExpPtr a): expr(a){}
    void printTree(int n){
        std::cout << "++";
        if(expr != NULL){expr->printTree(n);}
    }
	void convertToIL(systemContext& ctx){throw std::runtime_error("PreIncOp not implemented");}
	
};

class PreDecOp: public ExpressionNode{
    public: 
    ExpPtr expr = NULL;
    PreDecOp(ExpPtr a): expr(a){}
    void printTree(int n){
        std::cout << "--";
        if(expr != NULL){expr->printTree(n);}
    }
	void convertToIL(systemContext& ctx){throw std::runtime_error("PreDecOp not implemented");}
	
};

class PostIncOp: public ExpressionNode{
    public: 
    ExpPtr expr = NULL;
    PostIncOp(ExpPtr a): expr(a){}
    void printTree(int n){
        if(expr != NULL){expr->printTree(n);}
        std::cout << "++";
    }
	void convertToIL(systemContext& ctx){throw std::runtime_error("PostIncOp not implemented");}
	
};

class PostDecOp: public ExpressionNode{
    public: 
    ExpPtr expr = NULL;
    PostDecOp(ExpPtr a): expr(a){}
    void printTree(int n){
        if(expr != NULL){expr->printTree(n);}
        std::cout << "--";    
    }
	void convertToIL(systemContext& ctx){throw std::runtime_error("PostDecOp not implemented");}
	
};

class RefOp: public ExpressionNode{
	public:
	ExpPtr expr = NULL;
	RefOp(ExpPtr a): expr(a){}
	void printTree(int n){
        if(expr != NULL){std::cout<< "&" ;expr->printTree(n);}
    }
	void convertToIL(systemContext& ctx){throw std::runtime_error("RefOp not implemented");}
	
};
//do we need this?

class PtrOp: public ExpressionNode{
	public:
	ExpPtr expr = NULL;
	PtrOp(ExpPtr a): expr(a){}
	void printTree(int n){
        if(expr != NULL){std::cout<< "->" ;expr->printTree(n);}
    }
	void convertToIL(systemContext& ctx){throw std::runtime_error("PtrOp not implemented");}
	
};
//do we need this?

class UAddOp: public ExpressionNode{
	public:
	ExpPtr expr = NULL;
	UAddOp(ExpPtr a): expr(a){}
	void printTree(int n){
        if(expr != NULL){std::cout<< "+" ;expr->printTree(n);}
    }
	void convertToIL(systemContext& ctx){throw std::runtime_error("UAddOp not implemented");}
	

	int eval();
};

class USubOp: public ExpressionNode{
	public:
	ExpPtr expr = NULL;
	USubOp(ExpPtr a): expr(a){}
	void printTree(int n){
        if(expr != NULL){std::cout<< "-" ;expr->printTree(n);}
    }
	void convertToIL(systemContext& ctx){throw std::runtime_error("USubOp not implemented");}
	

	int eval();
};

class BitwiseNotOp: public ExpressionNode{
	public:
	ExpPtr expr = NULL;
	BitwiseNotOp(ExpPtr a): expr(a){}
	void printTree(int n){
        if(expr != NULL){std::cout<< "~" ;expr->printTree(n);}
    }	
	void convertToIL(systemContext& ctx){throw std::runtime_error("BitwiseNotOp not implemented");}
	

	int eval();
};

class LogicalNotOp: public ExpressionNode{
	public:
	ExpPtr expr = NULL;
	LogicalNotOp(ExpPtr a): expr(a){}
	void printTree(int n){
        if(expr != NULL){std::cout<< "!" ;expr->printTree(n);}
    }	
	void convertToIL(systemContext& ctx){throw std::runtime_error("LogicalNotOp not implemented");}
	

	int eval();
};

class SizeOf: public ExpressionNode{
    public: 
    NodePtr decList = NULL;
    ExpPtr expr = NULL;
    bool primitive = false;
    SizeOf(NodePtr a): decList(a){primitive = true;}
	SizeOf(ExpPtr a): expr(a){primitive = false;}
    void printTree(int n){
		std::cout << "SizeOf: "; 
        if(expr != NULL){decList->printTree(n);}
		if(expr != NULL){expr->printTree(n);}
    }
	void convertToIL(systemContext& ctx){throw std::runtime_error("SizeOf not implemented");}
};

class array_call: public ExpressionNode{ //TODO
    public: 
    ExpPtr array = NULL, idx = NULL;
	array_call(ExpPtr _array, ExpPtr _idx): array(_array), idx(_idx) {}
	void printTree(int n){
        if(array != NULL){array->printTree(n);}
		std::cout << "[" ;
		if(idx != NULL){idx->printTree(n);}
		std::cout << "]" ;
    }
	void convertToIL(systemContext& ctx){throw std::runtime_error("array_call not implemented");}

	
};

class function_call: public ExpressionNode{
    public: 
    ExpPtr expr = NULL;
    NodePtr list = NULL;
    function_call(ExpPtr a, NodePtr b): expr(a), list(b){}
    void printTree(int n){
		std::cout<< "Function Call: { Name: ";
        if(expr != NULL){expr->printTree(n);}
		std::cout<< ", ";
        if(list != NULL){list->printTree(n);}
		std::cout << " }";
    }
	void convertToIL(systemContext& ctx){throw std::runtime_error("function_call not implemented");}
	
};

class DotMemberOp : public ExpressionNode{
	public:
	std::string member;
	ExpPtr obj = NULL;
	DotMemberOp(ExpPtr _obj, std::string _member): member(_member), obj(_obj) {}
	void printTree(int n){
        if(obj != NULL){obj->printTree(n);}
        std::cout << "." << member;
    }
	void convertToIL(systemContext& ctx){throw std::runtime_error("DotMemberOp not implemented");}
};

class PtrMemberOp : public ExpressionNode{
	public:
	std::string member;
	ExpPtr obj = NULL;
	PtrMemberOp(ExpPtr _obj, std::string _member): member(_member), obj(_obj) {}
	void printTree(int n){
        if(obj != NULL){obj->printTree(n);}
        std::cout << "->" << member;
    }
	void convertToIL(systemContext& ctx){throw std::runtime_error("PtrMemberOp not implemented");}
};


#endif