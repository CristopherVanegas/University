// Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
// Copyright 2022-2023 Advanced Micro Devices, Inc. All Rights Reserved.
// --------------------------------------------------------------------------------
// Tool Version: Vivado v.2023.2 (win64) Build 4029153 Fri Oct 13 20:14:34 MDT 2023
// Date        : Mon Jul 29 21:01:46 2024
// Host        : ItsMrJkali21 running 64-bit major release  (build 9200)
// Command     : write_verilog -force -mode funcsim -rename_top decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix -prefix
//               decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix_ mux81_mux41_ip_v1_0_0_0_sim_netlist.v
// Design      : mux81_mux41_ip_v1_0_0_0
// Purpose     : This verilog netlist is a functional simulation representation of the design and should not be modified
//               or synthesized. This netlist cannot be used for SDF annotated simulation.
// Device      : xc7z020clg484-1
// --------------------------------------------------------------------------------
`timescale 1 ps / 1 ps

module decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix_mux41_ip
   (sout_0,
    i0,
    i1,
    S1,
    i2,
    i3,
    S2);
  output sout_0;
  input i0;
  input i1;
  input S1;
  input i2;
  input i3;
  input S2;

  wire S1;
  wire S2;
  wire i0;
  wire i1;
  wire i2;
  wire i3;
  wire mux21_0_O;
  wire mux21_1_O;
  wire sout_0;

  (* CHECK_LICENSE_TYPE = "mux41_ip_mux21_0_0,mux21,{}" *) 
  (* DowngradeIPIdentifiedWarnings = "yes" *) 
  (* IP_DEFINITION_SOURCE = "package_project" *) 
  (* X_CORE_INFO = "mux21,Vivado 2023.2" *) 
  decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix_mux41_ip_mux21_0_0 mux21_0
       (.I0(i1),
        .I1(S1),
        .O(mux21_0_O),
        .sel(i0));
  (* CHECK_LICENSE_TYPE = "mux41_ip_mux21_0_1,mux21,{}" *) 
  (* DowngradeIPIdentifiedWarnings = "yes" *) 
  (* IP_DEFINITION_SOURCE = "package_project" *) 
  (* X_CORE_INFO = "mux21,Vivado 2023.2" *) 
  decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix_mux41_ip_mux21_0_1 mux21_1
       (.I0(i3),
        .I1(S1),
        .O(mux21_1_O),
        .sel(i2));
  (* CHECK_LICENSE_TYPE = "mux41_ip_mux21_0_2,mux21,{}" *) 
  (* DowngradeIPIdentifiedWarnings = "yes" *) 
  (* IP_DEFINITION_SOURCE = "package_project" *) 
  (* X_CORE_INFO = "mux21,Vivado 2023.2" *) 
  decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix_mux41_ip_mux21_0_2 mux21_2
       (.I0(mux21_1_O),
        .I1(S2),
        .O(sout_0),
        .sel(mux21_0_O));
endmodule

(* CHECK_LICENSE_TYPE = "mux41_ip_mux21_0_0,mux21,{}" *) (* DowngradeIPIdentifiedWarnings = "yes" *) (* IP_DEFINITION_SOURCE = "package_project" *) 
(* X_CORE_INFO = "mux21,Vivado 2023.2" *) 
module decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix_mux41_ip_mux21_0_0
   (sel,
    I0,
    I1,
    O);
  input sel;
  input I0;
  input I1;
  output O;

  wire I0;
  wire I1;
  wire O;
  wire sel;

  LUT3 #(
    .INIT(8'hB8)) 
    O_INST_0
       (.I0(I1),
        .I1(sel),
        .I2(I0),
        .O(O));
endmodule

(* CHECK_LICENSE_TYPE = "mux41_ip_mux21_0_1,mux21,{}" *) (* DowngradeIPIdentifiedWarnings = "yes" *) (* IP_DEFINITION_SOURCE = "package_project" *) 
(* X_CORE_INFO = "mux21,Vivado 2023.2" *) 
module decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix_mux41_ip_mux21_0_1
   (sel,
    I0,
    I1,
    O);
  input sel;
  input I0;
  input I1;
  output O;

  wire I0;
  wire I1;
  wire O;
  wire sel;

  LUT3 #(
    .INIT(8'hB8)) 
    O_INST_0
       (.I0(I1),
        .I1(sel),
        .I2(I0),
        .O(O));
endmodule

(* CHECK_LICENSE_TYPE = "mux41_ip_mux21_0_2,mux21,{}" *) (* DowngradeIPIdentifiedWarnings = "yes" *) (* IP_DEFINITION_SOURCE = "package_project" *) 
(* X_CORE_INFO = "mux21,Vivado 2023.2" *) 
module decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix_mux41_ip_mux21_0_2
   (sel,
    I0,
    I1,
    O);
  input sel;
  input I0;
  input I1;
  output O;

  wire I0;
  wire I1;
  wire O;
  wire sel;

  LUT3 #(
    .INIT(8'hB8)) 
    O_INST_0
       (.I0(I1),
        .I1(sel),
        .I2(I0),
        .O(O));
endmodule

module decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix_mux41_ip_wrapper
   (sout_0,
    i0,
    i1,
    S1,
    i2,
    i3,
    S2);
  output sout_0;
  input i0;
  input i1;
  input S1;
  input i2;
  input i3;
  input S2;

  wire S1;
  wire S2;
  wire i0;
  wire i1;
  wire i2;
  wire i3;
  wire sout_0;

  decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix_mux41_ip mux41_ip_i
       (.S1(S1),
        .S2(S2),
        .i0(i0),
        .i1(i1),
        .i2(i2),
        .i3(i3),
        .sout_0(sout_0));
endmodule

(* CHECK_LICENSE_TYPE = "mux81_mux41_ip_v1_0_0_0,mux41_ip_wrapper,{}" *) (* DowngradeIPIdentifiedWarnings = "yes" *) (* IP_DEFINITION_SOURCE = "package_project" *) 
(* X_CORE_INFO = "mux41_ip_wrapper,Vivado 2023.2" *) 
(* NotValidForBitStream *)
module decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix
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

  wire S1;
  wire S2;
  wire i0;
  wire i1;
  wire i2;
  wire i3;
  wire sout_0;

  decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix_mux41_ip_wrapper inst
       (.S1(S1),
        .S2(S2),
        .i0(i0),
        .i1(i1),
        .i2(i2),
        .i3(i3),
        .sout_0(sout_0));
endmodule
`ifndef GLBL
`define GLBL
`timescale  1 ps / 1 ps

