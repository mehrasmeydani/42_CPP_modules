#include "../header/Span.hpp"
#include <iostream>
#include <climits>

static int g_tests = 0;
static int g_passed = 0;

#define GREEN "\033[32m"
#define RED "\033[31m"
#define RESET "\033[0m"

#define TEST(name) \
	g_tests++;

#define ASSERT(condition) \
	if (condition) { \
		std::cout << GREEN "PASS" RESET " " << __func__ << std::endl; \
		g_passed++; \
	} else { \
		std::cout << RED "FAIL" RESET " " << __func__ << std::endl; \
	}

#define ASSERT_THROW(code, exception_type) \
	try { \
		code; \
		std::cout << RED "FAIL" RESET " " << __func__ << " (no exception)" << std::endl; \
	} catch (const exception_type&) { \
		std::cout << GREEN "PASS" RESET " " << __func__ << std::endl; \
		g_passed++; \
	}

#define ASSERT_NO_THROW(code) \
	try { \
		code; \
		std::cout << GREEN "PASS" RESET " " << __func__ << std::endl; \
		g_passed++; \
	} catch (...) { \
		std::cout << RED "FAIL" RESET " " << __func__ << " (unexpected exception)" << std::endl; \
	}

void test_constructor() {
	TEST("constructor with size");
	Span sp(5);
	ASSERT_NO_THROW(Span sp2(10));
}

void test_add_number_basic() {
	TEST("add single number");
	Span sp(3);
	ASSERT_NO_THROW(sp.addNumber(42));
	
	TEST("add multiple numbers");
	Span sp2(5);
	sp2.addNumber(1);
	sp2.addNumber(2);
	sp2.addNumber(3);
	ASSERT_NO_THROW(sp2.addNumber(4));
}

void test_add_number_overflow() {
	TEST("add number - stack overflow");
	Span sp(2);
	sp.addNumber(1);
	sp.addNumber(2);
	ASSERT_THROW(sp.addNumber(3), Span::FullStack);
}

