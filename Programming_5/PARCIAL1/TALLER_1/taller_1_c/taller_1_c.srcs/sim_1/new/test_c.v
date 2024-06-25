`timescale 1ns / 1ps

module test_c(

    );
    
    reg a, b, c;
    wire s;
    
    main circ(a, b, c); //dut [device unit test]
    initial begin
    a = 1;
    b = 0;
    c = 0;
    #500;
    
    a = 0;
    b = 1;
    c = 0;
    #500;
        
    a = 1;
    b = 1;
    c = 0;
    #500;
        
    a = 0;
    b = 0;
    c = 1;
    #500;
    end
    
endmodule
