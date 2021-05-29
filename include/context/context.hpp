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
#include <fstream>
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
    bool isArray;
    int elements;
    int width;

    varData();
    varData(int _width);
    varData(int _width, int _elements);
};

struct subModuleInfo {
    std::string moduleIdentifier; // identifier within module
    std::string startSignal, doneSignal;
    std::string outDataWire; //name of wire for data out
    std::vector<std::string> inputList; // maintains order of the inputs, contains name of registers for each input
    std::map<std::string, std::string> inputReg; //key = input name, val = reg in this module connected to input

    subModuleInfo();
    subModuleInfo(std::string _moduleIdentifier, std::string _startSignal,
                  std::string _doneSignal, std::string _outDataWire, 
                  std::map<std::string, std::string> _inputReg, 
                  std::vector<std::string> _inputList);
};

struct remoteModuleInfo {
    std::string moduleIdentifier; // identifier within module
    std::string startSignal, doneSignal;
    std::string outDataWire; //name of wire for data out
    std::vector<std::string> inputList; // maintains order of the inputs, contains name of registers for each input
    std::map<std::string, std::string> inputReg; //key = input name, val = reg in this module connected to input
    
    // Variables below are used to connect module to mux
    int opcode;
    std::string selectWire;
    std::string dataaWire, databWire;
    std::string returnDataWire;
    std::string returnDataValidWire;


    remoteModuleInfo();
    remoteModuleInfo(std::string _moduleIdentifier, std::string _startSignal,
                  std::string _doneSignal, std::string _outDataWire, 
                  std::map<std::string, std::string> _inputReg, 
                  std::vector<std::string> _inputList);
};

struct splitFunctionStateInfo{
    std::map<std::string, functionCallStateInfo> callStateList;
    std::map<std::string, functionWaitStateInfo> waitStateList;
    std::map<std::string, std::string> doneRegList;
    std::map<std::string, expressionStateInfo> assignmentList;


    splitFunctionStateInfo();
};



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
    std::map<std::string, subModuleInfo> subModules;
    std::map<std::string, remoteModuleInfo> remoteModules;
public:
    moduleContext(std::string _moduleName): stateCount(0), varCount(0), moduleName(_moduleName) {}
    moduleContext(std::string _moduleName, std::vector<std::string> _inputs): stateCount(0), varCount(0), moduleName(_moduleName), inputs(_inputs) {}

    // adding states
    std::string addState(const std::string& stateName, const stateContainer& stateData); //generates a state name and adds it the state list, return index of state
    void addNamedState(const std::string& stateName, const stateContainer& stateData); // does not generate a state name, assume label has already been generated
    
    //variables
    void addVariable(const std::string& varName, int width);
    void addVariable(const std::string& varName, int width, int elements); //used for arrays
    
    // generators
    std::string genStateName(const std::string& stateName);
    std::string genTmpVar(const std::string& varName);
    void genListOfVars( std::vector<std::string>& varNames);

    // state manipulation
    stateInfo& findState(std::string stateName);
    std::string lastStateName();
    void modifyNextState(std::string stateName, std::string nextState);

    //submodule map
    bool findSubModule(std::string moduleName);
    subModuleInfo& getSubModuleInfo(std::string moduleName);

    // output
    std::string printVerilog();
    std::string printParams();
    std::string printRemoteVerilog();

    //inputs
    std::vector<std::string> getInputs(){return this->inputs;}

    //getters
    std::string getName(){return moduleName;}
    bool operator== (std::string _moduleName);
};

// systemContext :  contains all modules which are to be created, aswell as structs to hold data
//                  between nodes
class systemContext {
private:
    std::vector<moduleContext> modules; // holds all module data, including the states they have
    std::vector<declaratorContext> decCtx; // holds data for declarations
    std::vector<expressionStateInfo> exprStates; //used to create expression states across nodes.
    std::vector<functionCallStateInfo> funcStates; // holds data for current function call
    std::vector<splitFunctionStateInfo> splitFuncStates;
    std::map<std::string, int > remoteModules; //List of all remote modules to be turned into sv files
    int opcode_count = 1;
public:
    expressionStateInfo& getExprState();
    void addExprState(expressionStateInfo e);
    void purgeExprState();
    functionCallStateInfo& getFuncState();
    void addFuncState(functionCallStateInfo f);
    void purgeFuncState();
    splitFunctionStateInfo& getSplitFuncState();
    void addSplitFuncState(splitFunctionStateInfo s);
    void purgeSplitFuncState();
    declaratorContext& getDecCtx(); // get current declarator context
    void addDecCtx(); // add new element to decCtx vector
    void purgeDecCtx(); // remove last element from decCtx vector.
    moduleContext& getCurrentModule();
    moduleContext& findModule(std::string moduleName);
    void addModule(std::string name, std::vector<std::string> inputs);
    subModuleInfo findFuncCall(std::string funcName); //checks if a function has been called by the current module
    void printAllVerilog();

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