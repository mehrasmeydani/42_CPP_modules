#include "../header/BitcoinExchange.hpp"
#include <cstddef>
#include <exception>
#include <fstream>
#include <iostream>
#include <ostream>
#include <string>

int main(int argc, char **argv) {
	BitcoinExchange btc;
	std::string		input_file;

	if (argc != 2)
	{
		print_error("Use the following format:\n./btc <inputfile.csv>");
		return (1);
	}
	std::ifstream	database("database.csv");
	if (!database.is_open())
	{
		print_error("Cannot open data base");
		return(1);
	}
	try {
		btc.set_map(database);
	} catch (const std::exception &e) {
		std::cerr << "Parsing database failed: \n";
		print_error(e.what());
		return (1);
	}
	input_file = argv[1];
	if (input_file.rfind(".csv", input_file.npos) != input_file.size() - 4 && input_file.size() != 4)
	{
		print_error("Input file not in .csv format");
		return (0);
	}
	std::ifstream	input(input_file.c_str());
	if (!input.is_open())
	{
		print_error("Cannot open input file");
		return(1);
	}
}