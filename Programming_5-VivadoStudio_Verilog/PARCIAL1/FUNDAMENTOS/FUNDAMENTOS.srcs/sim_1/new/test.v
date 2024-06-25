`timescale 1ns / 1ps

module test();
    reg[4:0] numero1 = 5'b10101;
    integer numero2 = 3;
    time tiempo;
    realtime tiempo_real;
    initial begin
        /*
        $display("El numero decimal         es %d", numero1);
        $display("El numero binario         es %b", numero1);
        $display("El numero octal           es %o", numero1);
        $display("El numero hexadecimal     es %h", numero1);
        */
        tiempo = $time;
        tiempo_real = $realtime;
        $display("El numero entero es %b en el tiempo %f y tiempo real %f", numero2, tiempo, tiempo_real);
        #100
        numero2 = 1000;
        tiempo = $time;
        tiempo_real = $realtime;
        $display("El numero entero es %b en el tiempo %f y tiempo real %f", numero2, tiempo, tiempo_real);
    end
    
    initial begin
        $monitor("El numero entero es %b en el tiempo %f y tiempo real %f", numero2, $time, $realtime);
    end
endmodule
