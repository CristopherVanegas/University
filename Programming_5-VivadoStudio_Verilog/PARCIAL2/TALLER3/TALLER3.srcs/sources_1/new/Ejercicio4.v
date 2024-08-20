`timescale 1ns / 1ps

// Construya el circuito 4-bit Ripple-Carry Adder

module mux21 (
        input wire sel,   // Se�al de selecci�n
        input wire I0,    // Entrada 0
        input wire I1,    // Entrada 1
        output reg O      // Salida
    );
    
    always @(*) begin
        case (sel)
            1'b0: O = I0;
            1'b1: O = I1;
            default: O = 1'b0; // Valor por defecto para evitar latch
        endcase
    end
endmodule


module Ejercicio4(
        input wire s0,   // Se�al de selecci�n
        input wire I0,    // Entrada 0
        input wire I1,    // Entrada 1
        output reg O0      // Salida
        
        input wire s1,   // Se�al de selecci�n
        input wire I2,    // Entrada 0
        input wire I3,    // Entrada 1
        output reg O1      // Salida
        
        input wire s2,   // Se�al de selecci�n
        input wire I4,    // Entrada 0
        input wire I5,    // Entrada 1
        output reg O2      // Salida
        
        input wire s3,   // Se�al de selecci�n
        input wire I6,    // Entrada 0
        input wire I7,    // Entrada 1
        output reg O3      // Salida
    );
endmodule
