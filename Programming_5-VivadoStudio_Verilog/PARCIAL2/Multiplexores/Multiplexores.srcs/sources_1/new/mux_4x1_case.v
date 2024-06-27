// MUX 4x1 + Signal | Case statement

`timescale 1ns / 1ps

module mux_4x1_case(
    input A,
    input B,
    input C,
    input D,
    input [1:0] sel,
    output out
    );
    reg temp;
    
    always@(*) begin
        case (sel)
            2'b00: temp = A;
            2'b01: temp = B;
            2'b10: temp = C;
            2'b11: temp = D;
        endcase
    end
    assign out = temp;
    
endmodule
