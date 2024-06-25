`timescale 1ns / 1ps

module circuito1(
    input A,
    input B,
    input C,
    input D,
    output S
    );
    
    assign S = (~A & ~B & C) | (~(A | B | ~C)) | ((~A & ~C & C) & (D));
endmodule
