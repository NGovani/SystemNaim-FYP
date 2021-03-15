#include "../include/pkg.hpp"
#include <iostream>
#include <fstream>

int main(int argc, char* argv[]){

    //args must be as followed: input_file.c
    if(argc != 2){ 
        std::cerr << "invalid input format" << std::endl;
        return -1;
    }

    //create AST
    Node* ast = parseAST(argv[1]);
    //create context and ostream
    static systemContext sysCtx;
    std::ofstream main_file, param_file;
    try
    {
        ast->convertToIL(sysCtx);
        sysCtx.printAllVerilog();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    // stream.close();
    return 0;
}