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
		void	set_map(std::ifstream &data_base);
		void	print_data(std::ifstream &input_data) const;
};

void	print_error(const std::string& err);
