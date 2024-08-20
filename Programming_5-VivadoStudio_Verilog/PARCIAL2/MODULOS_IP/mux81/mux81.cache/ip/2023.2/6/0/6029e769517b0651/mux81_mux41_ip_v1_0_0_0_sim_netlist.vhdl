-- Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
-- Copyright 2022-2023 Advanced Micro Devices, Inc. All Rights Reserved.
-- --------------------------------------------------------------------------------
-- Tool Version: Vivado v.2023.2 (win64) Build 4029153 Fri Oct 13 20:14:34 MDT 2023
-- Date        : Mon Jul 29 21:01:46 2024
-- Host        : ItsMrJkali21 running 64-bit major release  (build 9200)
-- Command     : write_vhdl -force -mode funcsim -rename_top decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix -prefix
--               decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix_ mux81_mux41_ip_v1_0_0_0_sim_netlist.vhdl
-- Design      : mux81_mux41_ip_v1_0_0_0
-- Purpose     : This VHDL netlist is a functional simulation representation of the design and should not be modified or
--               synthesized. This netlist cannot be used for SDF annotated simulation.
-- Device      : xc7z020clg484-1
-- --------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
library UNISIM;
use UNISIM.VCOMPONENTS.ALL;
entity decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix_mux41_ip_mux21_0_0 is
  port (
    sel : in STD_LOGIC;
    I0 : in STD_LOGIC;
    I1 : in STD_LOGIC;
    O : out STD_LOGIC
  );
  attribute CHECK_LICENSE_TYPE : string;
  attribute CHECK_LICENSE_TYPE of decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix_mux41_ip_mux21_0_0 : entity is "mux41_ip_mux21_0_0,mux21,{}";
  attribute DowngradeIPIdentifiedWarnings : string;
  attribute DowngradeIPIdentifiedWarnings of decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix_mux41_ip_mux21_0_0 : entity is "yes";
  attribute IP_DEFINITION_SOURCE : string;
  attribute IP_DEFINITION_SOURCE of decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix_mux41_ip_mux21_0_0 : entity is "package_project";
  attribute X_CORE_INFO : string;
  attribute X_CORE_INFO of decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix_mux41_ip_mux21_0_0 : entity is "mux21,Vivado 2023.2";
end decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix_mux41_ip_mux21_0_0;

architecture STRUCTURE of decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix_mux41_ip_mux21_0_0 is
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
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
library UNISIM;
use UNISIM.VCOMPONENTS.ALL;
entity decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix_mux41_ip_mux21_0_1 is
  port (
    sel : in STD_LOGIC;
    I0 : in STD_LOGIC;
    I1 : in STD_LOGIC;
    O : out STD_LOGIC
  );
  attribute CHECK_LICENSE_TYPE : string;
  attribute CHECK_LICENSE_TYPE of decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix_mux41_ip_mux21_0_1 : entity is "mux41_ip_mux21_0_1,mux21,{}";
  attribute DowngradeIPIdentifiedWarnings : string;
  attribute DowngradeIPIdentifiedWarnings of decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix_mux41_ip_mux21_0_1 : entity is "yes";
  attribute IP_DEFINITION_SOURCE : string;
  attribute IP_DEFINITION_SOURCE of decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix_mux41_ip_mux21_0_1 : entity is "package_project";
  attribute X_CORE_INFO : string;
  attribute X_CORE_INFO of decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix_mux41_ip_mux21_0_1 : entity is "mux21,Vivado 2023.2";
end decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix_mux41_ip_mux21_0_1;

architecture STRUCTURE of decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix_mux41_ip_mux21_0_1 is
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
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
library UNISIM;
use UNISIM.VCOMPONENTS.ALL;
entity decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix_mux41_ip_mux21_0_2 is
  port (
    sel : in STD_LOGIC;
    I0 : in STD_LOGIC;
    I1 : in STD_LOGIC;
    O : out STD_LOGIC
  );
  attribute CHECK_LICENSE_TYPE : string;
  attribute CHECK_LICENSE_TYPE of decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix_mux41_ip_mux21_0_2 : entity is "mux41_ip_mux21_0_2,mux21,{}";
  attribute DowngradeIPIdentifiedWarnings : string;
  attribute DowngradeIPIdentifiedWarnings of decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix_mux41_ip_mux21_0_2 : entity is "yes";
  attribute IP_DEFINITION_SOURCE : string;
  attribute IP_DEFINITION_SOURCE of decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix_mux41_ip_mux21_0_2 : entity is "package_project";
  attribute X_CORE_INFO : string;
  attribute X_CORE_INFO of decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix_mux41_ip_mux21_0_2 : entity is "mux21,Vivado 2023.2";
end decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix_mux41_ip_mux21_0_2;

