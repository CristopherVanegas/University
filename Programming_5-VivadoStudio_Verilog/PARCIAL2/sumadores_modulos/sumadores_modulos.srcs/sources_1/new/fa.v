`timescale 1ns / 1ps

module fa(
    input A,
    input B,
    input Cin,
    output S,
    output Cout
    );
    
    wire t1, t2, t3;
    // Mapeo Implicito //
    ha ha1(A, B, t1, t2);
    
    // Mapeo Implicito //
    ha ha2(t2, Cin, t3, S);
    
    or(Cout, t1, t3);
endmodule
