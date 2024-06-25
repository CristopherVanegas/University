`timescale 1ns / 1ps

module ff_rs(
    input R,
    input S,
    input CLK,
    output reg Q,
    output reg QBAR
    );
    always@(negedge CLK)
    begin
        case({R, S})
        2'b00: 
        begin
            Q <= Q;
            QBAR <= QBAR;
        end
        2'b01:
        begin
            Q <= 1;
            QBAR <= 0;
        end
        2'b10:
        begin
            Q <= 0;
            QBAR <= 1;
        end
        2'b11:
        begin
            Q <= 1'bx;
            QBAR <= 1'bx;
        end
        endcase
    end
endmodule
