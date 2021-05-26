

testcase: 
	mkdir -p out
	../bin/c_to_v_compiler test.c
	verilator -Wall -cc -sv out/hls_test_func.sv -y out
	verilator -Wall -cc -sv out/hls_test_top.sv -y out --exe --build tb.cpp
	@echo "===========Compilation Complete============"
	@echo "==============Running Test================="
	@obj_dir/Vhls_test_top

clean:
	@rm -rf obj_dir
	@rm -rf out/*