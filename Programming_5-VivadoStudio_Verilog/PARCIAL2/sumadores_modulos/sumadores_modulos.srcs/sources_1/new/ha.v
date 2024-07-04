`timescale 1ns / 1ps

module ha(
    input A,
    input B,
    output C,
    output S
    );
    
    assign S = A ^ B;
    // xor(S, A, B);
    
    assign C = A & B;
    // and(C, A, B);
endmodule
