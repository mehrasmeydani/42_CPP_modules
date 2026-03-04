#include "../header/BitcoinExchange.hpp"

int main(int argc, char **argv) {
	BitcoinExchange btc;
	if (argc != 2)
	{
		print_error("Use the following format:\n./btc <inputfile.csv>");
		return (1);
	}
	
}