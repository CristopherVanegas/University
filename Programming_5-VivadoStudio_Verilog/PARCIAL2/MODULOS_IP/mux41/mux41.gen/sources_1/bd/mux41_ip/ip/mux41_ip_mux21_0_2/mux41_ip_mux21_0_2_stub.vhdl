-- Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
-- Copyright 2022-2023 Advanced Micro Devices, Inc. All Rights Reserved.
-- --------------------------------------------------------------------------------
-- Tool Version: Vivado v.2023.2 (win64) Build 4029153 Fri Oct 13 20:14:34 MDT 2023
-- Date        : Mon Jul 29 20:46:25 2024
-- Host        : ItsMrJkali21 running 64-bit major release  (build 9200)
-- Command     : write_vhdl -force -mode synth_stub -rename_top mux41_ip_mux21_0_2 -prefix
--               mux41_ip_mux21_0_2_ mux41_ip_mux21_0_0_stub.vhdl
-- Design      : mux41_ip_mux21_0_0
-- Purpose     : Stub declaration of top-level module interface
-- Device      : xc7z020clg484-1
-- --------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity mux41_ip_mux21_0_2 is
  Port ( 
    sel : in STD_LOGIC;
    I0 : in STD_LOGIC;
    I1 : in STD_LOGIC;
    O : out STD_LOGIC
  );

end mux41_ip_mux21_0_2;

architecture stub of mux41_ip_mux21_0_2 is
attribute syn_black_box : boolean;
attribute black_box_pad_pin : string;
attribute syn_black_box of stub : architecture is true;
attribute black_box_pad_pin of stub : architecture is "sel,I0,I1,O";
attribute X_CORE_INFO : string;
attribute X_CORE_INFO of stub : architecture is "mux21,Vivado 2023.2";
begin
end;
