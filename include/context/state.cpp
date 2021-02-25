#include "state.hpp"
#include "../functional.hpp"

// func {
//     myVariant tmp = ds;
//     std::visit(functional::overload{
//         [&](const auto& x) {handleExpr(x);}
//     }, tmp );
// }

// prints the state logic for a given expression
std::string createExpressionVerilog(expressionStateInfo st){
    std::string exprString = st.r + " <= ";

    std::visit(functional::overload{
        [&](std::string& x) {exprString += x;},
        [&](int& x) {exprString += ("32'd"+ std::to_string(x));}
    }, st.op1);

    switch (st.cmd){
    case ADD:
        exprString += " + ";
        break;
    case SUB:
        exprString += " - ";
        break;
    case MUL:
        exprString += " * ";
        break;
    case DIV:
        exprString += " / ";
        break;
    case LS:
        exprString += " << ";
        break;
    case RS:
        exprString += " >> ";
        break;
    case MOV:
        exprString += ";\n";
        return exprString;
        break;
    default:
        exprString += " - ";
        break;
    }

    std::visit(functional::overload{
        [&](std::string& x) {exprString += x;},
        [&](int& x) {exprString += ("32'd"+ std::to_string(x));}
    }, st.op2);
    exprString += ";\n";
    return exprString;
}

std::string handleStateToVerilog(expressionStateInfo st, const std::string& nextState){
    std::string exprString = createExpressionVerilog(st);
    if(st.returnState){
        std::cerr << "insinde here" << std::endl;
        exprString += "done <= 1'b1\n";
        exprString += "state_next <= 16'd0\n";
    } else {
        exprString += "state_next <= " + nextState + ";\n";
    }
    return exprString;
}

std::string handleStateToVerilog(functionStateInfo st, const std::string& nextState){
}
std::string handleStateToVerilog(branchStateInfo st, const std::string& nextState){
}
std::string handleStateToVerilog(conditionalStateInfo st, const std::string& nextState){
}

std::string stateInfo::printVerilog(std::string nextState){
    std::string r;

    //add state name and begin keyword
    r += (this->stateName +": begin\n");

    //Add state logic
    std::visit(functional::overload{
        [&](const auto& st) {r += handleStateToVerilog(st, nextState);}
    }, this->state);
    //end keyword
    r += "end\n";
    return r;
}


