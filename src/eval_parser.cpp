#include "../include/pkg.hpp"
#include <iostream>


int main(int argc, char *argv[])
{

    // if(argc != 2){ 
    //     std::cerr << "invalid input format" << std::endl;
    //     return -1;
    // }

    // //create AST
    // Node* ast = parseAST(argv[1]);

    // std::cout << "parsed Tree" << std::endl;
    
    // ast->printTree(0);

    expressionStateInfo e = {
        "a", //return
        expressionTerm("b"),
        expressionTerm(100),
        SUB
    };
    stateContainer x = e;

    stateInfo s = stateInfo("test", x);
    std::cout << s.printVerilog() << std::endl;

    return 0;
}
