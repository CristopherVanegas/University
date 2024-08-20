//Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
//Copyright 2022-2023 Advanced Micro Devices, Inc. All Rights Reserved.
//--------------------------------------------------------------------------------
//Tool Version: Vivado v.2023.2 (win64) Build 4029153 Fri Oct 13 20:14:34 MDT 2023
//Date        : Wed Aug 14 21:04:13 2024
//Host        : ItsMrJkali21 running 64-bit major release  (build 9200)
//Command     : generate_target design_1.bd
//Design      : design_1
//Purpose     : IP block netlist
//--------------------------------------------------------------------------------
`timescale 1 ps / 1 ps

(* CORE_GENERATION_INFO = "design_1,IP_Integrator,{x_ipVendor=xilinx.com,x_ipLibrary=BlockDiagram,x_ipName=design_1,x_ipVersion=1.00.a,x_ipLanguage=VERILOG,numBlks=4,numReposBlks=4,numNonXlnxBlks=0,numHierBlks=0,maxHierDepth=0,numSysgenBlks=0,numHlsBlks=0,numHdlrefBlks=0,numPkgbdBlks=0,bdsource=USER,synth_mode=Hierarchical}" *) (* HW_HANDOFF = "design_1.hwdef" *) 
module design_1
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

  wire A_0_1;
  wire A_1_1;
  wire A_2_1;
  wire A_3_1;
  wire B_0_1;
  wire B_1_1;
  wire B_2_1;
  wire B_3_1;
  wire C_0_1;
  wire full_substractor_0_Br;
  wire full_substractor_0_D;
  wire full_substractor_1_Br;
  wire full_substractor_1_D;
  wire full_substractor_2_Br;
  wire full_substractor_2_D;
  wire full_substractor_3_Br;
  wire full_substractor_3_D;

  assign A_0_1 = A_0;
  assign A_1_1 = A_1;
  assign A_2_1 = A_2;
  assign A_3_1 = A_3;
  assign B_0_1 = B_0;
  assign B_1_1 = B_1;
  assign B_2_1 = B_2;
  assign B_3_1 = B_3;
  assign Br = full_substractor_0_Br;
  assign C_0_1 = C_0;
  assign D = full_substractor_2_D;
  assign D_1 = full_substractor_3_D;
  assign D_2 = full_substractor_1_D;
  assign D_3 = full_substractor_0_D;
  design_1_full_substractor_0_0 full_substractor_0
       (.A(A_3_1),
        .B(B_3_1),
        .Br(full_substractor_0_Br),
        .C(full_substractor_1_Br),
        .D(full_substractor_0_D));
  design_1_full_substractor_0_1 full_substractor_1
       (.A(A_2_1),
        .B(B_2_1),
        .Br(full_substractor_1_Br),
        .C(full_substractor_3_Br),
        .D(full_substractor_1_D));
  design_1_full_substractor_0_2 full_substractor_2
       (.A(A_0_1),
        .B(B_0_1),
        .Br(full_substractor_2_Br),
        .C(C_0_1),
        .D(full_substractor_2_D));
  design_1_full_substractor_0_3 full_substractor_3
       (.A(A_1_1),
        .B(B_1_1),
        .Br(full_substractor_3_Br),
        .C(full_substractor_2_Br),
        .D(full_substractor_3_D));
endmodule
