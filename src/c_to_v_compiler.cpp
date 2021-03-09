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
        std::cout << "======= Printing Verilog ======" << std::endl;
        main_file.open("out/func.v");
        main_file << sysCtx.getCurrentModule().printVerilog() << std::endl;
        main_file.close();
        param_file.open("out/func_params.vh");
        param_file << sysCtx.getCurrentModule().printParams() << std::endl;
        param_file.close();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    // stream.close();
    return 0;
}