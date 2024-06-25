`timescale 1ns / 1ps

module main(
    input din,
    input clk,  // clk -> senal de reloj
    output reg q,
    output reg qbar
    );
    
    /* cuando utilice una senal de reloj el circuito se convierte en secuencias pues requier
       de un sincronizmo. 
       Surgen 2 nuevas palabras reservadas para indicar que senales recibe:
        [1] always@(negedge clk) -> mide en bajada por el flanco negativo
        [2] always@(posedge clk) -> mide en subida por el flanco positivo
     */
    always@(posedge clk)
    begin
        q <= din;   // guarda el valor de la entrada del flip flop en q cuando la senal sea neg.
        qbar = ~din;
        
    end    
endmodule





