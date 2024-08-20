`timescale 1ns / 1ps

module mux21(
    input i0,
    input i1,
    input sel,
    output out
    );
    
    reg temp;
    
    always@(*) begin
        if(sel == 1'b1)
            temp = i0;
        else
            temp = i1;
    end
    
    assign out = temp;
    
endmodule
