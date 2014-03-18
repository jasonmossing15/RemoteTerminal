----------------------------------------------------------------------------------
-- Engineer: Jason Mossing
-- Create Date:    08:26:07 03/17/2014 
-- Module Name:    ascii_to_nibble - Behavioral 
----------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx primitives in this code.
library UNISIM;
use UNISIM.VComponents.all;

entity ascii_to_nibble is
    Port ( ascii : in  STD_LOGIC_VECTOR (7 downto 0);
           nibble : out  STD_LOGIC_VECTOR (3 downto 0));
end ascii_to_nibble;

architecture Behavioral of ascii_to_nibble is

begin
	with ascii select
	nibble <= "0000" when x"30",
				 "0001" when x"31",
				 "0010" when x"32",
				 "0011" when x"33",
				 "0100" when x"34",
				 "0101" when x"35",
				 "0110" when x"36",
				 "0111" when x"37",
				 "1000" when x"38",
				 "1001" when x"39",
				 "1010" when x"41",
				 "1011" when x"42",
				 "1100" when x"43",
				 "1101" when x"44",
				 "1110" when x"45",
				 "1111" when others;
	


end Behavioral;