module glbl ();

    parameter ROC_WIDTH = 100000;
    parameter TOC_WIDTH = 0;
    parameter GRES_WIDTH = 10000;
    parameter GRES_START = 10000;

//--------   STARTUP Globals --------------
    wire GSR;
    wire GTS;
    wire GWE;
    wire PRLD;
    wire GRESTORE;
    tri1 p_up_tmp;
    tri (weak1, strong0) PLL_LOCKG = p_up_tmp;

    wire PROGB_GLBL;
    wire CCLKO_GLBL;
    wire FCSBO_GLBL;
    wire [3:0] DO_GLBL;
    wire [3:0] DI_GLBL;
   
    reg GSR_int;
    reg GTS_int;
    reg PRLD_int;
    reg GRESTORE_int;

//--------   JTAG Globals --------------
    wire JTAG_TDO_GLBL;
    wire JTAG_TCK_GLBL;
    wire JTAG_TDI_GLBL;
    wire JTAG_TMS_GLBL;
    wire JTAG_TRST_GLBL;

    reg JTAG_CAPTURE_GLBL;
    reg JTAG_RESET_GLBL;
    reg JTAG_SHIFT_GLBL;
    reg JTAG_UPDATE_GLBL;
    reg JTAG_RUNTEST_GLBL;

    reg JTAG_SEL1_GLBL = 0;
    reg JTAG_SEL2_GLBL = 0 ;
    reg JTAG_SEL3_GLBL = 0;
    reg JTAG_SEL4_GLBL = 0;

    reg JTAG_USER_TDO1_GLBL = 1'bz;
    reg JTAG_USER_TDO2_GLBL = 1'bz;
    reg JTAG_USER_TDO3_GLBL = 1'bz;
    reg JTAG_USER_TDO4_GLBL = 1'bz;

    assign (strong1, weak0) GSR = GSR_int;
    assign (strong1, weak0) GTS = GTS_int;
    assign (weak1, weak0) PRLD = PRLD_int;
    assign (strong1, weak0) GRESTORE = GRESTORE_int;

    initial begin
	GSR_int = 1'b1;
	PRLD_int = 1'b1;
	#(ROC_WIDTH)
	GSR_int = 1'b0;
	PRLD_int = 1'b0;
    end

    initial begin
	GTS_int = 1'b1;
	#(TOC_WIDTH)
	GTS_int = 1'b0;
    end

    initial begin 
	GRESTORE_int = 1'b0;
	#(GRES_START);
	GRESTORE_int = 1'b1;
	#(GRES_WIDTH);
	GRESTORE_int = 1'b0;
    end

endmodule
`endif
