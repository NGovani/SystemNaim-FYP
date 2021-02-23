#include "context.hpp"

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

// addState: generates a unique label using the stateName and creates an entry
//           in the states vector
std::string moduleContext::addState(const std::string& stateName, const stateContainer& stateData){
    std::string uniqueName = stateName + std::to_string(stateCount++);
    this->states.push_back(stateInfo(uniqueName, stateData));
    return uniqueName;
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
    r += ("(input clk,\ninput start,\ninput resetn,\noutput reg done\n);\n\n"); //module inputs and outputs

    //print standard variables
    r += ("reg [15:0] state, state_next;\n\n");
    //print program variables;
    for(auto const& [name, data] : this->variables){ // Might wanna also add var_next to be more safe
        r += ("reg [31:0] " + name + ";\n"); //TODO change to include arrays
    }
    
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

//---------------------------------------------//
//---------------- System Context -------------//
//---------------------------------------------//


declaratorContext& systemContext::getDecCtx(){
    return decCtx.back();
}
void systemContext::addDecCtx(){
    decCtx.push_back(declaratorContext());
}
void systemContext::purgeDecCtx(){
    decCtx.pop_back();
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