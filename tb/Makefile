

testcase: 
	mkdir -p out
	../bin/c_to_v_compiler test.sn
	verilator -Wall -Wno-WIDTH -cc -sv out/hls_test_func_a.sv -y out 
	verilator -Wall -Wno-WIDTH -cc -sv out/hls_test_func_b.sv -y out
	verilator -Wall -Wno-WIDTH -cc -sv out/hls_test_top.sv -y out --exe --build tb.cpp
	@echo "===========Compilation Complete============"
	@echo "==============Running Test================="
	@obj_dir/Vhls_test_top

clean:
	@rm -rf obj_dir
	@rm -rf out/*