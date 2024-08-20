`timescale 1ns / 1ps

module e1_mux61(
        input wire [5:0] data_in,   // Entrada de datos, 6 bits
        input wire [2:0] sel,       // Señal de selección, 3 bits
        output reg data_out         // Salida de datos
    );
    
    always @(*) begin
        case (sel)
            3'b000: data_out = data_in[0];
            3'b001: data_out = data_in[1];
            3'b010: data_out = data_in[2];
            3'b011: data_out = data_in[3];
            3'b100: data_out = data_in[4];
            3'b101: data_out = data_in[5];
            default: data_out = 1'b0; // Valor por defecto
        endcase
    end
    
endmodule
