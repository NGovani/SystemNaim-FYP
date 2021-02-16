#include "state.hpp"
#include "../functional.hpp"

// func {
//     myVariant tmp = ds;
//     std::visit(functional::overload{
//         [&](const auto& x) {handleExpr(x);}
//     }, tmp );
// }

std::string handleStateToVerilog(expressionStateInfo st){
    std::string exprString = st.r + " <= ";

    std::visit(functional::overload{
        [&](std::string& x) {exprString += x;},
        [&](int& x) {exprString += ("32'd"+ std::to_string(x));}
    }, st.op1);

    switch (st.cmd){
    case ADD:
        exprString += " + ";
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

std::string handleStateToVerilog(functionStateInfo st){
}
std::string handleStateToVerilog(branchStateInfo st){
}
std::string handleStateToVerilog(conditionalStateInfo st){
}

std::string stateInfo::printVerilog(std::string nextState){
    std::string r;

    //add state name and begin keyword
    r += (this->stateName +": begin\n");

    //Add state logic
    std::visit(functional::overload{
        [&](const auto& st) {r += handleStateToVerilog(st);}
    }, this->state);
    r += "state_next <= " + nextState + ";\n";
    //end keyword
    r += "end\n";
    return r;
}


