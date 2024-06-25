`timescale 1ns / 1ps

module operadores_aritmeticos(
    );
    integer numero1, numero2;
    wire salida;
    
    initial begin
        $display("La suma es %d", (numero1 + numero2));
        $display("La resta es %d", (numero1 - numero2));
        $display("La multiplicacion es %d", (numero1 * numero2));
        $display("La division es %d", (numero1 / numero2));
    end
endmodule
