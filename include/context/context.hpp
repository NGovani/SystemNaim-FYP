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

struct DeclaratorContext{
    std::string id;
    bool initliased = false;
    //int destReg; //should be an enum.
    int size; //declaration specifier determines this
    int elements = 1; // usually for arrays, set to 1 by default for normal declaration
    int offset;
    bool isArray = false;
    bool isPointer = false;
    int initOffset = 0;

    int totSize();
    void purge(); //used when current declaration is done.
    void nextElement();
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
    std::map<std::string, varData> globalVars;
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
public:
    moduleContext(std::string _moduleName): stateCount(0), moduleName(_moduleName) {}
    std::string addState(const std::string& stateName, const stateContainer& stateData); //generates a state name and adds it the state list
    void addVariable(const std::string& varName);
    void addVariable(const std::string& varName, int elements); //used for arrays
    std::string printVerilog();
};

// systemContext :  contains all modules which are to be created. Allows access to 
class systemContext {
private:
    std::map<std::string, moduleContext> modules; // Map where key = module name: val = module context

public:
    moduleContext* getCurrentModule();


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