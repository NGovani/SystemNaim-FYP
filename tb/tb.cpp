#include "../obj_dir/Vhls_test_top.h"
#include "verilated.h"
#include "iostream"
extern "C"{
    #include "../test.c"
}
#include "stdlib.h"
#include "time.h"
#include <string>

int main(int argc, char** argv){
    srand(time(NULL));
    Verilated::commandArgs(argc, argv);
    int passed = 0, failed = 0;
    for(int i = 0; i < 20; ++i){
        Vhls_test_top* top = new Vhls_test_top;
        top->start = 0;
        top->reset = 0;
        top->clk_en = 0;
        int time = 0;

        // Inputs: numbers between 0 and 1000
        int in1 = rand() % 1000;
        int in2 = rand() % 1000;
        top->a = in1;
        top->b = in2;

        while(top->done != true){
            if(time > 10 && time < 20){
                top->reset = 0;
                top->start = 1;
                top->clk_en = 1;
            }
            if(time >= 20){
                top->reset = 0;
                top->start = 0;
                top->clk_en = 1;
            }
            if ((time % 10) == 0) {
                top->clk = 0; // Toggle clock
            }
            if ((time % 10) == 5) {
                top->clk = 1;
            }
            
            top->eval();
            time++;
        }
        if(hls_test_top(in1,in2) == top->d_out ){
            std::cout << "=======Test Passed========" << std::endl;
            std::cout << "Inputs: " << in1 << " " << in2 << std::endl;
            std::cout << "Output: " << hls_test_top(in1,in2) << std::endl;
            std::cout << "Cycles Taken: " << time/10 << std::endl;
            passed++;
        } else {
            std::cout << "=======Test Failed========" << std::endl;
            std::cout << "Got: " << top->d_out << std::endl;
            std::cout << "Expected: " << hls_test_top(in1,in2) << std::endl;
            std::cout << "Cycles: " << time/10 << std::endl; 
            failed++;
        }
    }
    std::cout << "======Final Results=======" << std::endl;
    std::cout << "Total Tests: " << passed + failed << std::endl;
    std::cout << "Successful Tests: " << passed << std::endl;
    std::cout << "Failed Tests: " << failed << std::endl;
}