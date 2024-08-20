`timescale 1ns / 1ps

module mux21 (
        input wire sel,   // Señal de selección
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
