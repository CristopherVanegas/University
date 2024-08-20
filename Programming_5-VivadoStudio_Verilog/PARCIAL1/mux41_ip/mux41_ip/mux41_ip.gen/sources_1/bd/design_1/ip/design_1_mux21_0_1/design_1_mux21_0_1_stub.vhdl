-- Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
-- Copyright 2022-2023 Advanced Micro Devices, Inc. All Rights Reserved.
-- --------------------------------------------------------------------------------
-- Tool Version: Vivado v.2023.2 (win64) Build 4029153 Fri Oct 13 20:14:34 MDT 2023
-- Date        : Wed Jul 24 21:02:32 2024
-- Host        : smb_d2_26 running 64-bit major release  (build 9200)
-- Command     : write_vhdl -force -mode synth_stub -rename_top design_1_mux21_0_1 -prefix
--               design_1_mux21_0_1_ design_1_mux21_0_0_stub.vhdl
-- Design      : design_1_mux21_0_0
-- Purpose     : Stub declaration of top-level module interface
-- Device      : xc7z020clg484-1
-- --------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity design_1_mux21_0_1 is
  Port ( 
    i0 : in STD_LOGIC;
    i1 : in STD_LOGIC;
    sel : in STD_LOGIC;
    \out\ : out STD_LOGIC
  );

end design_1_mux21_0_1;

architecture stub of design_1_mux21_0_1 is
attribute syn_black_box : boolean;
attribute black_box_pad_pin : string;
attribute syn_black_box of stub : architecture is true;
attribute black_box_pad_pin of stub : architecture is "i0,i1,sel,\out\";
attribute X_CORE_INFO : string;
attribute X_CORE_INFO of stub : architecture is "mux21,Vivado 2023.2";
begin
end;
