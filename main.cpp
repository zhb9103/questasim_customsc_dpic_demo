/*
    Created by Bill.Zhang
    in 2025;
*/



#define SC_INCLUDE_DYNAMIC_PROCESSES
#include "systemc.h"
#include "sc_dpiheader.h"
#include <string>
#include "svdpi.h"
//#include <tlm.h>
#include "hvl_sc_top.h"

#ifdef MTI_SYSTEMC

SC_MODULE_EXPORT(hvl_sc_top);

#else


int sc_main(int argc, char *argv[]) {

    //instantiate user TB in this wrapper
    hvl_sc_top hvl_sc_top_test("hvl_sc_top_test"); 

    sc_start();
    return 0;

}


#endif


