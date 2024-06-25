`timescale 1ns / 1ps

module circuito1(
    input A,
    input B,
    input C,
    output S
    );
    
    assign S = (A & B) || ((B || C) & (C & B));
endmodule
