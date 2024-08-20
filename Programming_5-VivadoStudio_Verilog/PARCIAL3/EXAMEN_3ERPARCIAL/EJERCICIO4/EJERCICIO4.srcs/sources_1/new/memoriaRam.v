`timescale 1ns / 1ps

// 128 & 16 (profundidad o filas x tamanio o columnas)
module memoriaRam(
        input clk, // reloj
        input we, // write enable
        input rst, // boton para blankear la memoria
        input [6:0] addr, // mem para direccionamiento
        input [15:0] din, // mem de entrada de dato de 16 bits
        input [15:0] dout //mem para salida de dato de 16 bits
    );
    reg [15:0] mem [128:0];
    reg [15:0] temp;
    integer i = 0;
    always@(posedge clk) begin
        if (rst == 1'b1) begin
            for (i = 0; i < 128; i = i + 1) begin
                mem[i] <= 16'h00;
            end
        end
        else begin
            if (we == 1'b1)
                mem[addr] <= din;
            else
                temp <= mem[addr];
        end
    end
    assign dout = temp;
endmodule
