
# GPP = /opt/simulation/questasim/questasim/gcc-7.4.0-linux/bin/g++
# GPP = /opt/simulation/questasim/questasim/gcc-7.4.0-linux_x86_64/bin/g++
GPP = g++
all: clean comp sim

SYSTEMC_HOME=/opt/simulation/systemc-2.3.2

CXXFLAGS=-Wno-deprecated -DVCSYSTEMC=1 -fPIC -shared -Wall -g -I. -I$(SYSTEMC_HOME)/include 
#CXXFLAGS=-Wno-deprecated -DVCSYSTEMC=1 -fPIC -Wall -g -I. -I$(SYSTEMC_HOME)/include
LDFLAGS=-L$(SYSTEMC_HOME)/lib-linux64 -lsystemc -lpthread

comp:
	# create library
	#vdel -all
	vlib work
	#compile SystemVerilog source file
	vlog +acc -work work -f filelist.fl
	# compile and link C source files
	# sccom -g -DMTI_BIND_SC_MEMBER_FUNCTION main.cpp hvl_sc_top.cpp
	$(GPP) $(CXXFLAGS) -I/opt/simulation/questasim/questasim/include  main.cpp hvl_sc_top.cpp -o libhvl_sc_top.so $(LDFLAGS)
	# $(GPP) $(CXXFLAGS) -I/opt/simulation/questasim/questasim/include -c  main.cpp hvl_sc_top.cpp $(LDFLAGS)
	# ar r hvl_sc_top.a main.o hvl_sc_top.o
	# sccom -g main.cpp hvl_sc_top.cpp
	# sccom hvl_sc_top.a -link 

sim:
	# start and run simulation
	vsim hdl_top hvl_sc_top -gblso "libhvl_sc_top.so" -do run.do -c

clean:
	rm -rf *.ref work transcript .*.swp *.o *.a *.so || TRUE

