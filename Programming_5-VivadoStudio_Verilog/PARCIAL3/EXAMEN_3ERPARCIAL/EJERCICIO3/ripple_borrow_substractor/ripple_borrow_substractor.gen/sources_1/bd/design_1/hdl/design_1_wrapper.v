//Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
//Copyright 2022-2023 Advanced Micro Devices, Inc. All Rights Reserved.
//--------------------------------------------------------------------------------
//Tool Version: Vivado v.2023.2 (win64) Build 4029153 Fri Oct 13 20:14:34 MDT 2023
//Date        : Wed Aug 14 21:04:13 2024
//Host        : ItsMrJkali21 running 64-bit major release  (build 9200)
//Command     : generate_target design_1_wrapper.bd
//Design      : design_1_wrapper
//Purpose     : IP block netlist
//--------------------------------------------------------------------------------
`timescale 1 ps / 1 ps

module design_1_wrapper
   (A_0,
    A_1,
    A_2,
    A_3,
    B_0,
    B_1,
    B_2,
    B_3,
    Br,
    Br_0,
    C_0,
    D,
    D_0,
    D_1,
    D_2,
    D_3);
  input A_0;
  input A_1;
  input A_2;
  input A_3;
  input B_0;
  input B_1;
  input B_2;
  input B_3;
  output Br;
  output Br_0;
  input C_0;
  output D;
  output D_0;
  output D_1;
  output D_2;
  output D_3;

  wire A_0;
  wire A_1;
  wire A_2;
  wire A_3;
  wire B_0;
  wire B_1;
  wire B_2;
  wire B_3;
  wire Br;
  wire Br_0;
  wire C_0;
  wire D;
  wire D_0;
  wire D_1;
  wire D_2;
  wire D_3;

  design_1 design_1_i
       (.A_0(A_0),
        .A_1(A_1),
        .A_2(A_2),
        .A_3(A_3),
        .B_0(B_0),
        .B_1(B_1),
        .B_2(B_2),
        .B_3(B_3),
        .Br(Br),
        .Br_0(Br_0),
        .C_0(C_0),
        .D(D),
        .D_0(D_0),
        .D_1(D_1),
        .D_2(D_2),
        .D_3(D_3));
endmodule
