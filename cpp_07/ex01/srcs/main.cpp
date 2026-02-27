#include "../header/iter.hpp"
#include <iostream>
#include <string>

// Test functions for different types
void printInt(const int& n) {
	std::cout << n << " ";
}

void printString(const std::string& s) {
	std::cout << "\"" << s << "\" ";
}

void printChar(const char& c) {
	std::cout << "'" << c << "' ";
}

void printDouble(const double& d) {
	std::cout << d << " ";
}

// Functions that modify values (for non-const version)
void doubleInt(int& n) {
	n *= 2;
}

void toUpperChar(char& c) {
	if (c >= 'a' && c <= 'z')
		c = c - 'a' + 'A';
}

void negateDouble(double& d) {
	d = -d;
}

void appendExclamation(std::string& s) {
	s += "!";
}

// Template function to test
template<typename T>
void printElement(const T& element) {
	std::cout << element << " ";
}

int main() {
	std::cout << "========================================\n";
	std::cout << "      Template iter() Function Test\n";
	std::cout << "========================================\n\n";

	// Test with integers (const version)
	std::cout << "--- Integer Array (const version) ---\n";
	const int intArray[] = {1, 2, 3, 4, 5};
	size_t intSize = sizeof(intArray) / sizeof(intArray[0]);
	std::cout << "Original: ";
	::iter(intArray, intSize, printInt);
	std::cout << std::endl;
	
	// Test with integers (non-const version)
	std::cout << "\n--- Integer Array (non-const version) ---\n";
	int modifiableIntArray[] = {10, 20, 30, 40, 50};
	std::cout << "Before doubling: ";
	::iter(modifiableIntArray, intSize, printInt);
	std::cout << std::endl;
	::iter(modifiableIntArray, intSize, doubleInt);
	std::cout << "After doubling:  ";
	::iter(modifiableIntArray, intSize, printInt);
	std::cout << std::endl;

	// Test with strings
	std::cout << "\n--- String Array ---\n";
	const std::string stringArray[] = {"hello", "world", "template", "test"};
	size_t stringSize = sizeof(stringArray) / sizeof(stringArray[0]);
	std::cout << "Strings: ";
	::iter(stringArray, stringSize, printString);
	std::cout << std::endl;

	// Test with modifiable strings
	std::cout << "\n--- Modifiable String Array ---\n";
	std::string modStringArray[] = {"cpp", "is", "great"};
	size_t modStringSize = sizeof(modStringArray) / sizeof(modStringArray[0]);
	std::cout << "Before: ";
	::iter(modStringArray, modStringSize, printString);
	std::cout << std::endl;
	::iter(modStringArray, modStringSize, appendExclamation);
	std::cout << "After:  ";
	::iter(modStringArray, modStringSize, printString);
	std::cout << std::endl;

	// Test with characters
	std::cout << "\n--- Character Array ---\n";
	char charArray[] = {'a', 'b', 'c', 'd', 'e'};
	size_t charSize = sizeof(charArray) / sizeof(charArray[0]);
	std::cout << "Before uppercase: ";
	::iter(charArray, charSize, printChar);
	std::cout << std::endl;
	::iter(charArray, charSize, toUpperChar);
	std::cout << "After uppercase:  ";
	::iter(charArray, charSize, printChar);
	std::cout << std::endl;

	// Test with doubles
	std::cout << "\n--- Double Array ---\n";
	double doubleArray[] = {1.1, 2.2, 3.3, 4.4};
	size_t doubleSize = sizeof(doubleArray) / sizeof(doubleArray[0]);
	std::cout << "Before negation: ";
	::iter(doubleArray, doubleSize, printDouble);
	std::cout << std::endl;
	::iter(doubleArray, doubleSize, negateDouble);
	std::cout << "After negation:  ";
	::iter(doubleArray, doubleSize, printDouble);
	std::cout << std::endl;

	// Test with template function
	std::cout << "\n--- Template Function Test ---\n";
	const int templateTestArray[] = {100, 200, 300};
	size_t templateSize = sizeof(templateTestArray) / sizeof(templateTestArray[0]);
	std::cout << "Using template function: ";
	::iter(templateTestArray, templateSize, printElement<int>);
	std::cout << std::endl;

	// Edge case: empty array (size = 0)
	std::cout << "\n--- Edge Case: Empty Array ---\n";
	int* emptyArray = NULL;
	std::cout << "Empty array (should print nothing): ";
	::iter(emptyArray, 0, printInt);
	std::cout << "Done.\n";

	// Edge case: single element
	std::cout << "\n--- Edge Case: Single Element ---\n";
	const int singleElement[] = {42};
	std::cout << "Single element: ";
	::iter(singleElement, 1, printInt);
	std::cout << std::endl;

	std::cout << "\n========================================\n";
	return 0;
}
