#pragma once
#include <map>
#include <fstream>
#include <iostream>

class BitcoinExchange {
	private:
		BitcoinExchange(const BitcoinExchange& in);
		BitcoinExchange& operator=(const BitcoinExchange& in);
		std::map<int, double> btc;
	public:
		BitcoinExchange(void);
		~BitcoinExchange();
		void	set_map(const std::fstream &data_base);
		void	print_data(const std::fstream &input_data) const;
};

void	print_error(const std::string& err);
