-- Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
-- Copyright 2022-2023 Advanced Micro Devices, Inc. All Rights Reserved.
-- --------------------------------------------------------------------------------
-- Tool Version: Vivado v.2023.2 (win64) Build 4029153 Fri Oct 13 20:14:34 MDT 2023
-- Date        : Mon Jul 29 20:46:25 2024
-- Host        : ItsMrJkali21 running 64-bit major release  (build 9200)
-- Command     : write_vhdl -force -mode funcsim
--               c:/Users/usuario/Desktop/PROV_WS/MODULOS_IP/mux41/mux41.gen/sources_1/bd/mux41_ip/ip/mux41_ip_mux21_0_0/mux41_ip_mux21_0_0_sim_netlist.vhdl
-- Design      : mux41_ip_mux21_0_0
-- Purpose     : This VHDL netlist is a functional simulation representation of the design and should not be modified or
--               synthesized. This netlist cannot be used for SDF annotated simulation.
-- Device      : xc7z020clg484-1
-- --------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
library UNISIM;
use UNISIM.VCOMPONENTS.ALL;
entity mux41_ip_mux21_0_0 is
  port (
    sel : in STD_LOGIC;
    I0 : in STD_LOGIC;
    I1 : in STD_LOGIC;
    O : out STD_LOGIC
  );
  attribute NotValidForBitStream : boolean;
  attribute NotValidForBitStream of mux41_ip_mux21_0_0 : entity is true;
  attribute CHECK_LICENSE_TYPE : string;
  attribute CHECK_LICENSE_TYPE of mux41_ip_mux21_0_0 : entity is "mux41_ip_mux21_0_0,mux21,{}";
  attribute DowngradeIPIdentifiedWarnings : string;
  attribute DowngradeIPIdentifiedWarnings of mux41_ip_mux21_0_0 : entity is "yes";
  attribute IP_DEFINITION_SOURCE : string;
  attribute IP_DEFINITION_SOURCE of mux41_ip_mux21_0_0 : entity is "package_project";
  attribute X_CORE_INFO : string;
  attribute X_CORE_INFO of mux41_ip_mux21_0_0 : entity is "mux21,Vivado 2023.2";
end mux41_ip_mux21_0_0;

architecture STRUCTURE of mux41_ip_mux21_0_0 is
begin
O_INST_0: unisim.vcomponents.LUT3
    generic map(
      INIT => X"B8"
    )
        port map (
      I0 => I1,
      I1 => sel,
      I2 => I0,
      O => O
    );
end STRUCTURE;
