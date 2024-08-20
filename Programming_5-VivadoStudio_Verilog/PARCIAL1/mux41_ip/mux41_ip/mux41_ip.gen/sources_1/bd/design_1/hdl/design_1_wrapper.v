//Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
//Copyright 2022-2023 Advanced Micro Devices, Inc. All Rights Reserved.
//--------------------------------------------------------------------------------
//Tool Version: Vivado v.2023.2 (win64) Build 4029153 Fri Oct 13 20:14:34 MDT 2023
//Date        : Wed Jul 24 21:01:53 2024
//Host        : smb_d2_26 running 64-bit major release  (build 9200)
//Command     : generate_target design_1_wrapper.bd
//Design      : design_1_wrapper
//Purpose     : IP block netlist
//--------------------------------------------------------------------------------
`timescale 1 ps / 1 ps

module design_1_wrapper
   (i0,
    i1,
    i2,
    i3,
    out_0,
    s1,
    s2);
  input i0;
  input i1;
  input i2;
  input i3;
  output out_0;
  input s1;
  input s2;

  wire i0;
  wire i1;
  wire i2;
  wire i3;
  wire out_0;
  wire s1;
  wire s2;

  design_1 design_1_i
       (.i0(i0),
        .i1(i1),
        .i2(i2),
        .i3(i3),
        .out_0(out_0),
        .s1(s1),
        .s2(s2));
endmodule
