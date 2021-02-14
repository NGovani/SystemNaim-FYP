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

    return 0;
}
