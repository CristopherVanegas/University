//Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
//Copyright 2022-2023 Advanced Micro Devices, Inc. All Rights Reserved.
//--------------------------------------------------------------------------------
//Tool Version: Vivado v.2023.2 (win64) Build 4029153 Fri Oct 13 20:14:34 MDT 2023
//Date        : Mon Jul 29 21:14:58 2024
//Host        : ItsMrJkali21 running 64-bit major release  (build 9200)
//Command     : generate_target mux161_wrapper.bd
//Design      : mux161_wrapper
//Purpose     : IP block netlist
//--------------------------------------------------------------------------------
`timescale 1 ps / 1 ps

module mux161_wrapper
   (S1_0,
    S1_2,
    S2_0,
    S2_1,
    i0_0,
    i0_1,
    i0_2,
    i0_3,
    i1_0,
    i1_1,
    i1_2,
    i1_3,
    i2_0,
    i2_1,
    i2_2,
    i2_3,
    i3_0,
    i3_1,
    i3_2,
    i3_3,
    sout_0_0);
  input S1_0;
  input S1_2;
  input S2_0;
  input S2_1;
  input i0_0;
  input i0_1;
  input i0_2;
  input i0_3;
  input i1_0;
  input i1_1;
  input i1_2;
  input i1_3;
  input i2_0;
  input i2_1;
  input i2_2;
  input i2_3;
  input i3_0;
  input i3_1;
  input i3_2;
  input i3_3;
  output sout_0_0;

  wire S1_0;
  wire S1_2;
  wire S2_0;
  wire S2_1;
  wire i0_0;
  wire i0_1;
  wire i0_2;
  wire i0_3;
  wire i1_0;
  wire i1_1;
  wire i1_2;
  wire i1_3;
  wire i2_0;
  wire i2_1;
  wire i2_2;
  wire i2_3;
  wire i3_0;
  wire i3_1;
  wire i3_2;
  wire i3_3;
  wire sout_0_0;

  mux161 mux161_i
       (.S1_0(S1_0),
        .S1_2(S1_2),
        .S2_0(S2_0),
        .S2_1(S2_1),
        .i0_0(i0_0),
        .i0_1(i0_1),
        .i0_2(i0_2),
        .i0_3(i0_3),
        .i1_0(i1_0),
        .i1_1(i1_1),
        .i1_2(i1_2),
        .i1_3(i1_3),
        .i2_0(i2_0),
        .i2_1(i2_1),
        .i2_2(i2_2),
        .i2_3(i2_3),
        .i3_0(i3_0),
        .i3_1(i3_1),
        .i3_2(i3_2),
        .i3_3(i3_3),
        .sout_0_0(sout_0_0));
endmodule
