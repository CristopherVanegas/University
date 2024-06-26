`timescale 1ns / 1ps

module main(
    input A,
    input B,
    input C,
    output S
    );
    
    assign S = (~A | B) & (A | B | C) & ~C;
endmodule
