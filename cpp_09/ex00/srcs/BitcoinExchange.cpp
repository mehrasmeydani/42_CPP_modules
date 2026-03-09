#include "../header/BitcoinExchange.hpp"
#include <cstdio>
#include <iostream>
#include <stdexcept>
#include <string>
#include <cstdlib>
#include <cerrno>
#include <cstring>

void	check_date_format(const std::string &date) {
	for (int i = 0; date[i]; i++) {
		if ((i < 4 || (i > 4 && i < 7) || (i > 7 && i < 10)) && (date[i] > '9' || date[i] < '0'))
			throw std::runtime_error("Invalid Date Format");
		else if ((i == 4 || i == 7) && date[i] != '-')
			throw std::runtime_error("Invalid Date Format");
		else if (i == 10 && date[i] != ' ')
			throw std::runtime_error("Invalid Date Format");
	}
}

void	check_date_value(int date) {
	int	number_days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (number_days[date % 10000 / 100 - 1] + ((date % 10000 / 100 == 2 && date / 10000 % 4 == 0 && (date / 10000 % 100 != 0 || date / 10000 % 400 == 0)) ? 1 : 0) < date % 100)
		throw std::runtime_error("Invalid Date");
}

int	get_date(const std::string& in) {
	int			date;
	char		*end;

	try {
		check_date_format(in.substr(0, 11));
		date = std::strtod(in.substr(0, 4).c_str(), &end);
		if (date < 1900)
			throw std::runtime_error("Invalid Date");
		date *= 100;
		date += std::strtod(in.substr(5, 2).c_str(), &end);
		if (date % 100 > 12 || !(date % 100))
			throw std::runtime_error("Invalid Date");
		date *= 100;
		date += std::strtod(in.substr(8, 2).c_str(), &end);
		if (date % 100 > 31 || !(date % 100))
			throw std::runtime_error("Invalid Date");
		check_date_value(date);
	} catch (const std::exception &e) {
		throw std::runtime_error(e.what());
	}
	return date;
}

void check_frac(const std::string& in) {
	size_t	len = in.length();
	bool	pers = 0;

	for(size_t i = 0;in[i] ;i++)
	{
		if (in[i] > '9' || in[i] < '0')
		{
			if (in[i] == '.' && pers == 0 && i != 0 && i + 1 != len && in[i + 1] >= '0' && in[i + 1] <= '9')
				pers = 1;
			else
				throw std::runtime_error("Invalid Value");
		}
	}
}


void	BitcoinExchange::set_map(std::ifstream& data_base) {
	std::string buffer;
	int			date;
	double		value;
	std::getline(data_base, buffer);
	if (data_base.eof())
		throw std::runtime_error("Data Base empty");
	if (buffer.compare("date | value"))
		throw std::runtime_error("Invalid First Line");
	while (std::getline(data_base, buffer))
	{
		try {
			date = get_date(buffer);
			if (buffer.substr(10, 3) != " | ")
				throw std::runtime_error("Invalid list format");
			check_frac(buffer.substr(13));
			errno = 0;
			value = std::strtod(buffer.substr(13).c_str(), NULL);
			if (errno != 0)
				throw std::runtime_error(std::strerror(errno));
			this->btc[date] =  value;
		} catch (const std::exception &e) {
			throw std::runtime_error(e.what());
		}
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
