#pragma once

#include <string>

class ScalarConverter {
	private:
		ScalarConverter(void);
		ScalarConverter(const ScalarConverter& in);
		ScalarConverter& operator=(const ScalarConverter& in);
		~ScalarConverter();
	public:
		static void convert(const std::string in);
};


