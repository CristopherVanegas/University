// Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
// Copyright 2022-2023 Advanced Micro Devices, Inc. All Rights Reserved.
// --------------------------------------------------------------------------------
// Tool Version: Vivado v.2023.2 (win64) Build 4029153 Fri Oct 13 20:14:34 MDT 2023
// Date        : Wed Jul 24 21:02:32 2024
// Host        : smb_d2_26 running 64-bit major release  (build 9200)
// Command     : write_verilog -force -mode synth_stub -rename_top design_1_mux21_0_1 -prefix
//               design_1_mux21_0_1_ design_1_mux21_0_0_stub.v
// Design      : design_1_mux21_0_0
// Purpose     : Stub declaration of top-level module interface
// Device      : xc7z020clg484-1
// --------------------------------------------------------------------------------

// This empty module with port declaration file causes synthesis tools to infer a black box for IP.
// The synthesis directives are for Synopsys Synplify support to prevent IO buffer insertion.
// Please paste the declaration into a Verilog source file or add the file as an additional source.
(* X_CORE_INFO = "mux21,Vivado 2023.2" *)
module design_1_mux21_0_1(i0, i1, sel, out)
/* synthesis syn_black_box black_box_pad_pin="i0,i1,sel,out" */;
  input i0;
  input i1;
  input sel;
  output out;
endmodule
