`timescale 1ns / 1ps

module main(
    input clk,
    input rst,
    input ld,
    input [3:0] ldvalue,
    output [3:0] dout
    );
    reg[3:0] temp = 0;
    
    always@(posedge clk)
    begin
        $display("Cont temp %b", temp);
        if (rst == 1'b1) temp = 0;
        else begin
            if(ld == 1'b1)
                temp = ldvalue;
            else
                temp = temp + 1;
        end
    end
    assign dout = temp;
endmodule
