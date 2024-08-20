`timescale 1ns / 1ps

module mux41(
    input A,
    input B,
    input C,
    input D,
    output [1:0] SEL,
    output reg Y
    );
    
    always@(*) begin
        if(SEL == 2'b00)
            Y = A;
        else if(SEL == 2'b01)
            Y = B;
        else if(SEL == 2'b10)
            Y = C;
        else
            Y = D;
        end
endmodule
