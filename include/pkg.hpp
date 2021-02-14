#ifndef ast_hpp
#define ast_hpp


// Nodes types which all other nodes inherit from
#include "ast/ast_base_nodes.hpp"

// Nodes that contain a variable number of children i.e. function argument lists and initialiser lists
#include "ast/ast_branch_nodes.hpp"

// Node that contain as arithmetic or function calls
#include "ast/ast_expression_nodes.hpp"

// Nodes which generally control the flow of the program
#include "ast/ast_statement_nodes.hpp"

// Nodes with specific pointer, contains function and variable declarators
#include "ast/ast_spec_nodes.hpp"

// Context used when compilining
#include "context/context.hpp"


extern Node *parseAST(char* fileName);

#endif
