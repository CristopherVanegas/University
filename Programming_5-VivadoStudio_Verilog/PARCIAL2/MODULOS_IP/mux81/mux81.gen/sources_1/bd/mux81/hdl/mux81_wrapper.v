//Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
//Copyright 2022-2023 Advanced Micro Devices, Inc. All Rights Reserved.
//--------------------------------------------------------------------------------
//Tool Version: Vivado v.2023.2 (win64) Build 4029153 Fri Oct 13 20:14:34 MDT 2023
//Date        : Mon Jul 29 21:00:05 2024
//Host        : ItsMrJkali21 running 64-bit major release  (build 9200)
//Command     : generate_target mux81_wrapper.bd
//Design      : mux81_wrapper
//Purpose     : IP block netlist
//--------------------------------------------------------------------------------
`timescale 1 ps / 1 ps

module mux81_wrapper
   (S1_0,
    S2_0,
    Z,
    i0_0,
    i0_1,
    i1_0,
    i1_1,
    i2_0,
    i2_1,
    i3_0,
    i3_1,
    sel_0);
  input S1_0;
  input S2_0;
  output Z;
  input i0_0;
  input i0_1;
  input i1_0;
  input i1_1;
  input i2_0;
  input i2_1;
  input i3_0;
  input i3_1;
  input sel_0;

  wire S1_0;
  wire S2_0;
  wire Z;
  wire i0_0;
  wire i0_1;
  wire i1_0;
  wire i1_1;
  wire i2_0;
  wire i2_1;
  wire i3_0;
  wire i3_1;
  wire sel_0;

  mux81 mux81_i
       (.S1_0(S1_0),
        .S2_0(S2_0),
        .Z(Z),
        .i0_0(i0_0),
        .i0_1(i0_1),
        .i1_0(i1_0),
        .i1_1(i1_1),
        .i2_0(i2_0),
        .i2_1(i2_1),
        .i3_0(i3_0),
        .i3_1(i3_1),
        .sel_0(sel_0));
endmodule
