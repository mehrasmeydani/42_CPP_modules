#include "../header/BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void) {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& in) {(void)in;}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange& in) {
	(void)in;
	return (*this);
}

BitcoinExchange::~BitcoinExchange(void) {}
