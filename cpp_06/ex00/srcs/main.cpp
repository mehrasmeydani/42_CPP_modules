#include "../header/ScalarConverter.hpp"
#include <iostream>
#include <sstream>
#include <string>
#include <cstring>

static int g_passed = 0;
static int g_failed = 0;
static bool g_verbose = false;

static std::string captureOutput(const std::string& input) {
	std::ostringstream buffer;
	std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf());
	ScalarConverter::convert(input);
	std::cout.rdbuf(oldCout);
	return buffer.str();
}

static void assertConvert(const std::string& input,
						  const std::string& expectedChar,
						  const std::string& expectedInt,
						  const std::string& expectedFloat,
						  const std::string& expectedDouble) {
	std::string output = captureOutput(input);
	std::string expected = "char: " + expectedChar + "\n"
						 + "int: " + expectedInt + "\n"
						 + "float: " + expectedFloat + "\n"
						 + "double: " + expectedDouble + "\n";

	if (output == expected) {
			std::cout << "\033[32m[PASS]\033[0m \"" << input << "\"\n";
		if (g_verbose) {
			std::istringstream outStream(output);
			std::string line;
			while (std::getline(outStream, line))
				std::cout << "    " << line << "\n";
		}
		g_passed++;
	} else {
		std::cout << "\033[31m[FAIL]\033[0m \"" << input << "\"\n";
		if (g_verbose) {
			std::cout << "  Expected:\n";
			std::istringstream expStream(expected);
			std::string line;
			while (std::getline(expStream, line))
				std::cout << "    " << line << "\n";
			std::cout << "  Got:\n";
			std::istringstream gotStream(output);
			while (std::getline(gotStream, line))
				std::cout << "    " << line << "\n";
		}
		g_failed++;
	}
}

