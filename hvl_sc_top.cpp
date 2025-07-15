/*
    Created by Bill.Zhang
    in 2025;
*/



#include "hvl_sc_top.h"





void hvl_sc_top::my_dynamic_process()
{
    printf("#\thello my_process.\n");
    //svSetScope(svGetScopeFromName("hdl_top"));
    //debug_task();
}

int hvl_sc_top::sc_task()
{
    std::string timeStr = sc_time_stamp().to_string();

    //svSetScope(svGetScopeFromName("hdl_top"));
    //debug_task();

    sc_core::wait(20, SC_NS);

    printf("#\t%s debug from sc_task(). \n", timeStr.c_str());

    sc_core::wait(40, SC_NS);

    timeStr = sc_time_stamp().to_string();

    printf("#\t%s debug from sc_task(). \n", timeStr.c_str());

   return 0;
}

void hvl_sc_top::call_verilog_task()
{ 
    //svSetScope(svGetScopeFromName("hdl_top"));
    //debug_task();

    for(int i = 0; i < 3; ++i)
    {
        //verilog_task();
    }
}
