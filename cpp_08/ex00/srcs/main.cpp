#include "../header/easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <deque>

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

void test_vector_find_existing() {
	TEST("vector find existing element");
	std::vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);
	vec.push_back(5);
	
	std::vector<int>::iterator it = easyfind(vec, 3);
	ASSERT(it != vec.end() && *it == 3);
}

void test_vector_find_first() {
	TEST("vector find first element");
	std::vector<int> vec;
	vec.push_back(10);
	vec.push_back(20);
	vec.push_back(30);
	
	std::vector<int>::iterator it = easyfind(vec, 10);
	ASSERT(it == vec.begin() && *it == 10);
}

void test_vector_find_last() {
	TEST("vector find last element");
	std::vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	
	std::vector<int>::iterator it = easyfind(vec, 3);
	ASSERT(it != vec.end() && *it == 3);
}

void test_vector_not_found() {
	TEST("vector element not found");
	std::vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	
	ASSERT_THROW(easyfind(vec, 99), std::exception);
}

void test_list_find_existing() {
	TEST("list find existing element");
	std::list<int> lst;
	lst.push_back(5);
	lst.push_back(10);
	lst.push_back(15);
	lst.push_back(20);
	
	std::list<int>::iterator it = easyfind(lst, 15);
	ASSERT(it != lst.end() && *it == 15);
}

void test_list_not_found() {
	TEST("list element not found");
	std::list<int> lst;
	lst.push_back(1);
	lst.push_back(3);
	lst.push_back(5);
	
	ASSERT_THROW(easyfind(lst, 4), std::exception);
}

void test_deque_find_existing() {
	TEST("deque find existing element");
	std::deque<int> deq;
	deq.push_back(100);
	deq.push_back(200);
	deq.push_back(300);
	
	std::deque<int>::iterator it = easyfind(deq, 200);
	ASSERT(it != deq.end() && *it == 200);
}

void test_deque_not_found() {
	TEST("deque element not found");
	std::deque<int> deq;
	deq.push_back(2);
	deq.push_back(4);
	deq.push_back(6);
	
	ASSERT_THROW(easyfind(deq, 5), std::exception);
}

void test_empty_containers() {
	TEST("empty vector");
	std::vector<int> empty_vec;
	ASSERT_THROW(easyfind(empty_vec, 1), std::exception);
	
	TEST("empty list");
	std::list<int> empty_list;
	ASSERT_THROW(easyfind(empty_list, 1), std::exception);
	
	TEST("empty deque");
	std::deque<int> empty_deque;
	ASSERT_THROW(easyfind(empty_deque, 1), std::exception);
}

void test_single_element() {
	TEST("single element vector - found");
	std::vector<int> vec;
	vec.push_back(42);
	std::vector<int>::iterator it = easyfind(vec, 42);
	ASSERT(it != vec.end() && *it == 42);
	
	TEST("single element vector - not found");
	ASSERT_THROW(easyfind(vec, 43), std::exception);
}

void test_duplicate_elements() {
	TEST("duplicate elements - finds first");
	std::vector<int> vec;
	vec.push_back(7);
	vec.push_back(7);
	vec.push_back(7);
	
	std::vector<int>::iterator it = easyfind(vec, 7);
	ASSERT(it == vec.begin() && *it == 7);
}

void test_negative_numbers() {
	TEST("negative numbers");
	std::vector<int> vec;
	vec.push_back(-5);
	vec.push_back(-10);
	vec.push_back(0);
	vec.push_back(5);
	
	std::vector<int>::iterator it1 = easyfind(vec, -5);
	std::vector<int>::iterator it2 = easyfind(vec, 0);
	ASSERT(it1 != vec.end() && *it1 == -5 && it2 != vec.end() && *it2 == 0);
}

void test_large_container() {
	TEST("large container");
	std::vector<int> vec;
	for (int i = 0; i < 1000; i++) {
		vec.push_back(i);
	}
	
	std::vector<int>::iterator it = easyfind(vec, 500);
	ASSERT(it != vec.end() && *it == 500);
	
	TEST("large container - not found");
	ASSERT_THROW(easyfind(vec, 1001), std::exception);
}

int main() {
	std::cout << "========================================\n";
	std::cout << "        EasyFind Function Unit Tests\n";
	std::cout << "========================================\n\n";
	
	test_vector_find_existing();
	test_vector_find_first();
	test_vector_find_last();
	test_vector_not_found();
	test_list_find_existing();
	test_list_not_found();
	test_deque_find_existing();
	test_deque_not_found();
	test_empty_containers();
	test_single_element();
	test_duplicate_elements();
	test_negative_numbers();
	test_large_container();
	
	std::cout << "\n========================================\n";
	std::cout << "Results: " << g_passed << "/" << g_tests << " tests passed\n";
	std::cout << "Success: " << (g_tests > 0 ? (g_passed * 100 / g_tests) : 0) << "%\n";
	std::cout << "========================================\n";
	
	return (g_passed == g_tests) ? 0 : 1;
}