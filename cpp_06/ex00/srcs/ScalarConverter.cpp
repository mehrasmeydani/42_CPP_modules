#include "../header/ScalarConverter.hpp"
#include <iostream>
#include <cstdlib>
#include <climits>
#include <iomanip>
#include <errno.h>

enum Type {
	UNKOWN,
	INT,
	FLOAT,
	DOUBLE,
	PSUEDOF,
	PSUEDO,
	EMPTY
};

static Type check_psuedo(std::string in) {
	if (in == "inf" || in == "+inf" || in == "-inf"
		|| in == "nan")
		return PSUEDO;
	if (in == "inff" || in == "+inff" || in == "-inff"
		|| in == "nanf")
		return PSUEDOF;
	return UNKOWN;
}


static Type check_int(std::string in) {
	size_t	i = 0;
	if (in[i] == '-' || in[i] == '+')
		i++;
	for(;in[i] ;i++)
		if (in[i] > '9' || in[i] < '0')
			return UNKOWN;
	return INT;
}

static Type check_frac(std::string in) {
	size_t i = 0;
	size_t	len = in.length();
	bool	pers = 0;
	bool	f = 0;
	if (in[i] == '-' || in[i] == '+')
		i++;
	for(;in[i] ;i++)
	{
		if (in[i] > '9' || in[i] < '0')
		{
			if (in[i] == '.' && pers == 0 && i != 0 && i + 1 != len && in[i + 1] >= '0' && in[i + 1] <= '9')
				pers = 1;
			else if (in[i] == 'f' && i + 1 == len && f == 0 && pers == 1)
				f = 1;
			else
				return UNKOWN;
		}
	}
	if (f == 1)
		return FLOAT;
	return DOUBLE;
}

static Type	parser(std::string in) {
	size_t	i = 0;
	enum Type out;

	if (!in[i] || (in.length() == 1 && (in[i] == '+' || in[i] == '-')))
		return EMPTY;
	if ((out = check_psuedo(in)) != 0)
		return out;
	if ((out = check_int(in)) != 0)
		return out;
	if ((out = check_frac(in)) != 0)
		return out;
	return UNKOWN;
}

static void	print_char(double d, const enum Type& t) {
	std::cout << "char: ";
	if (d > 127 || d < 0 || t == PSUEDO || t == PSUEDOF)
		std::cout << "impossible\n";
	else if (d < 33 || d == 127)
		std::cout << "Non displayable\n";
	else
		std::cout << static_cast<unsigned char>(d) << std::endl;
}

static void print_int(double d, const enum Type& t) {
	std::cout << "int: ";
	if (t == PSUEDO || t == PSUEDOF || d > INT_MAX || d < INT_MIN)
		std::cout << "impossible\n";
	else
		std::cout << static_cast<int>(d) << std::endl;
}

static void print_float(double d, const std::string& in, const enum Type& t) {
	std::cout << "float: ";
	if (t == PSUEDO)
		std::cout << in << "f\n";
	else if (t == PSUEDOF)
	 	std::cout << in << std::endl;
	else
		std::cout << std::fixed << std::setprecision(1) << static_cast<float>(d) << "f\n";
}

static void print_double(double d, const std::string& in, const enum Type& t) {
	std::cout << "double: ";
	if (t == PSUEDO)
		std::cout << in << std::endl;
	else if (t == PSUEDOF)
	 	std::cout << in.substr(0, in.length() - 1) << std::endl;
	else
		std::cout << std::fixed << std::setprecision(1) << d << std::endl;
}

static void printer(double d, const std::string& in, const enum Type& t) {
	print_char(d, t);
	print_int(d, t);
	print_float(d, in, t);
	print_double(d, in, t);
	(void)in;
}

void	ScalarConverter::convert(const std::string in) {
	char	*end;
	enum Type out = parser(in);
	errno = 0;
	double	d = std::strtod(in.c_str(), &end);
	if (errno == ERANGE || out == EMPTY || out == UNKOWN)
	{
		std::cout << "char: impossible\n";
		std::cout << "int: impossible\n";
		std::cout << "float: impossible\n";
		std::cout << "double: impossible\n";
		return ;
	}
	errno = 0;
	std::strtof(in.c_str(), &end);
	if (errno == ERANGE)
	{
		std::cout << "char: impossible\n";
		std::cout << "int: impossible\n";
		std::cout << "float: impossible\n";
		print_double(d, in, out);
		return ;
	}
	printer(d, in, out);
}

ScalarConverter::ScalarConverter(void) {}

ScalarConverter::ScalarConverter(const ScalarConverter& in) {(void)in;}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter& in) {
	(void)in;
	return (*this);
}

ScalarConverter::~ScalarConverter(void) {}
