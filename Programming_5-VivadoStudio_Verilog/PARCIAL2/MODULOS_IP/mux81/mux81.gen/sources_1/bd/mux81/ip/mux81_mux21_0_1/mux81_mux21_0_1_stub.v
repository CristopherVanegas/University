// Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
// Copyright 2022-2023 Advanced Micro Devices, Inc. All Rights Reserved.
// --------------------------------------------------------------------------------
// Tool Version: Vivado v.2023.2 (win64) Build 4029153 Fri Oct 13 20:14:34 MDT 2023
// Date        : Mon Jul 29 21:00:38 2024
// Host        : ItsMrJkali21 running 64-bit major release  (build 9200)
// Command     : write_verilog -force -mode synth_stub
//               c:/Users/usuario/Desktop/PROV_WS/MODULOS_IP/mux81/mux81.gen/sources_1/bd/mux81/ip/mux81_mux21_0_1/mux81_mux21_0_1_stub.v
// Design      : mux81_mux21_0_1
// Purpose     : Stub declaration of top-level module interface
// Device      : xc7z020clg484-1
// --------------------------------------------------------------------------------

// This empty module with port declaration file causes synthesis tools to infer a black box for IP.
// The synthesis directives are for Synopsys Synplify support to prevent IO buffer insertion.
// Please paste the declaration into a Verilog source file or add the file as an additional source.
(* X_CORE_INFO = "mux21,Vivado 2023.2" *)
module mux81_mux21_0_1(sel, I0, I1, O)
/* synthesis syn_black_box black_box_pad_pin="sel,I0,I1,O" */;
  input sel;
  input I0;
  input I1;
  output O;
endmodule
