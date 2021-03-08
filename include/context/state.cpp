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
    std::string exprString = "\t" + st.r + " = ";

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
    case EQ:
        exprString += " == ";
        break;
    case NEQ:
        exprString += " != ";
        break;
    case GT:
        exprString += " > ";
        break;
    case GTE:
        exprString += " >= ";
        break;
    case LT:
        exprString += " < ";
        break;
    case LTE:
        exprString += " <= ";
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
        exprString += "\tdone = 1'b1;\n";
        exprString += "\tstate_next = 16'd0;\n";
    } else if (!st.nxtState.empty()) {
        exprString += "\tstate_next = " + st.nxtState + ";\n";
    }
    else {
        exprString += "\tstate_next = " + nextState + ";\n";
    }
    return exprString;
}

std::string handleStateToVerilog(functionStateInfo st, const std::string& nextState){
}
std::string handleStateToVerilog(branchStateInfo st, const std::string& nextState){
    if(!st.condVar.empty()){
        return "\tstate_next = " + st.condVar + " ? " + nextState + " : "  + st.jumpLabel + ";\n" ;
    } else {
        return "\tstate_next = " + st.jumpLabel + ";\n";
    }
}
std::string handleStateToVerilog(conditionalStateInfo st, const std::string& nextState){
}
std::string handleStateToVerilog(temporaryStateInfo st, const std::string& nextState){
    return "\tstate_next <= " + nextState + ";\n";
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

bool stateInfo::operator== (std::string _stateName){
    return this->stateName == _stateName;
}


