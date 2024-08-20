`timescale 1ns / 1ps

module priority83(
    output reg  [2:0] out,
    output reg        valid
);

always @(*) begin
valid = 1'b1;
casex (in)
    8'b10000000: out = 3'b111;
    8'b01000000: out = 3'b110;
    8'b00100000: out = 3'b101;
    8'b00010000: out = 3'b100;
    8'b00001000: out = 3'b011;
    8'b00000100: out = 3'b010;
    8'b00000010: out = 3'b001;
    8'b00000001: out = 3'b000;
    default: begin
        out = 3'bxxx;
        valid = 1'b0;
    end
endcase
end

endmodule