`timescale 1ns / 1ps

module metodo_1proceso(
        input clk, rst, din, 
        output reg dout
    );
    parameter idle = 0;
    parameter s0 = 1;
    parameter s1 = 2;
    
    reg [1:0] state = idle;
    
    always@(posedge clk) begin
        if(rst == 1'b1) begin
            state <= idle;
            state = s0;
        end
        else begin
            case(state)
                idle: begin
                    dout = 1'b0;
                    state = s0;
                end
                s0: begin
                    dout = 1'b0;
                    if(din == 1'b1)
                        state = s1;
                    else
                        state = s0;
                end
                s1: begin
                    dout = 1'b1;
                    if(din == 1'b1)
                        state = s0;
                    else
                        state = s1;
                end
            endcase
        end
        
        
    end
endmodule
