# SystemNaim-FYP
The objective of SystemNaim is to create a HLS tool with in-built support for multi-fpga systems.

## Inputs and Outputs

The tool takes in a single C90(subset) source file and outputs a set of pure verilog files with the same functionality and which are able to then be overlayed onto an FPGA.

Work still needs to be done to get those files working on a Quartus device however at some point a step-by-step guide will be included to guide one through the process

# C-compiler Subset

### Here is a list of all the intended features:

* [ ] files containing multiple functions that call each other
* [ ] variables of `int` type
* [ ] arithmetic and logical expressions
* [ ] if-then-else statements
* [ ] while loops
* [ ] for loops
* [ ] arrays declared locally (i.e. inside a function)
* [ ] reading and writing elements of an array
* [ ] `switch` statements
* [ ] the `break` and `continue` keywords