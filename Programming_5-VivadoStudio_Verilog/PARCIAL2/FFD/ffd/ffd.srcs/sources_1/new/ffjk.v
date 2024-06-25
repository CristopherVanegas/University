`timescale 1ns / 1ps

module ffjk(
    input j,
    input k,
    input clk,
    output reg q,
    output reg qbar
    );
    
    always@(posedge clk)
    begin
        case ({j, k})
            2'b00:
            begin
                q <= q;
                qbar <= ~q;
            end
            2'b01:
            begin
                q <= 0;
                qbar <= 1;
            end
            2'b10:
            begin
                q <= 1;
                qbar <= 0;
            end
            2'b11:
            begin
                q <= ~q;
                qbar <= ~qbar;
            end
        endcase
    end    
endmodule
