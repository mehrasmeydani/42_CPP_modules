#include "../header/BitcoinExchange.hpp"
#include <cstdio>
#include <iostream>
#include <stdexcept>
#include <string>

void	BitcoinExchange::set_map(std::ifstream& data_base) {
	std::string buffer;
	std::string	date;
	double value;
	std::getline(data_base, buffer);
	if (data_base.eof())
		throw std::runtime_error("Data Base empty");
	if (buffer.compare("date | value"))
		throw std::runtime_error("Invalid First Line");
	while (std::getline(data_base, buffer))
	{

	}

}

BitcoinExchange::BitcoinExchange(void) {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& in) {(void)in;}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange& in) {
	(void)in;
	return (*this);
}

BitcoinExchange::~BitcoinExchange(void) {}

void print_error(const std::string &err) {
	std::cerr << err << std::endl;
}
