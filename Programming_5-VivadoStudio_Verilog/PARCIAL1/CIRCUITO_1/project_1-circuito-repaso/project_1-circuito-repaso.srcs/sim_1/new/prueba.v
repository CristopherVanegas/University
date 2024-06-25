`timescale 1ns / 1ps

module prueba_mod(

    );
    
    reg a, b, c, d;
    wire s;
    
    circuito1 circ(a, b, c, d); //dut [device unit test]
    initial begin
    a = 0;
    b = 0;
    c = 0;
    d = 0;
    #500;
    
    a = 0;
    b = 0;
    c = 0;
    d = 1;
    #500;
        
    a = 0;
    b = 0;
    c = 1;
    d = 0;
    #500;
        
    a = 0;
    b = 0;
    c = 1;
    d = 1;
    #500;
    end
endmodule
