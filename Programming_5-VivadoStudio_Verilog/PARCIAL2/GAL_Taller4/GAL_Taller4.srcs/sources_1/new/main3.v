`timescale 1ns / 1ps

module paralel(
input c,
input x0,
input y0,
output d0,
input x1,
input y1,
output d1,
input x2,
input y2,
output d2,
input x3,
input y3,
output d3,
output bout
);

wire t1, t2, t3;

full ps1(x0, y0, c,d0, t1);
full ps2(x1, y1, t1, d1, t2);
full ps3(x2, y2, t2, d2, t3);
full ps4(x3, y3, t3, d3, bout);

endmodule
