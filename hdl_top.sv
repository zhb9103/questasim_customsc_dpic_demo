/*
    Created by Bill.Zhang
    in 2025;
*/



module hdl_top;

import "DPI-SC" context task sc_task();
export "DPI-SC" task verilog_task;
export "DPI-SC" task debug_task;


reg clk;
reg rst;

task debug_task();
  $display("#%d debug_task.", $time);
endtask

task verilog_task();
  #10
  $display("#%d info from verilog_task.", $time);
  #20
  $display("#%d info from verilog_task.", $time);
endtask

initial
begin
  clk='b0;
  rst='b0;
  $display("#%d starting test.", $time);
  #100;
  rst='b1;
  sc_task();

  repeat (1000) begin
    #10 clk=~clk;
  end

  #2000 $finish;
end 
endmodule
