`timescale 1ns / 1ps

// 64 & 8 (profundidad o filas x tamanio o columnas)
module mem_ram(
        input clk, // reloj
        input we, // write enable
        input rst, // boton para blankear la memoria
        input [5:0] addr, // mem para direccionamiento
        input [7:0] din, // mem de entrada de dato de 8 bits
        input [7:0] dout //mem para salida de dato de 8 bits
    );
    reg [7:0] mem [63:0];
    reg [7:0] temp;
    integer i = 0;
    always@(posedge clk) begin
        if (rst == 1'b1) begin
            for (i = 0; i < 64; i = i + 1) begin
                mem[i] <= 8'h00;
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
