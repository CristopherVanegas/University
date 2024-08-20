//Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
//Copyright 2022-2023 Advanced Micro Devices, Inc. All Rights Reserved.
//--------------------------------------------------------------------------------
//Tool Version: Vivado v.2023.2 (win64) Build 4029153 Fri Oct 13 20:14:34 MDT 2023
//Date        : Mon Jul 29 21:14:58 2024
//Host        : ItsMrJkali21 running 64-bit major release  (build 9200)
//Command     : generate_target mux161.bd
//Design      : mux161
//Purpose     : IP block netlist
//--------------------------------------------------------------------------------
`timescale 1 ps / 1 ps

(* CORE_GENERATION_INFO = "mux161,IP_Integrator,{x_ipVendor=xilinx.com,x_ipLibrary=BlockDiagram,x_ipName=mux161,x_ipVersion=1.00.a,x_ipLanguage=VERILOG,numBlks=5,numReposBlks=5,numNonXlnxBlks=0,numHierBlks=0,maxHierDepth=0,numSysgenBlks=0,numHlsBlks=0,numHdlrefBlks=0,numPkgbdBlks=0,bdsource=USER,synth_mode=Hierarchical}" *) (* HW_HANDOFF = "mux161.hwdef" *) 
module mux161
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

  wire S1_0_1;
  wire S1_2_1;
  wire S2_0_1;
  wire S2_1_1;
  wire i0_0_1;
  wire i0_1_1;
  wire i0_2_1;
  wire i0_3_1;
  wire i1_0_1;
  wire i1_1_1;
  wire i1_2_1;
  wire i1_3_1;
  wire i2_0_1;
  wire i2_1_1;
  wire i2_2_1;
  wire i2_3_1;
  wire i3_0_1;
  wire i3_1_1;
  wire i3_2_1;
  wire i3_3_1;
  wire mux41_ip_v1_0_0_sout_0;
  wire mux41_ip_v1_0_1_sout_0;
  wire mux41_ip_v1_0_2_sout_0;
  wire mux41_ip_v1_0_3_sout_0;
  wire mux41_ip_v1_0_4_sout_0;

  assign S1_0_1 = S1_0;
  assign S1_2_1 = S1_2;
  assign S2_0_1 = S2_0;
  assign S2_1_1 = S2_1;
  assign i0_0_1 = i0_0;
  assign i0_1_1 = i0_1;
  assign i0_2_1 = i0_2;
  assign i0_3_1 = i0_3;
  assign i1_0_1 = i1_0;
  assign i1_1_1 = i1_1;
  assign i1_2_1 = i1_2;
  assign i1_3_1 = i1_3;
  assign i2_0_1 = i2_0;
  assign i2_1_1 = i2_1;
  assign i2_2_1 = i2_2;
  assign i2_3_1 = i2_3;
  assign i3_0_1 = i3_0;
  assign i3_1_1 = i3_1;
  assign i3_2_1 = i3_2;
  assign i3_3_1 = i3_3;
  assign sout_0_0 = mux41_ip_v1_0_2_sout_0;
  mux161_mux41_ip_v1_0_0_0 mux41_ip_v1_0_0
       (.S1(S1_2_1),
        .S2(S2_1_1),
        .i0(i0_3_1),
        .i1(i1_3_1),
        .i2(i2_3_1),
        .i3(i3_3_1),
        .sout_0(mux41_ip_v1_0_0_sout_0));
  mux161_mux41_ip_v1_0_0_1 mux41_ip_v1_0_1
       (.S1(S1_2_1),
        .S2(S2_1_1),
        .i0(i0_2_1),
        .i1(i1_2_1),
        .i2(i2_2_1),
        .i3(i3_2_1),
        .sout_0(mux41_ip_v1_0_1_sout_0));
  mux161_mux41_ip_v1_0_0_2 mux41_ip_v1_0_2
       (.S1(S1_0_1),
        .S2(S2_0_1),
        .i0(mux41_ip_v1_0_4_sout_0),
        .i1(mux41_ip_v1_0_1_sout_0),
        .i2(mux41_ip_v1_0_0_sout_0),
        .i3(mux41_ip_v1_0_3_sout_0),
        .sout_0(mux41_ip_v1_0_2_sout_0));
  mux161_mux41_ip_v1_0_0_3 mux41_ip_v1_0_3
       (.S1(S1_2_1),
        .S2(S2_1_1),
        .i0(i0_1_1),
        .i1(i1_1_1),
        .i2(i2_1_1),
        .i3(i3_1_1),
        .sout_0(mux41_ip_v1_0_3_sout_0));
  mux161_mux41_ip_v1_0_0_4 mux41_ip_v1_0_4
       (.S1(S1_2_1),
        .S2(S2_1_1),
        .i0(i0_0_1),
        .i1(i1_0_1),
        .i2(i2_0_1),
        .i3(i3_0_1),
        .sout_0(mux41_ip_v1_0_4_sout_0));
endmodule
