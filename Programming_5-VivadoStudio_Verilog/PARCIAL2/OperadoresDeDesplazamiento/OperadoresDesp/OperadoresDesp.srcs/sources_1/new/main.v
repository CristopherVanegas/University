`timescale 1ns / 1ps

module main(
    );
    reg [3:0] din1 = 4'b0101, din2 = 4'b0110;
    reg [3:0] sdin1 = 4'b0000, sdin2 = 4'b0000;
    reg [7:0] concat = 0;
    reg [11:0] repeticion = 0;
    
    initial begin
    // Al desplazarlo hacia la izq. los valores vacios de la der. se rellenan con 0
    sdin1 = din1 << 2;
    // Al desplazarlo hacia la der. los valores vacios de la izq. se rellenan con 0
    sdin2 = din1 >> 2;
    
    concat = {sdin1, sdin2};
    
    $display("La variable es %b y el desplazamiento hacia la izq. es %b", din1, sdin1);
    $display("La variable es %b y el desplazamiento hacia la der. es %b", din2, sdin2);
    $display("La concatenacion de sdin1 %b y  sdin2 %b es concatenacion %b", sdin1, sdin2, concat);
    
    repeticion = {3{din2}};
    $display("Guardando 3 veces din2 %b en repeticion %b", din2, repeticion);
    end
endmodule
