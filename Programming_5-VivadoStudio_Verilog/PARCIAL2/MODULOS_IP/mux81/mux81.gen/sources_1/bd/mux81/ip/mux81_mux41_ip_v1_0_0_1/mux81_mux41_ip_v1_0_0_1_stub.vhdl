-- Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
-- Copyright 2022-2023 Advanced Micro Devices, Inc. All Rights Reserved.
-- --------------------------------------------------------------------------------
-- Tool Version: Vivado v.2023.2 (win64) Build 4029153 Fri Oct 13 20:14:34 MDT 2023
-- Date        : Mon Jul 29 21:01:46 2024
-- Host        : ItsMrJkali21 running 64-bit major release  (build 9200)
-- Command     : write_vhdl -force -mode synth_stub -rename_top mux81_mux41_ip_v1_0_0_1 -prefix
--               mux81_mux41_ip_v1_0_0_1_ mux81_mux41_ip_v1_0_0_0_stub.vhdl
-- Design      : mux81_mux41_ip_v1_0_0_0
-- Purpose     : Stub declaration of top-level module interface
-- Device      : xc7z020clg484-1
-- --------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity mux81_mux41_ip_v1_0_0_1 is
  Port ( 
    S1 : in STD_LOGIC;
    S2 : in STD_LOGIC;
    i0 : in STD_LOGIC;
    i1 : in STD_LOGIC;
    i2 : in STD_LOGIC;
    i3 : in STD_LOGIC;
    sout_0 : out STD_LOGIC
  );

end mux81_mux41_ip_v1_0_0_1;

architecture stub of mux81_mux41_ip_v1_0_0_1 is
attribute syn_black_box : boolean;
attribute black_box_pad_pin : string;
attribute syn_black_box of stub : architecture is true;
attribute black_box_pad_pin of stub : architecture is "S1,S2,i0,i1,i2,i3,sout_0";
attribute X_CORE_INFO : string;
attribute X_CORE_INFO of stub : architecture is "mux41_ip_wrapper,Vivado 2023.2";
begin
end;
