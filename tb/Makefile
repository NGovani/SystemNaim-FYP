

testcase: 
	mkdir -p out
	../bin/c_to_v_compiler test.c
	verilator -Wall -cc out/func.v -y out --exe --build tb.cpp
	@echo "===========Compilation Complete============"
	@echo "==============Running Test================="
	@obj_dir/Vfunc

clean:
	@rm -rf obj_dir
	@rm -rf out/*