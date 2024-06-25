`timescale 1ns / 1ps
module operadores_desp_sim();
    reg [3:0] din1 = 4'b0101, din2 = 4'b0110;
    reg [3:0] sdin1 = 4'b0000, sdin2 = 4'b0000;
    
    initial begin
    // Al desplazarlo hacia la izq. los valores vacios de la der. se rellenan con 0
    sdin1 = din1 << 2;
    // Al desplazarlo hacia la der. los valores vacios de la izq. se rellenan con 0
    sdin2 = din1 >> 2;
    
    $display("La variable es %b y el desplazamiento es %b", din1, sdin1);
    $display("La variable es %b y el desplazamiento es %b", din2, sdin2);
    end
endmodule
