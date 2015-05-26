`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: Avnet
// Engineer: JLB
// 
// Create Date: 09/10/2012 03:32:02 PM
// Design Name: 
// Module Name: PWM_Controller
// Project Name: PWM Controller
// Target Devices: Any Xilinx FPGA
// Tool Versions: Created in PlanAhead 14.2
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////


module PWM_Controller(
    input Clk,
    input [31:0] DutyCycle,
    output [7:0] PWM_out
    );
    
    // Sets PWM Period.  Must be calculated vs. input clk period.
    // For example, setting this to 20 will divide the input clock by 2^20, or 1 Million.
    // So a 50 MHz input clock will be divided by 1e6, thus this will have a period of 1/50
    parameter period = 20;  
    
    reg [period-1:0] count;  
    reg [7:0] PWM_out;
    
    always @(posedge Clk)
       count <= count + 1; 
    
     always @(Clk)
       if (count < DutyCycle)
           PWM_out <= 8'hFF;
       else
           PWM_out <= 8'h00; 
        
endmodule