void test_shortest_span_basic() {
	TEST("shortest span - basic case");
	Span sp(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	// Sorted: 3, 6, 9, 11, 17
	// Differences: 3, 3, 2, 6 -> shortest is 2
	ASSERT(sp.shortestSpan() == 2);
}

void test_shortest_span_two_elements() {
	TEST("shortest span - two elements");
	Span sp(2);
	sp.addNumber(10);
	sp.addNumber(15);
	ASSERT(sp.shortestSpan() == 5);
}

void test_shortest_span_duplicates() {
	TEST("shortest span - with duplicates");
	Span sp(4);
	sp.addNumber(5);
	sp.addNumber(10);
	sp.addNumber(5);
	sp.addNumber(20);
	// Sorted: 5, 5, 10, 20
	// Differences: 0, 5, 10 -> shortest is 0
	ASSERT(sp.shortestSpan() == 0);
}

void test_longest_span_basic() {
	TEST("longest span - basic case");
	Span sp(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	// Min: 3, Max: 17 -> longest span is 14
	ASSERT(sp.longestSpan() == 14);
}

void test_longest_span_two_elements() {
	TEST("longest span - two elements");
	Span sp(2);
	sp.addNumber(100);
	sp.addNumber(200);
	ASSERT(sp.longestSpan() == 100);
}

void test_longest_span_negative() {
	TEST("longest span - with negative numbers");
	Span sp(4);
	sp.addNumber(-10);
	sp.addNumber(5);
	sp.addNumber(-20);
	sp.addNumber(15);
	// Min: -20, Max: 15 -> longest span is 35
	ASSERT(sp.longestSpan() == 35);
}

void test_exceptions_too_small() {
	TEST("shortest span - empty span");
	Span sp(5);
	ASSERT_THROW(sp.shortestSpan(), Span::StackTooSmall);
	
	TEST("longest span - empty span");
	Span sp2(5);
	ASSERT_THROW(sp2.longestSpan(), Span::StackTooSmall);
	
	TEST("shortest span - single element");
	Span sp3(5);
	sp3.addNumber(42);
	ASSERT_THROW(sp3.shortestSpan(), Span::StackTooSmall);
	
	TEST("longest span - single element");
	Span sp4(5);
	sp4.addNumber(42);
	ASSERT_THROW(sp4.longestSpan(), Span::StackTooSmall);
}

void test_copy_constructor() {
	TEST("copy constructor");
	Span original(3);
	original.addNumber(1);
	original.addNumber(2);
	original.addNumber(3);
	
	Span copy(original);
	ASSERT(copy.shortestSpan() == 1 && copy.longestSpan() == 2);
}

void test_assignment_operator() {
	TEST("assignment operator");
	Span sp1(3);
	sp1.addNumber(10);
	sp1.addNumber(20);
	sp1.addNumber(30);
	
	Span sp2(1);
	sp2 = sp1;
	ASSERT(sp2.shortestSpan() == 10 && sp2.longestSpan() == 20);
}

void test_populate_method() {
	TEST("populate - shortest span works");
	Span sp(1000);
	sp.populate();
	ASSERT_NO_THROW(sp.shortestSpan());
	
	TEST("populate - longest span works");
	ASSERT_NO_THROW(sp.longestSpan());
	
	TEST("populate method - already full");
	Span sp2(2);
	sp2.addNumber(1);
	sp2.addNumber(2);
	// Should fill remaining capacity (0 in this case)
	ASSERT_NO_THROW(sp2.populate());
}

void test_extreme_values() {
	TEST("extreme values - longest span");
	Span sp(3);
	sp.addNumber(INT_MAX);
	sp.addNumber(0);
	sp.addNumber(INT_MIN);
	ASSERT_NO_THROW(sp.longestSpan());
	
	TEST("extreme values - shortest span");
	ASSERT_NO_THROW(sp.shortestSpan());
}

void test_edge_cases() {
	TEST("zero capacity span");
	Span sp(0);
	ASSERT_THROW(sp.addNumber(1), Span::FullStack);
	
	TEST("single capacity - overflow");
	Span sp2(1);
	sp2.addNumber(42);
	ASSERT_THROW(sp2.addNumber(43), Span::FullStack);
	
	TEST("single capacity - span too small");
	ASSERT_THROW(sp2.shortestSpan(), Span::StackTooSmall);
}

void test_large_span() {
	TEST("large span - shortest span");
	Span sp(10000);
	
	// Add numbers in a pattern to test performance
	for (int i = 0; i < 10000; i++) {
		sp.addNumber(i);
	}
	ASSERT(sp.shortestSpan() == 1);
	
	TEST("large span - longest span");
	ASSERT(sp.longestSpan() == 9999);
}

void test_subject_example() {
	TEST("subject example case");
	Span sp = Span(5);
	
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	
	std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	
	ASSERT(sp.shortestSpan() == 2 && sp.longestSpan() == 14);
}

int main() {
	std::cout << "========================================\n";
	std::cout << "          Span Class Unit Tests\n";
	std::cout << "========================================\n\n";
	
	test_constructor();
	test_add_number_basic();
	test_add_number_overflow();
	test_shortest_span_basic();
	test_shortest_span_two_elements();
	test_shortest_span_duplicates();
	test_longest_span_basic();
	test_longest_span_two_elements();
	test_longest_span_negative();
	test_exceptions_too_small();
	test_copy_constructor();
	test_assignment_operator();
	test_populate_method();
	test_extreme_values();
	test_edge_cases();
	test_large_span();
	
	std::cout << "\n--- Subject Example ---\n";
	test_subject_example();
	
	std::cout << "\n========================================\n";
	std::cout << "Results: " << g_passed << "/" << g_tests << " tests passed\n";
	std::cout << "Success: " << (g_tests > 0 ? (g_passed * 100 / g_tests) : 0) << "%\n";
	std::cout << "========================================\n";
	
	return (g_passed == g_tests) ? 0 : 1;
}