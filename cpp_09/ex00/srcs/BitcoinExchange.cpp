#include "../header/BitcoinExchange.hpp"

void	set_map(const std::fstream& data_base) {

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
