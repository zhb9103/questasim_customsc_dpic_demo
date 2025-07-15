
#ifndef __HVL_SC_TOP_H__
#define __HVL_SC_TOP_H__


#define SC_INCLUDE_DYNAMIC_PROCESSES
#include "systemc.h"
#include "sc_dpiheader.h"
#include "svdpi.h"
#include <string>
#include <tlm.h>



class TestFunction
{
public:
    void DynamicThread(int para1, int para2)
    {
        printf("#\tpara1:%d, para2:%d\n",para1,para2);
        svSetScope(svGetScopeFromName("hdl_top"));
        //debug_task();
    }
};

class MyProcess
{
public:
    void DynamicProcess()
    {
        //svSetScope(svGetScopeFromName("hdl_top"));
        //debug_task();
    }
};

//SC_MODULE(hvl_sc_top)
// replace with below:
class hvl_sc_top: public sc_module
{
    void call_verilog_task();
    int sc_task();

    void my_dynamic_process();

public:
    //SC_CTOR(hvl_sc_top) 
    // replace with below:
    SC_HAS_PROCESS(hvl_sc_top);
    hvl_sc_top(sc_module_name module_name):sc_module(module_name)
    {
        SC_THREAD(call_verilog_task);
        SC_THREAD(MainThread);
    
        sc_core::sc_spawn(sc_bind(&TestFunction::DynamicThread,&m_Function,1,2),0,0);
        sc_core::sc_spawn(sc_bind(&MyProcess::DynamicProcess,&m_Process),0,0);
    
        //SC_DPI_REGISTER_CPP_MEMBER_FUNCTION("sc_task", &hvl_sc_top::sc_task);
    }
    

    ~hvl_sc_top() {};

    void MainThread()
    {
        printf("#\tmain thread start.\n");
        wait(2,SC_NS);
        sc_spawn_options t_opts;
        t_opts.spawn_method();
        //t_opts.set_sensitivity()
        //t_opts.dont_initialize();
        // sc_process_handle my_proc_handle=sc_spawn(sc_bind(&hvl_sc_top::my_dynamic_process,this),sc_gen_unique_name("my_dynamic_process"),&t_opts);
        sc_process_handle my_proc_handle=sc_spawn(sc_bind(&hvl_sc_top::my_dynamic_process,this),sc_gen_unique_name("my_dynamic_process"),0);
        wait(3,SC_NS);
        //my_proc_handle.disable();
    }

    TestFunction m_Function;
    MyProcess m_Process;
};




//SC_MODULE_EXPORT(hvl_sc_top);


#endif