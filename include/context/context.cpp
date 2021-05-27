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
//--------------VarData------------------------//
//---------------------------------------------//
varData::varData(){}
varData::varData(int _width): width(_width), isArray(false), elements(1){} 
varData::varData(int _width, int _elements): width(_width), isArray(true), elements(_elements){}

//---------------------------------------------//
//--------------subModuleInfo------------------//
//---------------------------------------------//

subModuleInfo::subModuleInfo(){}
subModuleInfo::subModuleInfo(std::string _moduleIdentifier, std::string _startSignal, 
                             std::string _doneSignal, std::string _outDataWire, 
                             std::map<std::string, std::string> _inputReg,
                             std::vector<std::string> _inputList)
                             : moduleIdentifier(_moduleIdentifier), startSignal(_startSignal),
                               doneSignal(_doneSignal), outDataWire(_outDataWire),
                               inputReg(_inputReg), inputList(_inputList) {}


//---------------------------------------------//
//-------------splitFunctionState--------------//
//---------------------------------------------//

splitFunctionStateInfo::splitFunctionStateInfo(){}


//---------------------------------------------//
//---------------- Module Context -------------//
//---------------------------------------------//

void moduleContext::handleTempState(const std::string& stateName, const stateContainer& stateData){
    bool tmpStatePresent = true;
    std::vector<std::string> statesToChange;
    while(tmpStatePresent){
        std::visit(functional::overload{
        [&](expressionStateInfo& st) {tmpStatePresent = false;},
        [&](functionCallStateInfo& st) {tmpStatePresent = false;},
        [&](functionWaitStateInfo& st) {tmpStatePresent = false;},
        [&](splitFunctionCallStateInfo& st) {tmpStatePresent = false;},
        [&](splitFunctionWaitStateInfo& st) {tmpStatePresent = false;},
        [&](branchStateInfo& st) {tmpStatePresent = false;},
        [&](temporaryStateInfo& st) {statesToChange.insert(statesToChange.end(), st.jumpToHere.begin(), st.jumpToHere.end());
                                    this->states.pop_back();
                                    }
        }, this->states.back().getState());
    }
    for(auto name : statesToChange){
        std::visit(functional::overload{
        [&](expressionStateInfo& st) {st.nxtState = stateName;},
        [&](functionCallStateInfo& st) {/*TODO*/},
        [&](functionWaitStateInfo& st) {/*TODO*/},
        [&](splitFunctionCallStateInfo& st) {/*TODO*/},
        [&](splitFunctionWaitStateInfo& st) {/*TODO*/},
        [&](branchStateInfo& st) {st.jumpLabel = stateName;},
        [&](temporaryStateInfo& st) {}
        }, this->findState(name).getState());
    }
    this->states.push_back(stateInfo(stateName, stateData));
}


