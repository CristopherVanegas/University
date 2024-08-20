//Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
//Copyright 2022-2023 Advanced Micro Devices, Inc. All Rights Reserved.
//--------------------------------------------------------------------------------
//Tool Version: Vivado v.2023.2 (win64) Build 4029153 Fri Oct 13 20:14:34 MDT 2023
//Date        : Wed Jul 24 21:01:53 2024
//Host        : smb_d2_26 running 64-bit major release  (build 9200)
//Command     : generate_target design_1.bd
//Design      : design_1
//Purpose     : IP block netlist
//--------------------------------------------------------------------------------
`timescale 1 ps / 1 ps

(* CORE_GENERATION_INFO = "design_1,IP_Integrator,{x_ipVendor=xilinx.com,x_ipLibrary=BlockDiagram,x_ipName=design_1,x_ipVersion=1.00.a,x_ipLanguage=VERILOG,numBlks=3,numReposBlks=3,numNonXlnxBlks=3,numHierBlks=0,maxHierDepth=0,numSysgenBlks=0,numHlsBlks=0,numHdlrefBlks=0,numPkgbdBlks=0,bdsource=USER,synth_mode=Hierarchical}" *) (* HW_HANDOFF = "design_1.hwdef" *) 
module design_1
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

  wire i0_0_1;
  wire i0_0_2;
  wire i1_0_1;
  wire i1_0_2;
  wire mux21_0_out;
  wire mux21_1_out;
  wire mux21_2_out;
  wire sel_0_1;
  wire sel_0_2;

  assign i0_0_1 = i0;
  assign i0_0_2 = i2;
  assign i1_0_1 = i1;
  assign i1_0_2 = i3;
  assign out_0 = mux21_1_out;
  assign sel_0_1 = s1;
  assign sel_0_2 = s2;
  design_1_mux21_0_0 mux21_0
       (.i0(i0_0_1),
        .i1(i1_0_1),
        .out(mux21_0_out),
        .sel(sel_0_1));
  design_1_mux21_0_1 mux21_1
       (.i0(mux21_0_out),
        .i1(mux21_2_out),
        .out(mux21_1_out),
        .sel(sel_0_2));
  design_1_mux21_0_2 mux21_2
       (.i0(i0_0_2),
        .i1(i1_0_2),
        .out(mux21_2_out),
        .sel(sel_0_1));
endmodule
