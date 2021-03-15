#ifndef STATE_HPP
#define STATE_HPP

#include <string>
#include <iostream>
#include <memory>
#include <initializer_list>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <sstream>
#include <variant>

enum ExpressionOperator{
    ADD,
    SUB,
    MUL,
    DIV,
    LS, //left shift
    RS, //right shift
    EQ,
    NEQ,
    GT,
    GTE,
    LT,
    LTE,
    MOV // takes a single argument assigns value
};

using expressionTerm = std::variant<std::string, int>; // A term can be either a constant (int) or a variable (string)

struct expressionStateInfo{
    std::string r; // return variable
    expressionTerm op1;
    expressionTerm op2;
    ExpressionOperator cmd; // command type
    bool returnState = false; // true if this state should end function operation

    std::string nxtState; // used if this state needs to go to another state after its complete
};


struct functionCallStateInfo{// state for calling a function: in the future might be used to call multiple functions
    std::string startSignal;
    std::vector<std::string> inputList;// used for compilation to share data between call node and arugement list node
    std::map<std::string, expressionTerm> inputs; //key = module input reg, val = variable being passed 
}; 

struct functionWaitStateInfo{ // state for waiting on a function/s after they have been called
    std::string startSignal;
    std::string doneSignal;
    std::string d_outWire;
    std::string d_outReg;
};

struct branchStateInfo{
    std::string condVar; //If this has a value then this is a conditional branch
    std::string jumpLabel; // label to jump to, if no condition this is auto taken

    std::string nxtState; // used if this state needs to go to another state after its complete
};


struct temporaryStateInfo{  // Empty state, used as a placeholder for states which need to jump to something after their operation is over
    std::vector<std::string> jumpToHere; //list of states which jump to this state
};


using stateContainer = std::variant<expressionStateInfo, functionCallStateInfo, functionWaitStateInfo, branchStateInfo, temporaryStateInfo>;

class stateInfo{
private:
    std::string stateName;
    stateContainer state;
public:
    stateInfo(std::string name, stateContainer info): state(info), stateName(name){};
    std::string printVerilogState();
    std::string printVerilogStateChange(std::string nextState);

    std::string getStateName(){return stateName;}
    stateContainer& getState(){return state;}
    bool operator== (std::string _stateName);
};


#endif