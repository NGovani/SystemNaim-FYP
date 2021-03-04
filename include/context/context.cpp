#include "context.hpp"
#include "functional.hpp"

//---------------------------------------------//
//--------------Lexer_Context------------------//
//---------------------------------------------//


void lexContext::incScope(){
        type_defs.push_back(type_defs[scopeLevel]);
        scopeLevel++;
    }

void lexContext::decScope(){
        type_defs.pop_back();
        scopeLevel--;
    }

//---------------------------------------------//
//--------------Python_Context-----------------//
//---------------------------------------------//

void pyContext::incScope(){
        scopeLevel++;
    }

void pyContext::decScope(){
        scopeLevel--;
    }



//---------------------------------------------//
//---------------- Module Context -------------//
//---------------------------------------------//

void moduleContext::handleTempState(const std::string& stateName, const stateContainer& stateData){
    bool tmpStatePresent = true;
    std::vector<std::string> statesToChange;
    while(tmpStatePresent){
        std::visit(functional::overload{
        [&](expressionStateInfo& st) {tmpStatePresent = false;},
        [&](functionStateInfo& st) {tmpStatePresent = false;},
        [&](branchStateInfo& st) {tmpStatePresent = false;},
        [&](conditionalStateInfo& st) {tmpStatePresent = false;},
        [&](temporaryStateInfo& st) {statesToChange.insert(statesToChange.end(), st.jumpToHere.begin(), st.jumpToHere.end());
                                    this->states.pop_back();
                                    }
        }, this->states.back().getState());
    }
    for(auto name : statesToChange){
        std::visit(functional::overload{
        [&](expressionStateInfo& st) {st.nxtState = stateName;},
        [&](functionStateInfo& st) {/*TODO*/},
        [&](branchStateInfo& st) {st.jumpLabel = stateName;},
        [&](conditionalStateInfo& st) {/*TODO*/},
        [&](temporaryStateInfo& st) {}
        }, this->findState(name).getState());
    }
    this->states.push_back(stateInfo(stateName, stateData));
}


// addState: generates a unique label using the stateName and creates an entry
//           in the states vector
std::string moduleContext::addState(const std::string& stateName, const stateContainer& stateData){
    std::string uniqueName = stateName + std::to_string(stateCount++);
    if(!this->states.empty()){
        std::visit(functional::overload{
            [&](temporaryStateInfo& st) {
                if(auto chk = std::get_if<temporaryStateInfo>(&stateData))
                    this->states.push_back(stateInfo(uniqueName, stateData));
                else
                    this->handleTempState(uniqueName, stateData);},
            [&](auto& st) {this->states.push_back(stateInfo(uniqueName, stateData));}
        }, this->states.back().getState());
    } else {
        this->states.push_back(stateInfo(uniqueName, stateData));
    }
    return uniqueName;
}

void moduleContext::addNamedState(const std::string& stateName, const stateContainer& stateData){
    if(!this->states.empty()){
        std::visit(functional::overload{
            [&](temporaryStateInfo& st) {
                if(auto chk = std::get_if<temporaryStateInfo>(&stateData))
                    //if the previous state is a tmp and so is this then just add this one to the list
                    this->states.push_back(stateInfo(stateName, stateData));
                else
                    this->handleTempState(stateName, stateData);},
            [&](auto& st) {this->states.push_back(stateInfo(stateName, stateData));}
        }, this->states.back().getState());
    } else {
        // if there are no states then just add it
        this->states.push_back(stateInfo(stateName, stateData));
    }
}

std::string moduleContext::genTmpVar(const std::string& varName){
    return varName + std::to_string(this->varCount++);
}

std::string moduleContext::genStateName(const std::string& stateName){
    return stateName + std::to_string(stateCount++);;
}

std::string moduleContext::lastStateName(){
    return this->states.back().getStateName();
}

stateInfo& moduleContext::findState(std::string stateName){
    return *(std::find(this->states.begin(), this->states.end(), stateName));
}

void moduleContext::addVariable(const std::string& varName){
    this->variables[varName] = varData();
}

void moduleContext::addVariable(const std::string& varName, int elements){
    this->variables[varName] = varData(elements);
}

std::string moduleContext::printVerilog(){
    std::string r = "";
    r += ("module " + this->moduleName + " "); // add initial module name and preamble
    r += ("(input clk,\ninput start,\ninput resetn,");
    for(auto const& name : this->inputs){ // Might wanna also add var_next to be more safe
        r += ("\ninput [31:0] " + name + ","); //TODO change to include arrays
    }
    r += ("\noutput reg done,\noutput reg [31:0] d_out\n);\n\n"); //module inputs and outputs

    //print standard variables
    r += ("reg [15:0] state, state_next;\n\n");
    //print program variables;
    for(auto const& [name, data] : this->variables){ // Might wanna also add var_next to be more safe
        r += ("reg [31:0] " + name + ";\n"); //TODO change to include arrays
    }
    r += "reg [31:0] d_out;\n"; //output reg for returns
    
    // always @ logic: update state
    r += "\nalways @ (posedge clk) begin\n"
    "if(!resetn)\n"
    "state <= 16'd0;\n"
    "else\n"
    "state <= state_next;\n"
    "end\n\n";
    // state logic
    r += "always @ (state) begin\n"
    "case (state)\n"
    "16'd0: begin\n"
    "if (start)\n"
    "state_next <= " + this->states[0].getStateName() + ";\n"
    "end\n";
    
    for(std::vector<stateInfo>::iterator it = this->states.begin(); it != this->states.end(); it++){
        if (it == (std::prev(this->states.end())))
            r+= it->printVerilog("16'd0");
        else{
            ;
            auto nx = std::next(it, 1);
            r+= it->printVerilog(nx->getStateName());
        }
    }

    r += "end\nendmodule\n";
    return r;
}

void moduleContext::modifyNextState(std::string stateName, std::string nextState){
    stateInfo& s = this->findState(stateName);
    std::visit(functional::overload{
        [&](expressionStateInfo& st) {st.nxtState = nextState;},
        [&](branchStateInfo& st) {st.nxtState = nextState;},
        [&](auto& st) {throw std::runtime_error("function. cond, and tmp state modify not implemented");}
    }, this->states.back().getState());

}


//---------------------------------------------//
//---------------- System Context -------------//
//---------------------------------------------//


declaratorContext& systemContext::getDecCtx(){
    if(decCtx.empty()) throw std::runtime_error("DecCtx Empty");
    return decCtx.back();
}
void systemContext::addDecCtx(){
    decCtx.push_back(declaratorContext());
}
void systemContext::purgeDecCtx(){
    decCtx.pop_back();
}

expressionStateInfo& systemContext::getExprState(){
    if(this->exprStates.empty()) throw std::runtime_error("exprStates Empty");
    return this->exprStates.back();
}

void systemContext::addExprState(expressionStateInfo e){
    this->exprStates.push_back(e);
}

void systemContext::purgeExprState(){
    this->exprStates.pop_back();
}

moduleContext& systemContext::getCurrentModule(){
    return modules.back();
}

void systemContext::addModule(std::string name, std::vector<std::string> inputs){
    if(inputs.empty())
        modules.push_back(moduleContext(name));
    else
        modules.push_back(moduleContext(name, inputs));
}