// MUX 4x1 + Signal | Case statement

`timescale 1ns / 1ps

module mux_4x1_case(
    input D0,
    input D1,
    input D2,
    input [1:0] sel, // S0 Y S1
    output Y
    );
    reg temp;
    
    always@(*)begin
     case(sel)
            2'b00: temp = D0;  
            2'b01: temp = D1;
            2'b10: temp = D2;
            2'b11: temp = 2'bxxx;
     endcase  
    end

    
    assign Y = temp;
    
endmodule
