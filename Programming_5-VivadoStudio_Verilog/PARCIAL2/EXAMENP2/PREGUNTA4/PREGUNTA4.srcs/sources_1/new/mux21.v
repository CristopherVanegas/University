`timescale 1ns / 1ps

module mux21(
    input A,
    input B,
    input S,
    output out
    );
    reg temp;
    
    always@(*) begin
        case (S)
            1'b0: temp = A;
            1'b1: temp = B;
        endcase
    end
    assign out = temp;
endmodule
