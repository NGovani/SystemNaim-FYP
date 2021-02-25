#include "../include/pkg.hpp"

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
    // std::ostream* os = &std::cout;
    // std::ofstream stream;
    
    //run print mips
    try
    {
        ast->convertToIL(sysCtx);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "here" << std::endl;
    std::cout << sysCtx.getCurrentModule().printVerilog() << std::endl;

    // stream.close();
    return 0;
}