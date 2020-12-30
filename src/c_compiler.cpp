#include "../include/ast.hpp"

int main(int argc, char* argv[]){

    //args must be as followed: input_file.c
    if(argc != 2){ 
        std::cerr << "invalid input format" << std::endl;
        return -1;
    }

    //create AST
    Node* ast = parseAST(argv[2]);

    //create context and ostream
    compilerContext comCtx;
    std::ostream* os = &std::cout;
    std::ofstream stream;
    stream.open(argv[4]);
    os = &stream;
    
    //run print mips
    ast->printMips(comCtx, *os);
    stream.close();
    return 0;
}