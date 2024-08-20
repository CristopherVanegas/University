// Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
// Copyright 2022-2023 Advanced Micro Devices, Inc. All Rights Reserved.
// --------------------------------------------------------------------------------
// Tool Version: Vivado v.2023.2 (win64) Build 4029153 Fri Oct 13 20:14:34 MDT 2023
// Date        : Mon Jul 29 21:01:46 2024
// Host        : ItsMrJkali21 running 64-bit major release  (build 9200)
// Command     : write_verilog -force -mode synth_stub
//               c:/Users/usuario/Desktop/PROV_WS/MODULOS_IP/mux81/mux81.gen/sources_1/bd/mux81/ip/mux81_mux41_ip_v1_0_0_0/mux81_mux41_ip_v1_0_0_0_stub.v
// Design      : mux81_mux41_ip_v1_0_0_0
// Purpose     : Stub declaration of top-level module interface
// Device      : xc7z020clg484-1
// --------------------------------------------------------------------------------

// This empty module with port declaration file causes synthesis tools to infer a black box for IP.
// The synthesis directives are for Synopsys Synplify support to prevent IO buffer insertion.
// Please paste the declaration into a Verilog source file or add the file as an additional source.
(* X_CORE_INFO = "mux41_ip_wrapper,Vivado 2023.2" *)
module mux81_mux41_ip_v1_0_0_0(S1, S2, i0, i1, i2, i3, sout_0)
/* synthesis syn_black_box black_box_pad_pin="S1,S2,i0,i1,i2,i3,sout_0" */;
  input S1;
  input S2;
  input i0;
  input i1;
  input i2;
  input i3;
  output sout_0;
endmodule
