-- Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
-- Copyright 2022-2023 Advanced Micro Devices, Inc. All Rights Reserved.
-- --------------------------------------------------------------------------------
-- Tool Version: Vivado v.2023.2 (win64) Build 4029153 Fri Oct 13 20:14:34 MDT 2023
-- Date        : Mon Jul 29 21:00:38 2024
-- Host        : ItsMrJkali21 running 64-bit major release  (build 9200)
-- Command     : write_vhdl -force -mode synth_stub
--               c:/Users/usuario/Desktop/PROV_WS/MODULOS_IP/mux81/mux81.gen/sources_1/bd/mux81/ip/mux81_mux21_0_1/mux81_mux21_0_1_stub.vhdl
-- Design      : mux81_mux21_0_1
-- Purpose     : Stub declaration of top-level module interface
-- Device      : xc7z020clg484-1
-- --------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity mux81_mux21_0_1 is
  Port ( 
    sel : in STD_LOGIC;
    I0 : in STD_LOGIC;
    I1 : in STD_LOGIC;
    O : out STD_LOGIC
  );

end mux81_mux21_0_1;

architecture stub of mux81_mux21_0_1 is
attribute syn_black_box : boolean;
attribute black_box_pad_pin : string;
attribute syn_black_box of stub : architecture is true;
attribute black_box_pad_pin of stub : architecture is "sel,I0,I1,O";
attribute X_CORE_INFO : string;
attribute X_CORE_INFO of stub : architecture is "mux21,Vivado 2023.2";
begin
end;