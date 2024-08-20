//Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
//Copyright 2022-2023 Advanced Micro Devices, Inc. All Rights Reserved.
//--------------------------------------------------------------------------------
//Tool Version: Vivado v.2023.2 (win64) Build 4029153 Fri Oct 13 20:14:34 MDT 2023
//Date        : Mon Jul 29 20:45:53 2024
//Host        : ItsMrJkali21 running 64-bit major release  (build 9200)
//Command     : generate_target mux41_ip_wrapper.bd
//Design      : mux41_ip_wrapper
//Purpose     : IP block netlist
//--------------------------------------------------------------------------------
`timescale 1 ps / 1 ps

module mux41_ip_wrapper
   (S1,
    S2,
    i0,
    i1,
    i2,
    i3,
    sout_0);
  input S1;
  input S2;
  input i0;
  input i1;
  input i2;
  input i3;
  output sout_0;

  wire S1;
  wire S2;
  wire i0;
  wire i1;
  wire i2;
  wire i3;
  wire sout_0;

  mux41_ip mux41_ip_i
       (.S1(S1),
        .S2(S2),
        .i0(i0),
        .i1(i1),
        .i2(i2),
        .i3(i3),
        .sout_0(sout_0));
endmodule
