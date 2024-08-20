//Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
//Copyright 2022-2023 Advanced Micro Devices, Inc. All Rights Reserved.
//--------------------------------------------------------------------------------
//Tool Version: Vivado v.2023.2 (win64) Build 4029153 Fri Oct 13 20:14:34 MDT 2023
//Date        : Mon Jul 29 21:00:05 2024
//Host        : ItsMrJkali21 running 64-bit major release  (build 9200)
//Command     : generate_target mux81.bd
//Design      : mux81
//Purpose     : IP block netlist
//--------------------------------------------------------------------------------
`timescale 1 ps / 1 ps

(* CORE_GENERATION_INFO = "mux81,IP_Integrator,{x_ipVendor=xilinx.com,x_ipLibrary=BlockDiagram,x_ipName=mux81,x_ipVersion=1.00.a,x_ipLanguage=VERILOG,numBlks=3,numReposBlks=3,numNonXlnxBlks=0,numHierBlks=0,maxHierDepth=0,numSysgenBlks=0,numHlsBlks=0,numHdlrefBlks=0,numPkgbdBlks=0,bdsource=USER,synth_mode=Hierarchical}" *) (* HW_HANDOFF = "mux81.hwdef" *) 
module mux81
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

  wire S1_0_1;
  wire S2_0_1;
  wire i0_0_1;
  wire i0_1_1;
  wire i1_0_1;
  wire i1_1_1;
  wire i2_0_1;
  wire i2_1_1;
  wire i3_0_1;
  wire i3_1_1;
  wire mux21_0_O;
  wire mux41_ip_v1_0_0_sout_0;
  wire mux41_ip_v1_0_1_sout_0;
  wire sel_0_1;

  assign S1_0_1 = S1_0;
  assign S2_0_1 = S2_0;
  assign Z = mux21_0_O;
  assign i0_0_1 = i0_0;
  assign i0_1_1 = i0_1;
  assign i1_0_1 = i1_0;
  assign i1_1_1 = i1_1;
  assign i2_0_1 = i2_0;
  assign i2_1_1 = i2_1;
  assign i3_0_1 = i3_0;
  assign i3_1_1 = i3_1;
  assign sel_0_1 = sel_0;
  mux81_mux21_0_1 mux21_0
       (.I0(mux41_ip_v1_0_0_sout_0),
        .I1(mux41_ip_v1_0_1_sout_0),
        .O(mux21_0_O),
        .sel(sel_0_1));
  mux81_mux41_ip_v1_0_0_0 mux41_ip_v1_0_0
       (.S1(S1_0_1),
        .S2(S2_0_1),
        .i0(i0_0_1),
        .i1(i1_0_1),
        .i2(i2_0_1),
        .i3(i3_0_1),
        .sout_0(mux41_ip_v1_0_0_sout_0));
  mux81_mux41_ip_v1_0_0_1 mux41_ip_v1_0_1
       (.S1(S1_0_1),
        .S2(S2_0_1),
        .i0(i0_1_1),
        .i1(i1_1_1),
        .i2(i2_1_1),
        .i3(i3_1_1),
        .sout_0(mux41_ip_v1_0_1_sout_0));
endmodule
