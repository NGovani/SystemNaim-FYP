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
    int offset;
    int elements = 1;
    int size; //used mainly for arrays but we can initlialise it for normal integers, to be used with the SizeOf command

    bool isTypdef = false;
    int type; //points to the declaration specifiers the typedef contains
    bool isEnum = false;
    int enumVal;

    bool global = true;
    bool isPointer = false;
    varData(){}
    varData(bool _typedef, int _type);
    varData(int _enumVal, bool _isEnum, bool _global): isEnum(_isEnum), enumVal(_enumVal), global(_global){}
    varData(int _offset, int _elements, int _size, bool _global, bool _pointer); //let declarator increment $sp
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


struct compilerContext{
    
    std::vector<funcScope> functions;


    int labelGen = 0;
    std::string generateUniqueLabel();
    std::string generateLabel(std::string s);

    std::map<std::string, varData>* currentBindings();
    DeclaratorContext tempDeclarator; //can be used by declarators to keep track of info needed to add to bindings.
    
};


// ILContext :  Interface for all context methods. Adding states, new function
// class IntermediateContext {
// private:
//     std::vector<functionCtx> functions; // seperate context for each function
// public:
// };

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