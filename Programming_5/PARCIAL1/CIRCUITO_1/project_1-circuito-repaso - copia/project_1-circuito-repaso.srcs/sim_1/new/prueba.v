`timescale 1ns / 1ps

module prueba_mod(

    );
    
    reg a, b, c;
    wire s;
    
    circuito1 circ(a, b, c, s); //dut [device unit test]
    initial begin
    a = 0;
    b = 0;
    c = 0;
    #500;
    
    a = 0;
    b = 0;
    c = 1;
    #500;
    
    a = 0;
    b = 1;
    c = 0;
    #500;
    
    a = 0;
    b = 1;
    c = 1;
    #500;
    
    a = 1;
    b = 0;
    c = 0;
    #500;
    
    a = 1;
    b = 0;
    c = 1;
    #500;
    
    a = 1;
    b = 1;
    c = 0;
    #500;
    
    a = 1;
    b = 1;
    c = 1;
    #500;
    end
endmodule
