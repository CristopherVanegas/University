`timescale 1ns / 1ps

module mux41(
        input wire [1:0] s,    // Señales de selección
        input wire       I0,     // Entrada 0
        input wire       I1,     // Entrada 1
        input wire       I2,     // Entrada 2
        input wire       I3,     // Entrada 3
        output reg       O       // Salida
    );
    always@(*) begin
        case (s)
            2'b00: O = I0;
            2'b01: O = I1;
            2'b10: O = I2;
            2'b11: O = I3;
        endcase
    end
endmodule

module mux21(
        input A,
        input B,
        input S,
        output out
        );
        reg temp;
        
        always@(*) begin
            case (S)
                1'b0: temp = A;
                1'b1: temp = B;
            endcase
        end
        assign out = temp;
endmodule

module mux8(
        input wire [1:0] s1,     // Señales de selección
        input wire       I0,     // Entrada 0
        input wire       I1,     // Entrada 1
        input wire       I2,     // Entrada 2
        input wire       I3,     // Entrada 3
        wire O1,
        input wire [1:0] s2,     // Señales de selección
        input wire       I4,     // Entrada 0
        input wire       I5,     // Entrada 1
        input wire       I6,     // Entrada 2
        input wire       I7,     // Entrada 3
        wire O2,
        input wire s3,           // Señales de selección
        output       Z       // Salida
    );
    
    // Mapeo Implicito //
    mux41 mux41_0(s1, I0, I1, I2, I3, O1);
    // Mapeo Implicito //
    mux41 mux41_1(s2, I4, I5, I6, I7, O2);
    // Mapeo Implicito //
    mux21 mux21_0(O1, O2, s3, Z);
endmodule