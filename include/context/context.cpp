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
//--------------remoteModuleInfo------------------//
//---------------------------------------------//                               

remoteModuleInfo::remoteModuleInfo(){}
remoteModuleInfo::remoteModuleInfo(std::string _moduleIdentifier, std::string _startSignal,
                  std::string _doneSignal, std::string _outDataWire,
                  std::string _selectWire, std::string _dataaWire,
                  std::string _databWire, std::string _returnDataWire,
                  std::string _returnDataValidWire,
                  std::map<std::string, std::string> _inputReg, 
                  std::vector<std::string> _inputList,
                  int _opcode): moduleIdentifier(_moduleIdentifier), startSignal(_startSignal),
                               doneSignal(_doneSignal), outDataWire(_outDataWire),             
                               selectWire(_selectWire), dataaWire(_dataaWire), 
                               databWire(_databWire), returnDataWire(_returnDataWire),
                               returnDataValidWire(_returnDataValidWire), opcode(_opcode),
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

remoteModuleInfo& moduleContext::getRemoteModuleInfo(std::string moduleName){
    return this->remoteModules[moduleName];
}

std::string moduleContext::printVerilog(){
    std::string r = "";
    r += ("module " + this->moduleName + " "); // add initial module name and preamble
    r += ("(input clk,\ninput clk_en,\ninput start,\ninput reset,");
    for(auto const& name : this->inputs){ // Might wanna also add var_next to be more safe
        r += ("\ninput [31:0] " + name + ","); //TODO change to include arrays
    }
    r += "\noutput reg done,\noutput reg [31:0] d_out";
    if(!this->remoteModules.empty()){
        r += ",\n"
        "output [7:0] opcode_out,\n"
        "output [31:0] dataa_out,\n"
        "output [31:0] datab_out,\n"
        "output start_out,\n"
        "input data_from_remote,\n"
        "input data_from_remote_valid\n";
    }

    r += ");\n\n"; //module inputs and outputs

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

    for(auto const& [name, info] : this->remoteModules ){
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
        ".d_out(" + info.outDataWire + "),\n"
        ".select_out(" + info.selectWire + "),\n"
        ".dataa_out(" + info.dataaWire + "),\n"
        ".datab_out(" + info.databWire + "),\n"
        ".data_from_remote(" + info.returnDataWire + "),\n"
        ".data_from_remote_valid(" + info.returnDataValidWire + "),\n"
        ");\n\n";

    }

    if(!this->remoteModules.empty()){
        r += "sysNaim_master_mux mux0(\n"
        "\t.clk(clk),\n"
        "\t.start_out(start_out),\n"
        "\t.opcode_out(opcode_out),\n"
        "\t.dataa_out(dataa_out),\n"
        "\t.datab_out(datab_out),\n"
        "\t.data_from_remote(data_from_remote),\n"
        "\t.data_from_remote_valid(data_from_remote_valid)";
        
        for(auto& [name, info] : this->remoteModules){
            std::string op = std::to_string(info.opcode);
            r += ",\n" //add new line from prev input
            "\t.select_in" + op + "(" + info.selectWire + "),\n"
            "\t.dataa_in" + op + "(" + info.dataaWire + "),\n"
            "\t.datab_in" + op + "(" + info.databWire + "),\n"
            "\t.data_from_remote_in" + op + "(" + info.returnDataWire + "),\n"
            "\t.data_from_remote_valid_in" + op + "(" + info.returnDataValidWire + ")";
        }

        r += ");\n";
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

std::string moduleContext::printRemoteVerilog(){

    std::string r = "";
    r += ("module " + this->moduleName + "_remote "); // add initial module name and preamble
    r += ("(input clk,\ninput clk_en,\ninput start,\ninput reset,");
    for(auto const& name : this->inputs){ // Might wanna also add var_next to be more safe
        r += ("\ninput [31:0] " + name + ","); //TODO change to include arrays
    }
    r += "\noutput reg done,\n"
    "output reg [31:0] d_out\n"
    "output reg select_out\n"
    "output reg [31:0] dataa_out\n"
    "output reg [31:0] datab_out\n"
    "input data_from_remote\n"
    "input data_from_remote_valid"
    ");\n\n"; //module inputs and outputs

    // params
    r += "parameter S_IDLE = 2'd0, S_WAIT = 2'd1;\n";

    //next states
    r += "reg [2:0] state, state_next;\n"
    "reg [31:0] d_out_next;\n"
    "reg done_next;\n"
    "reg select_out_next;\n"
    "reg [31:0] dataa_out_next, datab_out_next;\n";

    r+= "\n\n";

    
    // always @ logic: update registarts
    r += "\nalways_ff @ (posedge clk or posedge reset) begin\n"
    "if(reset)\n"
    "\tstate <= S_IDLE;\n"
    "else if (!clk_en)\n"
    "\tstate <= S_IDLE;\n"
    "else begin\n";
    r += "d_out <= d_out_next;\n"
    "done <= done_next;\n"
    "state <= state_next;\n"
    "select_out <= select_out_next;\n"
    "dataa_out <= dataa_out_next;\n"
    "datab_out <= datab_out_next;\n"
    ;

    r += "end\n"
    "end\n\n";


    // in-state logic
    r += "always_comb begin\n";
    r += "d_out_next = d_out;\n"
    "done_next = 1'b0;\n"
    "state_next = S_IDLE;\n"
    "select_out_next = 1'b0;\n"
    "dataa_out_next = dataa_out;\n"
    "datab_out_next = datab_out;\n"
    ;

    r += "case (state)\n"
    "S_IDLE: begin\n"
    "\tstate_next = start ? S_WAIT : S_IDLE;\n"
    "\tselect_out_next = start;\n";

    std::string dataa_val = this->inputs.size() > 0 ? (" start ? " + this->inputs[0] + " : 32'd0;" ) : "32'd0"; 
    std::string datab_val = this->inputs.size() > 1 ? (" start ? " + this->inputs[1] + " : 32'd0;" ) : "32'd0"; 
    
    r += "\tdataa_out_next = " + dataa_val + "\n";
    r += "\tdatab_out_next = " + datab_val + "\n";
    r += "end\n"
    "S_WAIT: begin\n"
    "\tstate_next = data_from_remote_valid ? S_IDLE : S_WAIT;\n"
    "\tdone_next = data_from_remote_valid;\n"
    "\td_out_next = data_from_remote_valid ? data_from_remote : 32'd0;\n";    
    r += "default: ;\n";

    r += "endcase\nend\n\nendmodule\n";
    return r;
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

int systemContext::getOpcode(){
    return opcode_count++;
}

void systemContext::addRemoteModule(std::string funcName, int opcode){
    this->remoteModules[funcName] = opcode;
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
        
        subModuleInfo s = subModuleInfo(subModuleVars[0], subModuleVars[1],subModuleVars[2],
         subModuleVars[3], inputMap, inputs);
        this->getCurrentModule().getSubModuleInfo(funcName) = s; //adds submodule to submodule list
        // add vars to module context
        this->getCurrentModule().addVariable(s.startSignal, 1);
        for(auto const& [in,reg]: s.inputReg){
            this->getCurrentModule().addVariable(reg, 32);
        }
        return s;
    }
}

std::string systemContext::printRemoteTopVerilog(){
    std::string r = "";
    r += ("module sysNaim_remote_top"); // add initial module name and preamble
    r += ("(input clk,\ninput clk_en,\ninput start,\ninput reset,");
    r += "\noutput done,\n"
    "output [31:0] result,\n"
    "output avalon_clk,\n"
    "input avalon_rst,\n"
	"output [31:0] w_data,\n"
	"output [2:0]  addr,\n"
	"output	 	  w_en,\n"
	"output		  r_en,\n"
	"output 		  chipselect,\n"
	"input  [31:0] r_data,\n"
	"output reg avalon_spi_reset\n"
    ");\n\n"; //module inputs and outputs

    //signals between decoder and spi handler
    r += "wire ready;\n"
    "wire valid;\n"
    "wire start_return;\n"
    "wire [31:0] data;\n"
    "wire [31:0] return_data;\n"
    "wire [31:0] dataa;\n"
    "wire [31:0] datab;\n"
    "wire return_valid;\n\n";


    //signals between decoder and mux
    r +=   "wire [31:0] dataa;\n"
    "wire [31:0] datab;\n"
    "wire [7:0] opcode;\n"
    "wire data_to_hls_valid;\n"
    "wire [31:0] data_from_hls;\n"
    "wire data_from_hls_valid;\n";

    r += "assign done = data_from_hls_valid;\n"
    "assign result = data_from_hls;\n";

    for(auto& [name, opcode] : this->remoteModules){
        r += "wire [31:0] start" + std::to_string(opcode) + ";\n"
        "wire [31:0] dataa" + std::to_string(opcode) + ";\n"
        "wire [7:0] datab" + std::to_string(opcode) + ";\n"
        "wire data_from_remote" + std::to_string(opcode) + ";\n"
        "wire [31:0] data_from_remote_valid" + std::to_string(opcode) + ";\n";
    }



    r += "spi_slave_handler s0("
	"\t.clk(clk),\n"
	"\t.reset(reset),\n"
	"\t// custom interface\n"
	"\t.ready(ready),\n"
	"\t.valid(valid),\n"
	"\t.data(data),\n"
	"\t.start_return(start_return),\n"
	"\t.return_data(return_data),\n"
	"\t.return_valid(return_valid),\n"
	"\t//Avalon-MM ports\n"
	"\t.avalon_clk(avalon_clk),\n"
	"\t.addr(addr),\n"
	"\t.w_data(w_data),\n"
	"\t.r_data(r_data),\n"
	"\t.w_en(w_en),\n"
	"\t.r_en(r_en),\n"
	"\t.chipselect(chipselect),\n"
	"\t.process_done()\n"
    ");\n";

    r += "instr_decoder i0(\n"
	"\t.clk(clk),\n"
	"\t.reset(reset),\n"
	"\t.start(start),\n"
	"\t// custom interface\n"
	"\t.ready(ready),\n"
	"\t.valid(valid),\n"
	"\t.data(data),\n"
	"\t.start_return(start_return),\n"
	"\t.return_data(return_data),\n"
	"\t.return_valid(return_valid),\n"
	"\t//HLS program interface\n"
	"\t.opcode(opcode),\n"
	"\t.dataa(dataa),\n"
	"\t.datab(datab),\n"
	"\t.data_to_hls_valid(data_to_hls_valid),\n"
	"\t.data_from_hls(data_from_hls),\n"
	"\t.data_from_hls_valid(data_from_hls_valid)\n"
	");";

    r += "sysNaim_slave_mux mux0(\n"
	"\t.clk(clk),\n"
    "\t.start_in(data_to_hls_valid),\n"
    "\t.opcode_in(opcode),\n"
    "\t.dataa_in(dataa),\n"
    "\t.datab_in(datab),\n"
    "\t.data_to_host(data_from_hls),\n"
    "\t.data_to_host_valid(data_from_hls_valid)";

    for(int i = 1; i <= this->remoteModules.size(); i++ ){
        std::string op = std::to_string(i);
        r += ",\n" //add new line from prev input
        "\t.start_out" + op +"(start" + op + "),\n"
        "\t.dataa_out" + op +"(dataa" + op + "),\n"
        "\t.datab_out" + op +"(datab" + op + "),\n"
        "\t.data_from_remote" + op +"(data_from_remote" + op + "),\n"
        "\t.data_from_remote_valid" + op +"(data_from_remote_valid" + op + ")";
    }

    r+= ");\n\n";

    for(auto& [name, opcode] : this->remoteModules){
        std::string op = std::to_string(opcode);
        moduleContext m = this->findModule(name);
        r += m.getName() + " m" + op+"(\n"
        "\t.clk(clk),\n"
        "\t.clk_en(clk_en),\n"
        "\t.reset(reset),\n"
        "\t.start(start" + op + "),\n"
        "\t.done(data_from_remote_valid" + op + "),\n"
        "\t.d_out(data_from_remote" + op + ")";
        for(int i = 0; i < m.getInputs().size(); i++){
            std::string wire = i == 0 ? "dataa" + op : "datab" + op;
            r += ",\n"
            "\t." + m.getInputs()[i] + "(" + wire + ")";
        }
        r+= ");\n\n";
    }
    
    // always @ logic: update registarts
    r += "\nalways_ff @ (posedge clk or posedge reset) begin\n"
    "if(reset)\n"
    "\tavalon_spi_reset <= 1'b1;\n"
    "else if (!clk_en)\n"
    "\tavalon_spi_reset <= 1'b1;\n"
    "else\n"
    "\tavalon_spi_reset <= 1'b0;\n"
    "end\n\n";

    r += "endmodule\n";
    return r;
}

std::string systemContext::printHostTopVerilog(){
        std::string r = "";
    r += ("module sysNaim_host_top"); // add initial module name and preamble
    r += ("(input clk,\ninput clk_en,\ninput start,\ninput reset,");
    r += "\noutput done,\n"
    "output [31:0] result,\n"
    "output avalon_clk,\n"
    "input avalon_rst,\n"
	"output [31:0] w_data,\n"
	"output [2:0]  addr,\n"
	"output	 	  w_en,\n"
	"output		  r_en,\n"
	"output 	  chipselect,\n"
	"input  [31:0] r_data,\n"
	"output reg avalon_spi_reset\n"
    ");\n\n"; //module inputs and outputs


    //signals between decoder and spi handler
    r += "wire ready;\n"
    "wire valid;\n"
    "wire start_return;\n"
    "wire [31:0] data;\n"
    "wire [31:0] return_data;\n"
    "wire return_valid;\n\n";


    //signals between decoder and mux
    r +=   "wire [31:0] dataa_out;\n"
    "wire [31:0] datab_out;\n"
    "wire [31:0] start_out;\n"
    "wire [7:0] opcode;\n"
    "wire [31:0] data_to_hls;\n"
    "wire data_to_hls_valid;\n";

    r += "assign done = data_from_hls_valid;\n"
    "assign result = data_from_hls;\n";

    r += "spi_handler s0("
	"\t.clk(clk),\n"
	"\t.reset(reset),\n"
	"\t// custom interface\n"
	"\t.ready(ready),\n"
	"\t.valid(valid),\n"
	"\t.data(data),\n"
	"\t.start_return(start_return),\n"
	"\t.return_data(return_data),\n"
	"\t.return_valid(return_valid),\n"
	"\t//Avalon-MM ports\n"
	"\t.avalon_clk(avalon_clk),\n"
	"\t.addr(addr),\n"
	"\t.w_data(w_data),\n"
	"\t.r_data(r_data),\n"
	"\t.w_en(w_en),\n"
	"\t.r_en(r_en),\n"
	"\t.chipselect(chipselect),\n"
    ");\n";

    r += "instr_encoder i0(\n"
	"\t.clk(clk),\n"
	"\t.reset(reset),\n"
	"\t// custom interface\n"
	"\t.ready(ready),\n"
	"\t.valid(valid),\n"
	"\t.data(data),\n"
	"\t.start_return(start_return),\n"
	"\t.return_data(return_data),\n"
	"\t.return_valid(return_valid),\n"
	"\t//HLS program interface\n"
	"\t.opcode(opcode),\n"
	"\t.dataa(dataa_out),\n"
	"\t.datab(datab_out),\n"
	"\t.start(start_out),\n"
	"\t.data_to_hls(data_to_hls),\n"
	"\t.data_to_hls_valid(data_to_hls_valid)\n"
	"\t.hex_out()\n"
    
	");";


    moduleContext topMdl = this->modules.back();

    r += topMdl.getName() + " m0(\n"
    "\t.clk(clk),\n"
    "\t.clk_en(clk_en),\n"
    "\t.reset(reset),\n"
    "\t.start(start),\n"
    "\t.done(done),\n"
    "\t.d_out(result)";
    for(int i = 0; i < topMdl.getInputs().size(); i++){
        std::string wire = i == 0 ? "dataa" : "datab";
        r += ",\n"
        "\t." + topMdl.getInputs()[i] + "(" + wire + ")";
    }  

    r += ",\n"
    "\t.opcode_output(opcode),\n"
    "\t.dataa_out(dataa_out),\n"
    "\t.datab_out(datab_out),\n"
    "\t.start_out(start_out),\n"
    "\t.data_from_remote(data_to_hls),\n"
    "\t.data_from_remote_valid(data_to_hls_valid)\n";


    r += ");\n";  

    for(auto& [name, opcode] : this->remoteModules){
       
    }
    
    // always @ logic: update registarts
    r += "\nalways_ff @ (posedge clk or posedge reset) begin\n"
    "if(reset)\n"
    "\tavalon_spi_reset <= 1'b1;"
    "else if (!clk_en)\n"
    "\tavalon_spi_reset <= 1'b1;"
    "else\n"
    "\tavalon_spi_reset <= 1'b0;"
    "end\n\n";

    r += "endmodule\n";
    return r;
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
    if(!this->remoteModules.empty()){
        for(auto& [mdl, op] : this->remoteModules){
            moduleContext remMdl = this->findModule(mdl);
            std::string remModuleFile = "out/" + remMdl.getName() + "_remote.sv";
            outFile.open(remModuleFile);
            outFile << remMdl.printRemoteVerilog() << std::endl;
            outFile.close();
        }
        std::string remTopFile = "out/sysNaim_remote_top.sv"; 
        outFile.open(remTopFile);
        outFile << this->printRemoteTopVerilog() << std::endl;
        outFile.close();
        std::string hostTopFile = "out/sysNaim_host_top.sv";
        outFile.open(hostTopFile);
        outFile << this->printHostTopVerilog() << std::endl;
        outFile.close();
    }
}


