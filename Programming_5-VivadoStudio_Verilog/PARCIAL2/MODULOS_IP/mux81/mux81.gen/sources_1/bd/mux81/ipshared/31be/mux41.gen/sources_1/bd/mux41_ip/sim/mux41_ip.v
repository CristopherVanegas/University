//Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
//Copyright 2022-2023 Advanced Micro Devices, Inc. All Rights Reserved.
//--------------------------------------------------------------------------------
//Tool Version: Vivado v.2023.2 (win64) Build 4029153 Fri Oct 13 20:14:34 MDT 2023
//Date        : Mon Jul 29 20:45:53 2024
//Host        : ItsMrJkali21 running 64-bit major release  (build 9200)
//Command     : generate_target mux41_ip.bd
//Design      : mux41_ip
//Purpose     : IP block netlist
//--------------------------------------------------------------------------------
`timescale 1 ps / 1 ps

(* CORE_GENERATION_INFO = "mux41_ip,IP_Integrator,{x_ipVendor=xilinx.com,x_ipLibrary=BlockDiagram,x_ipName=mux41_ip,x_ipVersion=1.00.a,x_ipLanguage=VERILOG,numBlks=3,numReposBlks=3,numNonXlnxBlks=0,numHierBlks=0,maxHierDepth=0,numSysgenBlks=0,numHlsBlks=0,numHdlrefBlks=0,numPkgbdBlks=0,bdsource=USER,synth_mode=Hierarchical}" *) (* HW_HANDOFF = "mux41_ip.hwdef" *) 
module mux41_ip
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

  wire I0_0_1;
  wire I0_0_2;
  wire I1_0_1;
  wire I1_0_2;
  wire mux21_0_O;
  wire mux21_1_O;
  wire mux21_2_O;
  wire sel_0_1;
  wire sel_0_2;

  assign I0_0_1 = i1;
  assign I0_0_2 = i3;
  assign I1_0_1 = S1;
  assign I1_0_2 = S2;
  assign sel_0_1 = i0;
  assign sel_0_2 = i2;
  assign sout_0 = mux21_2_O;
  mux41_ip_mux21_0_0 mux21_0
       (.I0(I0_0_1),
        .I1(I1_0_1),
        .O(mux21_0_O),
        .sel(sel_0_1));
  mux41_ip_mux21_0_1 mux21_1
       (.I0(I0_0_2),
        .I1(I1_0_1),
        .O(mux21_1_O),
        .sel(sel_0_2));
  mux41_ip_mux21_0_2 mux21_2
       (.I0(mux21_1_O),
        .I1(I1_0_2),
        .O(mux21_2_O),
        .sel(mux21_0_O));
endmodule
