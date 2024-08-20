// Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
// Copyright 2022-2023 Advanced Micro Devices, Inc. All Rights Reserved.
// --------------------------------------------------------------------------------
// Tool Version: Vivado v.2023.2 (win64) Build 4029153 Fri Oct 13 20:14:34 MDT 2023
// Date        : Mon Jul 29 20:46:25 2024
// Host        : ItsMrJkali21 running 64-bit major release  (build 9200)
// Command     : write_verilog -force -mode synth_stub
//               c:/Users/usuario/Desktop/PROV_WS/MODULOS_IP/mux41/mux41.gen/sources_1/bd/mux41_ip/ip/mux41_ip_mux21_0_0/mux41_ip_mux21_0_0_stub.v
// Design      : mux41_ip_mux21_0_0
// Purpose     : Stub declaration of top-level module interface
// Device      : xc7z020clg484-1
// --------------------------------------------------------------------------------

// This empty module with port declaration file causes synthesis tools to infer a black box for IP.
// The synthesis directives are for Synopsys Synplify support to prevent IO buffer insertion.
// Please paste the declaration into a Verilog source file or add the file as an additional source.
(* X_CORE_INFO = "mux21,Vivado 2023.2" *)
module mux41_ip_mux21_0_0(sel, I0, I1, O)
/* synthesis syn_black_box black_box_pad_pin="sel,I0,I1,O" */;
  input sel;
  input I0;
  input I1;
  output O;
endmodule
