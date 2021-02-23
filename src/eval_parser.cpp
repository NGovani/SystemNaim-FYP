#include "../include/pkg.hpp"
#include <iostream>


int main(int argc, char *argv[])
{

    if(argc != 2){ 
        std::cerr << "invalid input format" << std::endl;
        return -1;
    }

    //create AST
    Node* ast = parseAST(argv[1]);

    std::cout << "parsed Tree" << std::endl;
    
    ast->printTree(0);

    // expressionStateInfo e1 = {
    //     "b", //return
    //     expressionTerm(100),
    //     expressionTerm(0),
    //     MOV
    // };
    // expressionStateInfo e2 = {
    //     "a", //return
    //     expressionTerm("b"),
    //     expressionTerm(100),
    //     SUB
    // };

    // moduleContext m = moduleContext("main");
    
    // m.addVariable("a");
    // m.addVariable("b");
    
    // m.addState("test", stateContainer(e1));
    // m.addState("test", stateContainer(e2));
    // std::cout << m.printVerilog();

    return 0;
}
