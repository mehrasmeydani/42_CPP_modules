#include "../header/Array.hpp"
#include <iostream>
#include <string>

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

#define ASSERT_THROW(code) \
	try { \
		code; \
		std::cout << RED "FAIL" RESET " " << __func__ << " (no exception)" << std::endl; \
	} catch (const std::exception& r) { \
		(void)r; \
		std::cout << GREEN "PASS" RESET " " << __func__ << std::endl; \
		g_passed++; \
	}

void test_default_constructor() {
	TEST("default constructor");
	Array<int> arr;
	ASSERT(arr.size() == 0);
}

void test_size_constructor() {
	TEST("size constructor");
	Array<int> arr(5);
	ASSERT(arr.size() == 5);
	
	TEST("size constructor initialization");
	bool all_default = true;
	for (unsigned int i = 0; i < arr.size(); i++) {
		if (arr[i] != 0) {
			all_default = false;
			break;
		}
	}
	ASSERT(all_default);
}

void test_copy_constructor() {
	TEST("copy constructor size");
	Array<int> original(3);
	original[0] = 10; original[1] = 20; original[2] = 30;
	Array<int> copy(original);
	ASSERT(copy.size() == original.size());
	
	TEST("copy constructor values");
	bool values_match = true;
	for (unsigned int i = 0; i < copy.size(); i++) {
		if (copy[i] != original[i]) {
			values_match = false;
			break;
		}
	}
	ASSERT(values_match);
	
	TEST("copy constructor independence");
	original[0] = 999;
	ASSERT(copy[0] == 10);
}

void test_assignment_operator() {
	TEST("assignment operator");
	Array<int> arr1(3);
	arr1[0] = 1; arr1[1] = 2; arr1[2] = 3;
	Array<int> arr2(5);
	arr2 = arr1;
	ASSERT(arr2.size() == 3 && arr2[0] == 1 && arr2[1] == 2 && arr2[2] == 3);
	
	TEST("assignment independence");
	arr1[0] = 999;
	ASSERT(arr2[0] == 1);
}

void test_element_access() {
	TEST("element access read/write");
	Array<int> arr(5);
	arr[0] = 42;
	arr[4] = 99;
	ASSERT(arr[0] == 42 && arr[4] == 99);
	
	TEST("const element access");
	const Array<int>& const_arr = arr;
	ASSERT(const_arr[0] == 42);
}

void test_exceptions() {
	TEST("out of bounds exception");
	Array<int> arr(3);
	ASSERT_THROW(arr[3] = 42);
	
	TEST("empty array exception");
	Array<int> empty;
	ASSERT_THROW((void)empty[0]);

	TEST("negative index exception");
	ASSERT_THROW((void)arr[-1]);
}

void test_different_types() {
	TEST("string array");
	Array<std::string> str_arr(2);
	str_arr[0] = "hello";
	str_arr[1] = "world";
	ASSERT(str_arr[0] == "hello" && str_arr[1] == "world");
	
	TEST("double array");
	Array<double> double_arr(2);
	double_arr[0] = 3.14;
	double_arr[1] = 2.71;
	ASSERT(double_arr[0] == 3.14 && double_arr[1] == 2.71);
}

void test_edge_cases() {
	TEST("zero size array");
	Array<int> zero_arr(0);
	ASSERT(zero_arr.size() == 0);
	
	TEST("large array");
	Array<int> large_arr(1000);
	large_arr[999] = 42;
	ASSERT(large_arr.size() == 1000 && large_arr[999] == 42);
	
	TEST("chain assignment");
	Array<int> a(2), b(2), c(2);
	a[0] = 10; a[1] = 20;
	c = b = a;
	ASSERT(b[0] == 10 && b[1] == 20 && c[0] == 10 && c[1] == 20);
}

int main() {
	std::cout << "========================================\n";
	std::cout << "         Array Template Unit Tests\n";
	std::cout << "========================================\n\n";
	
	test_default_constructor();
	test_size_constructor();  
	test_copy_constructor();
	test_assignment_operator();
	test_element_access();
	test_exceptions();
	test_different_types();
	test_edge_cases();
	
	std::cout << "\n========================================\n";
	std::cout << "Results: " << g_passed << "/" << g_tests << " tests passed\n";
	std::cout << "Success: " << (g_tests > 0 ? (g_passed * 100 / g_tests) : 0) << "%\n";
	std::cout << "========================================\n";
	
	return (g_passed == g_tests) ? 0 : 1;
}


// #include <iostream>
// #include <cstdlib>
// #include "../header/Array.hpp"

// #define MAX_VAL 750
// int main(int, char**)
// {
//     Array<int> numbers(MAX_VAL);
//     int* mirror = new int[MAX_VAL];
//     srand(time(NULL));
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         const int value = rand();
//         numbers[i] = value;
//         mirror[i] = value;
//     }
//     //SCOPE
//     {
//         Array<int> tmp = numbers;
//         Array<int> test(tmp);
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         if (mirror[i] != numbers[i])
//         {
//             std::cerr << "didn't save the same value!!" << std::endl;
//             return 1;
//         }
//     }
//     try
//     {
//         numbers[-2] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }
//     try
//     {
//         numbers[MAX_VAL] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         numbers[i] = rand();
//     }
//     delete [] mirror;//
//     return 0;
// }