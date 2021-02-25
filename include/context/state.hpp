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
    MOV // takes a single argument assigns value
};

using expressionTerm = std::variant<std::string, int>; // A term can be either a constant (int) or a variable (string)

struct expressionStateInfo{
    std::string r; // return variable
    expressionTerm op1;
    expressionTerm op2;
    ExpressionOperator cmd; // command type
    bool returnState = false; // true if this state should end function operation
};


struct functionStateInfo{};
struct branchStateInfo{};
struct conditionalStateInfo{};

using stateContainer = std::variant<expressionStateInfo, functionStateInfo, branchStateInfo, conditionalStateInfo>;

class stateInfo{
private:
    std::string stateName;
    stateContainer state;
public:
    stateInfo(std::string name, stateContainer info): state(info), stateName(name){};
    std::string printVerilog(std::string nextState);
    std::string getStateName(){return stateName;}
};


#endif