static void runUnitTests() {
	std::cout << "========== INTEGER TESTS ==========\n";
	assertConvert("0", "Non displayable", "0", "0.0f", "0.0");
	assertConvert("42", "*", "42", "42.0f", "42.0");
	assertConvert("-42", "impossible", "-42", "-42.0f", "-42.0");
	assertConvert("+42", "*", "42", "42.0f", "42.0");
	assertConvert("2147483647", "impossible", "2147483647", "2147483648.0f", "2147483647.0");
	assertConvert("-2147483648", "impossible", "-2147483648", "-2147483648.0f", "-2147483648.0");
	assertConvert("2147483648", "impossible", "impossible", "2147483648.0f", "2147483648.0");
	assertConvert("-2147483649", "impossible", "impossible", "-2147483648.0f", "-2147483649.0");

	std::cout << "\n========== FLOAT TESTS ==========\n";
	assertConvert("0.0f", "Non displayable", "0", "0.0f", "0.0");
	assertConvert("42.0f", "*", "42", "42.0f", "42.0");
	assertConvert("-42.0f", "impossible", "-42", "-42.0f", "-42.0");
	assertConvert("4.2f", "Non displayable", "4", "4.2f", "4.2");
	assertConvert("-4.2f", "impossible", "-4", "-4.2f", "-4.2");
	assertConvert("0.5f", "Non displayable", "0", "0.5f", "0.5");

	std::cout << "\n========== DOUBLE TESTS ==========\n";
	assertConvert("0.0", "Non displayable", "0", "0.0f", "0.0");
	assertConvert("42.0", "*", "42", "42.0f", "42.0");
	assertConvert("-42.0", "impossible", "-42", "-42.0f", "-42.0");
	assertConvert("4.2", "Non displayable", "4", "4.2f", "4.2");
	assertConvert("-4.2", "impossible", "-4", "-4.2f", "-4.2");

	std::cout << "\n========== PSEUDO-LITERALS ==========\n";
	assertConvert("nan", "impossible", "impossible", "nanf", "nan");
	assertConvert("nanf", "impossible", "impossible", "nanf", "nan");
	assertConvert("inf", "impossible", "impossible", "inff", "inf");
	assertConvert("+inf", "impossible", "impossible", "+inff", "+inf");
	assertConvert("-inf", "impossible", "impossible", "-inff", "-inf");
	assertConvert("inff", "impossible", "impossible", "inff", "inf");
	assertConvert("+inff", "impossible", "impossible", "+inff", "+inf");
	assertConvert("-inff", "impossible", "impossible", "-inff", "-inf");

	std::cout << "\n========== CHAR RANGE TESTS ==========\n";
	assertConvert("65", "A", "65", "65.0f", "65.0");
	assertConvert("97", "a", "97", "97.0f", "97.0");
	assertConvert("48", "0", "48", "48.0f", "48.0");
	assertConvert("32", "Non displayable", "32", "32.0f", "32.0");
	assertConvert("127", "Non displayable", "127", "127.0f", "127.0");
	assertConvert("128", "impossible", "128", "128.0f", "128.0");

	std::cout << "\n========== CHAR IMPOSSIBLE CASES ==========\n";
	assertConvert("-1", "impossible", "-1", "-1.0f", "-1.0");           // negative (below 0)
	assertConvert("-128", "impossible", "-128", "-128.0f", "-128.0");   // negative
	assertConvert("200", "impossible", "200", "200.0f", "200.0");       // above 127
	assertConvert("255", "impossible", "255", "255.0f", "255.0");       // above 127
	assertConvert("1000", "impossible", "1000", "1000.0f", "1000.0");   // way above 127

	std::cout << "\n========== INT IMPOSSIBLE CASES ==========\n";
	assertConvert("2147483648", "impossible", "impossible", "2147483648.0f", "2147483648.0");     // INT_MAX + 1
	assertConvert("-2147483649", "impossible", "impossible", "-2147483648.0f", "-2147483649.0"); // INT_MIN - 1
	assertConvert("9999999999", "impossible", "impossible", "10000000000.0f", "9999999999.0");     // large positive
	assertConvert("-9999999999", "impossible", "impossible", "-10000000000.0f", "-9999999999.0"); // large negative
	assertConvert("99999999999999", "impossible", "impossible", "100000000376832.0f", "99999999999999.0"); // very large

	std::cout << "\n========== EDGE CASES (INVALID) ==========\n";
	assertConvert("", "impossible", "impossible", "impossible", "impossible");
	assertConvert("abc", "impossible", "impossible", "impossible", "impossible");
	assertConvert("42abc", "impossible", "impossible", "impossible", "impossible");
	assertConvert("42.42.42", "impossible", "impossible", "impossible", "impossible");
	assertConvert("--42", "impossible", "impossible", "impossible", "impossible");
	assertConvert("++42", "impossible", "impossible", "impossible", "impossible");
	assertConvert(".", "impossible", "impossible", "impossible", "impossible");
	assertConvert(".5", "impossible", "impossible", "impossible", "impossible");
	assertConvert("5.", "impossible", "impossible", "impossible", "impossible");
	assertConvert("f", "impossible", "impossible", "impossible", "impossible");
	assertConvert(".f", "impossible", "impossible", "impossible", "impossible");
	assertConvert("5.f", "impossible", "impossible", "impossible", "impossible");
	assertConvert(".5f", "impossible", "impossible", "impossible", "impossible");
	assertConvert("5..5", "impossible", "impossible", "impossible", "impossible");
	assertConvert("5.5.5f", "impossible", "impossible", "impossible", "impossible");
	assertConvert("hello", "impossible", "impossible", "impossible", "impossible");
	assertConvert("42f", "impossible", "impossible", "impossible", "impossible");  // missing decimal
	assertConvert("42.f", "impossible", "impossible", "impossible", "impossible"); // no digit after decimal
	assertConvert("-", "impossible", "impossible", "impossible", "impossible");
	assertConvert("+", "impossible", "impossible", "impossible", "impossible");
	assertConvert("+-42", "impossible", "impossible", "impossible", "impossible");
	assertConvert("-+42", "impossible", "impossible", "impossible", "impossible");
	assertConvert("4-2", "impossible", "impossible", "impossible", "impossible");
	assertConvert("4+2", "impossible", "impossible", "impossible", "impossible");
	assertConvert("4.2.f", "impossible", "impossible", "impossible", "impossible");
	assertConvert("ff", "impossible", "impossible", "impossible", "impossible");
	assertConvert("4.2ff", "impossible", "impossible", "impossible", "impossible");
	assertConvert(" ", "impossible", "impossible", "impossible", "impossible");
	assertConvert(" 42", "impossible", "impossible", "impossible", "impossible");
	assertConvert("42 ", "impossible", "impossible", "impossible", "impossible");
	assertConvert("4 2", "impossible", "impossible", "impossible", "impossible");

	std::cout << "\n========== FLOAT OVERFLOW (only float impossible) ==========\n";
	assertConvert("3402823500000000000000000000000000000000.0f", "impossible", "impossible", "impossible", "3402823499999999917547887437814326886400.0");

	std::cout << "\n========== DOUBLE OVERFLOW (all impossible) ==========\n";
	assertConvert("1797693134862315708145274237317043570000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000.0", "impossible", "impossible", "impossible", "impossible");

	std::cout << "\n==========================================\n";
	std::cout << "Results: \033[32m" << g_passed << " passed\033[0m, \033[31m" << g_failed << " failed\033[0m\n";
	if (g_failed == 0)
		std::cout << "\033[32mAll tests passed!\033[0m\n";
}

// static void manualTest(const std::string& input) {
// 	std::cout << "===== Testing: \"" << input << "\" =====\n";
// 	ScalarConverter::convert(input);
// 	std::cout << std::endl;
// }

int main(int argc, char **argv)
{
	if (argc == 2) {
		ScalarConverter::convert(argv[1]);
	} else if (argc == 3 && std::strcmp(argv[1], "test") == 0) {
		if (std::strcmp(argv[2], "verbose") == 0)
			g_verbose = true;
		runUnitTests();
	} else {
		std::cerr << "Usage: " << argv[0] << " [value]\n";
		std::cerr << "       " << argv[0] << " test unit  - run unit tests (pass/fail only)\n";
		std::cerr << "       " << argv[0] << " test verbose  - run unit tests with output\n";
		return 1;
	}
	return g_failed > 0 ? 1 : 0;
}