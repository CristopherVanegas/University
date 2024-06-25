// MUX 4x1 + Signal

`timescale 1ns / 1ps

module mux21(
    input A,
    input B,
    input C,
    input D,
    input [1:0] sel,
    output out
    );
    
    reg temp;
    
    always@(*) begin
        if (sel[1] == 1'b0 && sel[0] == 1'b0)
            temp = A;
        else if (sel[1] == 1'b0 && sel[0] == 1'b1)
            temp = B;
        else if (sel[1] == 1'b1 && sel[0] == 1'b0)
            temp = C;
        else if (sel[1] == 1'b1 && sel[0] == 1'b1)
            temp = D;
    end
    assign out = temp;
endmodule
