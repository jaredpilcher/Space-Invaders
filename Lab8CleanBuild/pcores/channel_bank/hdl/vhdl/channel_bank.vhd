library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;
use ieee.numeric_std.all;		

entity channel_bank is
  port
  (
    clk      : in std_logic;
	chan_sel_in : in std_logic_vector(0 to 2);
	addr_we	 : in std_logic;
	length_we: in std_logic;
	data_in  : in std_logic_vector(0 to 31);
	addr_out : out std_logic_vector(0 to 31);
	length_out:out std_logic_vector(0 to 31)
  );
  
end entity channel_bank;

architecture chanBank of channel_bank is
	--channel 0
	signal cur_chan_length0, next_chan_length0: std_logic_vector(0 to 31);
	signal cur_chan_addr0, next_chan_addr0: std_logic_vector(0 to 31);
	--channel 1
	signal cur_chan_length1, next_chan_length1: std_logic_vector(0 to 31);
	signal cur_chan_addr1, next_chan_addr1: std_logic_vector(0 to 31);
	--channel 2
	signal cur_chan_length2, next_chan_length2: std_logic_vector(0 to 31);
	signal cur_chan_addr2, next_chan_addr2: std_logic_vector(0 to 31);
	--channel 3
	signal cur_chan_length3, next_chan_length3: std_logic_vector(0 to 31);
	signal cur_chan_addr3, next_chan_addr3: std_logic_vector(0 to 31);
	--channel 4
	signal cur_chan_length4, next_chan_length4: std_logic_vector(0 to 31);
	signal cur_chan_addr4, next_chan_addr4: std_logic_vector(0 to 31);
	--channel 5
	signal cur_chan_length5, next_chan_length5: std_logic_vector(0 to 31);
	signal cur_chan_addr5, next_chan_addr5: std_logic_vector(0 to 31);
	--channel 6
	signal cur_chan_length6, next_chan_length6: std_logic_vector(0 to 31);
	signal cur_chan_addr6, next_chan_addr6: std_logic_vector(0 to 31);
	--channel 7
	signal cur_chan_length7, next_chan_length7: std_logic_vector(0 to 31);
	signal cur_chan_addr7, next_chan_addr7: std_logic_vector(0 to 31);
	
begin
	process(clk)
	begin
		if(clk'event and clk='1') then
			--channel 0
			cur_chan_length0 <= next_chan_length0;
			cur_chan_addr0 <= next_chan_addr0;
			--channel 1
			cur_chan_length1 <= next_chan_length1;
			cur_chan_addr1 <= next_chan_addr1;
			--channel 2
			cur_chan_length2 <= next_chan_length2;
			cur_chan_addr2 <= next_chan_addr2;
			--channel 3
			cur_chan_length3 <= next_chan_length3;
			cur_chan_addr3 <= next_chan_addr3;
			--channel 4
			cur_chan_length4 <= next_chan_length4;
			cur_chan_addr4 <= next_chan_addr4;
			--channel 5
			cur_chan_length5 <= next_chan_length5;
			cur_chan_addr5 <= next_chan_addr5;
			--channel 6
			cur_chan_length6 <= next_chan_length6;
			cur_chan_addr6 <= next_chan_addr6;
			--channel 7
			cur_chan_length7 <= next_chan_length7;
			cur_chan_addr7 <= next_chan_addr7;
        end if;
    end process;

	--writing to registers
	process(chan_sel_in, addr_we, length_we, data_in)
	begin
		--channel 0
		next_chan_length0 <= cur_chan_length0;
		next_chan_addr0 <= cur_chan_addr0;
		--channel 1
		next_chan_length1 <= cur_chan_length1;
		next_chan_addr1 <= cur_chan_addr1;
		--channel 2
		next_chan_length2 <= cur_chan_length2;
		next_chan_addr2 <= cur_chan_addr2;
		--channel 3
		next_chan_length3 <= cur_chan_length3;
		next_chan_addr3 <= cur_chan_addr3;
		--channel 4
		next_chan_length4 <= cur_chan_length4;
		next_chan_addr4 <= cur_chan_addr4;
		--channel 5
		next_chan_length5 <= cur_chan_length5;
		next_chan_addr5 <= cur_chan_addr5;
		--channel 6
		next_chan_length6 <= cur_chan_length6;
		next_chan_addr6 <= cur_chan_addr6;
		--channel 7
		next_chan_length7 <= cur_chan_length7;
		next_chan_addr7 <= cur_chan_addr7;
		case chan_sel_in is
			when "000" =>
				addr_out <= cur_chan_addr0;
				length_out <= cur_chan_length0;
				if addr_we = '1' then
					next_chan_addr0 <= data_in;
				end if;
				if length_we = '1' then
					next_chan_length0 <= data_in;
				end if;
			when "001" =>
				addr_out <= cur_chan_addr1;
				length_out <= cur_chan_length1;
				if addr_we = '1' then
					next_chan_addr1 <= data_in;
				end if;
				if length_we = '1' then
					next_chan_length1 <= data_in;
				end if;
			when "010" =>
				addr_out <= cur_chan_addr2;
				length_out <= cur_chan_length2;
				if addr_we = '1' then
					next_chan_addr2 <= data_in;
				end if;
				if length_we = '1' then
					next_chan_length2 <= data_in;
				end if;
			when "011" =>
				addr_out <= cur_chan_addr3;
				length_out <= cur_chan_length3;
				if addr_we = '1' then
					next_chan_addr3 <= data_in;
				end if;
				if length_we = '1' then
					next_chan_length3 <= data_in;
				end if;
			when "100" =>
				addr_out <= cur_chan_addr4;
				length_out <= cur_chan_length4;
				if addr_we = '1' then
					next_chan_addr4 <= data_in;
				end if;
				if length_we = '1' then
					next_chan_length4 <= data_in;
				end if;
			when "101" =>
				addr_out <= cur_chan_addr5;
				length_out <= cur_chan_length5;
				if addr_we = '1' then
					next_chan_addr5 <= data_in;
				end if;
				if length_we = '1' then
					next_chan_length5 <= data_in;
				end if;
			when "110" =>
				addr_out <= cur_chan_addr6;
				length_out <= cur_chan_length6;
				if addr_we = '1' then
					next_chan_addr6 <= data_in;
				end if;
				if length_we = '1' then
					next_chan_length6 <= data_in;
				end if;
			when others =>
				addr_out <= cur_chan_addr7;
				length_out <= cur_chan_length7;
				if addr_we = '1' then
					next_chan_addr7 <= data_in;
				end if;
				if length_we = '1' then
					next_chan_length7 <= data_in;
				end if;
		end case;
	end process;
	

end chanBank;