architecture STRUCTURE of decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix_mux41_ip_mux21_0_2 is
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
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
library UNISIM;
use UNISIM.VCOMPONENTS.ALL;
entity decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix_mux41_ip is
  port (
    sout_0 : out STD_LOGIC;
    i0 : in STD_LOGIC;
    i1 : in STD_LOGIC;
    S1 : in STD_LOGIC;
    i2 : in STD_LOGIC;
    i3 : in STD_LOGIC;
    S2 : in STD_LOGIC
  );
end decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix_mux41_ip;

architecture STRUCTURE of decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix_mux41_ip is
  signal mux21_0_O : STD_LOGIC;
  signal mux21_1_O : STD_LOGIC;
  attribute CHECK_LICENSE_TYPE : string;
  attribute CHECK_LICENSE_TYPE of mux21_0 : label is "mux41_ip_mux21_0_0,mux21,{}";
  attribute DowngradeIPIdentifiedWarnings : string;
  attribute DowngradeIPIdentifiedWarnings of mux21_0 : label is "yes";
  attribute IP_DEFINITION_SOURCE : string;
  attribute IP_DEFINITION_SOURCE of mux21_0 : label is "package_project";
  attribute X_CORE_INFO : string;
  attribute X_CORE_INFO of mux21_0 : label is "mux21,Vivado 2023.2";
  attribute CHECK_LICENSE_TYPE of mux21_1 : label is "mux41_ip_mux21_0_1,mux21,{}";
  attribute DowngradeIPIdentifiedWarnings of mux21_1 : label is "yes";
  attribute IP_DEFINITION_SOURCE of mux21_1 : label is "package_project";
  attribute X_CORE_INFO of mux21_1 : label is "mux21,Vivado 2023.2";
  attribute CHECK_LICENSE_TYPE of mux21_2 : label is "mux41_ip_mux21_0_2,mux21,{}";
  attribute DowngradeIPIdentifiedWarnings of mux21_2 : label is "yes";
  attribute IP_DEFINITION_SOURCE of mux21_2 : label is "package_project";
  attribute X_CORE_INFO of mux21_2 : label is "mux21,Vivado 2023.2";
begin
mux21_0: entity work.decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix_mux41_ip_mux21_0_0
     port map (
      I0 => i1,
      I1 => S1,
      O => mux21_0_O,
      sel => i0
    );
mux21_1: entity work.decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix_mux41_ip_mux21_0_1
     port map (
      I0 => i3,
      I1 => S1,
      O => mux21_1_O,
      sel => i2
    );
mux21_2: entity work.decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix_mux41_ip_mux21_0_2
     port map (
      I0 => mux21_1_O,
      I1 => S2,
      O => sout_0,
      sel => mux21_0_O
    );
end STRUCTURE;
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
library UNISIM;
use UNISIM.VCOMPONENTS.ALL;
entity decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix_mux41_ip_wrapper is
  port (
    sout_0 : out STD_LOGIC;
    i0 : in STD_LOGIC;
    i1 : in STD_LOGIC;
    S1 : in STD_LOGIC;
    i2 : in STD_LOGIC;
    i3 : in STD_LOGIC;
    S2 : in STD_LOGIC
  );
end decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix_mux41_ip_wrapper;

architecture STRUCTURE of decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix_mux41_ip_wrapper is
begin
mux41_ip_i: entity work.decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix_mux41_ip
     port map (
      S1 => S1,
      S2 => S2,
      i0 => i0,
      i1 => i1,
      i2 => i2,
      i3 => i3,
      sout_0 => sout_0
    );
end STRUCTURE;
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
library UNISIM;
use UNISIM.VCOMPONENTS.ALL;
entity decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix is
  port (
    S1 : in STD_LOGIC;
    S2 : in STD_LOGIC;
    i0 : in STD_LOGIC;
    i1 : in STD_LOGIC;
    i2 : in STD_LOGIC;
    i3 : in STD_LOGIC;
    sout_0 : out STD_LOGIC
  );
  attribute NotValidForBitStream : boolean;
  attribute NotValidForBitStream of decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix : entity is true;
  attribute CHECK_LICENSE_TYPE : string;
  attribute CHECK_LICENSE_TYPE of decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix : entity is "mux81_mux41_ip_v1_0_0_0,mux41_ip_wrapper,{}";
  attribute DowngradeIPIdentifiedWarnings : string;
  attribute DowngradeIPIdentifiedWarnings of decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix : entity is "yes";
  attribute IP_DEFINITION_SOURCE : string;
  attribute IP_DEFINITION_SOURCE of decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix : entity is "package_project";
  attribute X_CORE_INFO : string;
  attribute X_CORE_INFO of decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix : entity is "mux41_ip_wrapper,Vivado 2023.2";
end decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix;

architecture STRUCTURE of decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix is
begin
inst: entity work.decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix_mux41_ip_wrapper
     port map (
      S1 => S1,
      S2 => S2,
      i0 => i0,
      i1 => i1,
      i2 => i2,
      i3 => i3,
      sout_0 => sout_0
    );
end STRUCTURE;
