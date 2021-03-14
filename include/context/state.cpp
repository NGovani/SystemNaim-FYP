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
    std::string exprString = "\t" + st.r + "_next = ";

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


//--------STATE LOGIC-----//
std::string handleStateToVerilog(expressionStateInfo st){
    std::string exprString = createExpressionVerilog(st);
    if(st.returnState){
        exprString += "\tdone_next = 1'b1;\n";
    }
    return exprString;
}



std::string handleStateToVerilog(functionCallStateInfo st){
    std::string returnString;
    for(auto const& [reg, input] : st.inputs){
        returnString += "\t" + reg + " = " + input + ";\n";
    }
    returnString += "\t" + st.startSignal + " = 1'd1;\n";
}
std::string handleStateToVerilog(functionWaitStateInfo st){
    return "\t" + st.startSignal + " = 1'd0;\n";
}

std::string handleStateToVerilog(branchStateInfo st){
    return ";\n";
}

std::string handleStateToVerilog(temporaryStateInfo st){
    return ";\n";
}


//-----STATE TRANSITION LOGIC-----//
std::string handleStateChange(expressionStateInfo st, const std::string& nextState){
    if(st.returnState){
        return "\tstate <= 16'd0;\n";
    } else if (!st.nxtState.empty()) {
        return "\tstate <= " + st.nxtState + ";\n";
    }
    else {
        return "\tstate <= " + nextState + ";\n";
    }
}

std::string handleStateChange(functionCallStateInfo st, const std::string& nextState){
    return "\tstate <= " + nextState + ";\n";
}


std::string handleStateChange(functionWaitStateInfo st, const std::string& nextState){
    return "\tstate <= " +  st.doneSignal + " ? " + nextState + " : state;\n";
}

std::string handleStateChange(branchStateInfo st, const std::string& nextState){
    if(!st.condVar.empty()){
        return "\tstate <= " + st.condVar + " ? " + nextState + " : "  + st.jumpLabel + ";\n" ;
    } else {
        return "\tstate <= " + st.jumpLabel + ";\n";
    }
}


std::string handleStateChange(temporaryStateInfo st, const std::string& nextState){
    return "\tstate <= " + nextState + ";\n";
}



std::string stateInfo::printVerilogState(){
    std::string r;

    //add state name and begin keyword
    r += (this->stateName +": begin\n");

    //Add state logic
    std::visit(functional::overload{
        [&](const auto& st) {r += handleStateToVerilog(st);}
    }, this->state);
    //end keyword
    r += "end\n";
    return r;
}

std::string stateInfo::printVerilogStateChange(std::string nextState){
    std::string r;

    //add state name and begin keyword
    r += (this->stateName +": begin\n");

    //Add state logic
    std::visit(functional::overload{
        [&](const auto& st) {r += handleStateChange(st, nextState);}
    }, this->state);
    //end keyword
    r += "end\n";
    return r;
}

bool stateInfo::operator== (std::string _stateName){
    return this->stateName == _stateName;
}