// addState: generates a unique label using the stateName and creates an entry
//           in the states vector
std::string moduleContext::addState(const std::string& stateName, const stateContainer& stateData){
    std::string uniqueName = stateName + std::to_string(stateCount++);
    if(!this->states.empty()){ // if there are states in the module, first consume all temporay states
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

void moduleContext::genListOfVars(std::vector<std::string>& varNames){
    for(auto& var : varNames){
        var += std::to_string(varCount);
    }
    varCount++;
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

void moduleContext::addVariable(const std::string& varName, int width){
    this->variables[varName] = varData(width);
}

void moduleContext::addVariable(const std::string& varName, int width, int elements){
    this->variables[varName] = varData(width, elements);
}

void moduleContext::modifyNextState(std::string stateName, std::string nextState){
    stateInfo& s = this->findState(stateName);
    std::visit(functional::overload{
        [&](expressionStateInfo& st) {st.nxtState = nextState;},
        [&](branchStateInfo& st) {st.nxtState = nextState;},
        [&](auto& st) {throw std::runtime_error("function. cond, and tmp state modify not implemented");}
    }, this->states.back().getState());

}

bool moduleContext::findSubModule(std::string moduleName){
    return this->subModules.count(moduleName);
}

subModuleInfo& moduleContext::getSubModuleInfo(std::string moduleName){
    return this->subModules[moduleName];
}

std::string moduleContext::printVerilog(){
    std::string r = "";
    r += ("module " + this->moduleName + " "); // add initial module name and preamble
    r += ("(input clk,\ninput clk_en,\ninput start,\ninput reset,");
    for(auto const& name : this->inputs){ // Might wanna also add var_next to be more safe
        r += ("\ninput [31:0] " + name + ","); //TODO change to include arrays
    }
    r += ("\noutput reg done,\noutput reg [31:0] d_out\n);\n\n"); //module inputs and outputs

    r += "`include \"" + this->moduleName + "_params.svh\"\n\n";

    //print standard variables
    r += ("reg [15:0] state;\n\n");

    //print program variables;
    for(auto const& [name, data] : this->variables){ // Might wanna also add var_next to be more safe
        std::string varWidth = data.width == 32 ? "[31:0] " : "" ;
        r += ("reg " + varWidth + name + ";\n");
    }
    for(auto const& [name, data] : this->variables){ // Might wanna also add var_next to be more safe
        std::string varWidth = data.width == 32 ? "[31:0] " : "" ;
        r += ("reg " + varWidth + name + "_next;\n"); 
    }
    r += "reg [31:0] d_out_next;\n"
    "reg done_next;\n";

    r+= "\n\n";
    
    //submodule instatiations
    for(auto const& [name, info] : this->subModules ){
        std::string subModuleInputs;
        for(auto const& [input, reg] : info.inputReg){
            subModuleInputs += "." + input + "(" + reg + "),\n";
        }

        //submodule variables
        r += "wire " + info.doneSignal + ";\n"
        "wire [31:0] " + info.outDataWire + ";\n";

        //connecting wires
        r += name + " " + info.moduleIdentifier +"(\n"
        ".clk(clk),\n"
        ".clk_en(clk_en),\n"
        ".reset(reset),\n" + 
        subModuleInputs +
        ".start(" + info.startSignal + "),\n"
        ".done(" + info.doneSignal + "),\n"
        ".d_out(" + info.outDataWire + "));\n\n";
    }

    
    // always @ logic: update state
    r += "\nalways_ff @ (posedge clk or posedge reset) begin\n"
    "if(reset)\n"
    "\tstate <= 16'd0;\n"
    "else if (!clk_en)\n"
    "\tstate <= 16'd0;\n"
    "else begin\n";
    for(auto const& [name, data] : this->variables){
        r += (name + " <= " + name + "_next;\n"); //TODO change to include arrays
    }
    r += "d_out <= d_out_next;\n"
    "done <= done_next;\n";
    r += "case (state)\n"
    "16'd0: state <= start ? " + this->states[0].getStateName() + " : 16'd0;\n";
    for(std::vector<stateInfo>::iterator it = this->states.begin(); it != this->states.end(); it++){
        if (it == (std::prev(this->states.end())))
            r+= it->printVerilogStateChange("16'd0");
        else{
            auto nx = std::next(it, 1);
            r+= it->printVerilogStateChange(nx->getStateName());
        }
    }
    r += "default: ;\n";
    r += "endcase\nend\n"
    "end\n\n";


    // in-state logic
    r += "always_comb begin\n";
    for(auto const& [name, data] : this->variables){
        r += (name + "_next = " + name + ";\n"); //TODO change to include arrays
    }
    r += "d_out_next = d_out;\n"
    "done_next = done;\n";

    r += "case (state)\n"
    "16'd0: begin\n"
    "\tdone_next = 0;\n"
    "\td_out_next = 0;\n"
    "end\n";

    
    for(std::vector<stateInfo>::iterator it = this->states.begin(); it != this->states.end(); it++){
        r+= it->printVerilogState();
    }
    r += "default: ;\n";

    r += "endcase\nend\n\nendmodule\n";
    return r;
}


std::string moduleContext::printParams(){
    int counter = 1;
    std::string out;
    for(auto& st : this->states){
        out += "parameter " + st.getStateName() + " = 16'd" + std::to_string(counter++) + ";\n";
    }
    return out;
}

bool moduleContext::operator== (std::string _moduleName){
    return this->moduleName == _moduleName;
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

functionCallStateInfo& systemContext::getFuncState(){
    if(this->funcStates.empty()) throw std::runtime_error("exprStates Empty");
    return this->funcStates.back();
}

void systemContext::addFuncState(functionCallStateInfo f){
    this->funcStates.push_back(f);
}

void systemContext::purgeFuncState(){
    this->funcStates.pop_back();
}

splitFunctionStateInfo& systemContext::getSplitFuncState(){
    if(this->splitFuncStates.empty()) throw std::runtime_error("splitFuncStates Empty");
    return this->splitFuncStates.back();
}

void systemContext::addSplitFuncState(splitFunctionStateInfo s){
    this->splitFuncStates.push_back(s);
}

void systemContext::purgeSplitFuncState(){
    this->splitFuncStates.pop_back();
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

moduleContext& systemContext::findModule(std::string moduleName){
    std::vector<moduleContext>::iterator m = std::find(this->modules.begin(), this->modules.end(), moduleName);
    if(m == this->modules.end()) throw std::runtime_error("Module not found: " + moduleName);
    return *(m);
}

subModuleInfo systemContext::findFuncCall(std::string funcName){
    
    if(this->getCurrentModule().findSubModule(funcName)){
        return this->getCurrentModule().getSubModuleInfo(funcName);
    } else {
        moduleContext& m = this->findModule(funcName);
        std::vector<std::string> inputs = m.getInputs();
        std::vector<std::string> subModuleVars {funcName, funcName +"_start", funcName +"_done", funcName +"_out"};
        subModuleVars.insert(subModuleVars.end(), inputs.begin(), inputs.end());
        this->getCurrentModule().genListOfVars(subModuleVars);
        std::map<std::string, std::string> inputMap;
        for(int i = 0; i < inputs.size(); i++){
            inputMap[inputs[i]] = subModuleVars[i + 4];
            //now inputs contains the generated reg name
            inputs[i] = subModuleVars[i + 4];
        }
        
        subModuleInfo s = subModuleInfo(subModuleVars[0], subModuleVars[1],subModuleVars[2], subModuleVars[3], inputMap, inputs);
        this->getCurrentModule().getSubModuleInfo(funcName) = s;
        // add vars to module context
        this->getCurrentModule().addVariable(s.startSignal, 1);
        for(auto const& [in,reg]: s.inputReg){
            this->getCurrentModule().addVariable(reg, 32);
        }
        return s;
    }
}

void systemContext::printAllVerilog(){
    std::ofstream outFile;
    for(auto& mdl : this->modules){
        std::string mainFile = "out/" + mdl.getName() + ".sv";
        std::string paramFile = "out/" + mdl.getName() + "_params.svh";
        outFile.open(mainFile);
        outFile << mdl.printVerilog() << std::endl;
        outFile.close();
        outFile.open(paramFile);
        outFile << mdl.printParams() << std::endl;
        outFile.close();
    }
}