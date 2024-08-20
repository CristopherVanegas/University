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

module mux16(
        input wire [1:0] s1,     // Señales de selección
        input wire       I0,     // Entrada 0
        input wire       I1,     // Entrada 1
        input wire       I2,     // Entrada 2
        input wire       I3,     // Entrada 3
        wire M1,
        input wire [1:0] s2,     // Señales de selección
        input wire       I4,     // Entrada 0
        input wire       I5,     // Entrada 1
        input wire       I6,     // Entrada 2
        input wire       I7,     // Entrada 3
        wire M2,
        input wire [1:0] s3,     // Señales de selección
        input wire       I8,     // Entrada 0
        input wire       I9,     // Entrada 1
        input wire       I10,     // Entrada 2
        input wire       I11,     // Entrada 3
        wire M3,
        input wire [1:0] s4,     // Señales de selección
        input wire       I12,     // Entrada 0
        input wire       I13,     // Entrada 1
        input wire       I14,     // Entrada 2
        input wire       I15,     // Entrada 3
        wire M4,
        input wire [1:0] s5,     // Señales de selección
        output       Y       // Salida
    );
    
    // Mapeo Implicito //
    mux41 mux41_0(s1, I0, I1, I2, I3, M1);
    // Mapeo Implicito //
    mux41 mux41_1(s2, I4, I5, I6, I7, M2);
    // Mapeo Implicito //
    mux41 mux41_2(s3, I8, I9, I10, I11, M3);
    // Mapeo Implicito //
    mux41 mux41_3(s4, I12, I13, I14, I15, M4);
    // Mapeo Implicito //
    mux41 mux41_4(s5, M1, M2, M3, M4, Y);
endmodule