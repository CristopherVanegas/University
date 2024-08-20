`timescale 1ns / 1ps

module full_substractor(
    input wire A,  // Minuendo
    input wire B,  // Sustraendo
    input wire C,  // Borrow de la operaci�n anterior
    output wire D, // Resultado de la resta
    output wire Br // Borrow de la operaci�n actual
);

    wire xor_BC;
    
    // D = A ? (B ? C)
    assign xor_BC = B ^ C;
    assign D = A ^ xor_BC;

    // Br = (A ? ~(B ? C)) ? (~B ? C)
    assign Br = (A & ~xor_BC) | (~B & C);

endmodule
