#ifndef CONTEXT_HPP
#define CONTEXT_HPP

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
#include "state.hpp"

//DeclaratorContext: used to hold information about variable and function declarations
struct declaratorContext{
    std::string id;
    std::vector<std::string> funcInputs;
    bool initliased = false;
    int elements = 1; // usually for arrays, set to 1 by default for normal declaration
    bool isArray = false;

};

struct LoopContext{ //needed for continue and break
    std::string cont, brk ;
    int scopeLvl;
    LoopContext(std::string _cont, std::string _brk, int _scope): cont(_cont), brk(_brk), scopeLvl(_scope){}
    LoopContext(std::string _brk, int _scope): brk(_brk), scopeLvl(_scope){} //for switches
};


struct varData{
    bool isArray = false;
    int elements = 1;

    varData(){} //usually varData is not needed, just for arrays;
    varData(int _elements): isArray(true), elements(_elements){}
};

struct scope{
    std::map<std::string, varData> bindings; 
    int stackOffset;

    scope(std::map<std::string, varData> _bindings, int _stackOffset);
    void addToBindings(std::string id, int offset, int elements, int size, bool global, bool pointer);
};

struct funcScope{
    int scopeLevel = 0;

    std::vector<scope> scopes;
    std::map<std::string, varData> parameters;
    std::vector<LoopContext> LoopsLabels;

    int memUsed = 0; //should be incremented as you add new bindings
    void incScope();
    void decScope(std::ostream& stream);
    funcScope(std::ostream& stream, std::map<std::string, varData> _globalVars);
     //the function definition node should pack the info correctly
};  //for a function with parameters.


// moduleContext: keeps track of variables and states for a specific module.
class moduleContext{
private:
    std::string moduleName;
    int stateCount;
    std::vector<stateInfo> states; //list of all states to be converted into verilog states;
    std::map<std::string, varData> variables;
    std::vector<std::string> inputs; //max 2 input variables
    int varCount;
    void handleTempState(const std::string& stateName, const stateContainer& stateData);
public:
    moduleContext(std::string _moduleName): stateCount(0), varCount(0), moduleName(_moduleName) {}
    moduleContext(std::string _moduleName, std::vector<std::string> _inputs): stateCount(0), varCount(0), moduleName(_moduleName), inputs(_inputs) {}
    std::string addState(const std::string& stateName, const stateContainer& stateData); //generates a state name and adds it the state list, return index of state
    void addNamedState(const std::string& stateName, const stateContainer& stateData); // does not generate a state name, assume label has already been generated, return index of state
    void addVariable(const std::string& varName);
    void addVariable(const std::string& varName, int elements); //used for arrays
    std::string printVerilog();
    std::string genStateName(const std::string& stateName);
    std::string genTmpVar(const std::string& varName);
    stateInfo& findState(std::string stateName);
    std::string lastStateName();
};

// systemContext :  contains all modules which are to be created, aswell as structs to hold data
//                  between nodes
class systemContext {
private:
    std::vector<moduleContext> modules; // holds all module data, including the states they have
    std::vector<declaratorContext> decCtx; // holds data for declarations
    std::vector<expressionStateInfo> exprStates; //used to create expression states across nodes. might be worth turning into a vector
public:
    expressionStateInfo& getExprState();
    void addExprState(expressionStateInfo e);
    void purgeExprState();
    declaratorContext& getDecCtx(); // get current declarator context
    void addDecCtx(); // add new element to decCtx vector
    void purgeDecCtx(); // remove last element from decCtx vector.
    moduleContext& getCurrentModule();
    void addModule(std::string name, std::vector<std::string> inputs);


};

// static compilerContext comCtx;


 //------------------------------------------------------------------------------------------------------------//

struct lexContext{
    std::vector<std::vector<std::string> > type_defs = {{}};
    int scopeLevel = 0;
    std::string temp_typedef;
    bool declaration = false;

    void incScope();
    void decScope();
};

struct pyContext{
    int scopeLevel = 0;
    std::vector<std::string> pythonBindings;

    void incScope();
    void decScope();
};

static lexContext ctx;


#endif