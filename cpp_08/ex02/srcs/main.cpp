#include "../header/MutantStack.hpp"
#include <iostream>
#include <list>
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

#define ASSERT_NO_THROW(code) \
	try { \
		code; \
		std::cout << GREEN "PASS" RESET " " << __func__ << std::endl; \
		g_passed++; \
	} catch (...) { \
		std::cout << RED "FAIL" RESET " " << __func__ << " (unexpected exception)" << std::endl; \
	}

// ---- Basic stack operations ----

void test_default_constructor() {
	TEST("default constructor");
	MutantStack<int> mstack;
	ASSERT(mstack.empty() && mstack.size() == 0);
}

void test_push_and_top() {
	TEST("push and top");
	MutantStack<int> mstack;
	mstack.push(42);
	ASSERT(mstack.top() == 42);
}

void test_push_multiple() {
	TEST("push multiple elements");
	MutantStack<int> mstack;
	mstack.push(1);
	mstack.push(2);
	mstack.push(3);
	ASSERT(mstack.size() == 3 && mstack.top() == 3);
}

void test_pop() {
	TEST("pop");
	MutantStack<int> mstack;
	mstack.push(10);
	mstack.push(20);
	mstack.pop();
	ASSERT(mstack.size() == 1 && mstack.top() == 10);
}

void test_empty() {
	TEST("empty check");
	MutantStack<int> mstack;
	bool was_empty = mstack.empty();
	mstack.push(1);
	ASSERT(was_empty == true && mstack.empty() == false);
}

// ---- Iterator tests ----

void test_begin_end() {
	TEST("begin/end iteration");
	MutantStack<int> mstack;
	mstack.push(1);
	mstack.push(2);
	mstack.push(3);

	int expected[] = {1, 2, 3};
	int i = 0;
	bool ok = true;
	for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it) {
		if (*it != expected[i])
			ok = false;
		i++;
	}
	ASSERT(ok && i == 3);
}

void test_const_iterator() {
	TEST("const_iterator");
	MutantStack<int> mstack;
	mstack.push(10);
	mstack.push(20);
	mstack.push(30);

	const MutantStack<int>& cref = mstack;
	int sum = 0;
	for (MutantStack<int>::const_iterator it = cref.begin(); it != cref.end(); ++it)
		sum += *it;
	ASSERT(sum == 60);
}


void test_iterator_modify() {
	TEST("modify through iterator");
	MutantStack<int> mstack;
	mstack.push(1);
	mstack.push(2);
	mstack.push(3);

	for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
		*it *= 10;

	int expected[] = {10, 20, 30};
	int i = 0;
	bool ok = true;
	for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it) {
		if (*it != expected[i])
			ok = false;
		i++;
	}
	ASSERT(ok);
}

void test_empty_stack_iterators() {
	TEST("iterators on empty stack");
	MutantStack<int> mstack;
	ASSERT(mstack.begin() == mstack.end());
}

// ---- Copy / Assignment ----

void test_copy_constructor() {
	TEST("copy constructor");
	MutantStack<int> original;
	original.push(1);
	original.push(2);
	original.push(3);

	MutantStack<int> copy(original);
	ASSERT(copy.size() == 3 && copy.top() == 3);
}

void test_copy_independence() {
	TEST("copy independence");
	MutantStack<int> original;
	original.push(10);
	original.push(20);

	MutantStack<int> copy(original);
	copy.push(30);
	ASSERT(original.size() == 2 && copy.size() == 3);
}

void test_assignment_operator() {
	TEST("assignment operator");
	MutantStack<int> sp1;
	sp1.push(10);
	sp1.push(20);
	sp1.push(30);

	MutantStack<int> sp2;
	sp2 = sp1;
	ASSERT(sp2.size() == 3 && sp2.top() == 30);
}

void test_assignment_independence() {
	TEST("assignment independence");
	MutantStack<int> sp1;
	sp1.push(1);
	sp1.push(2);

	MutantStack<int> sp2;
	sp2 = sp1;
	sp2.push(3);
	ASSERT(sp1.size() == 2 && sp2.size() == 3);
}

void test_self_assignment() {
	TEST("self assignment");
	MutantStack<int> mstack;
	mstack.push(42);
	MutantStack<int>* ptr = &mstack;
	mstack = *ptr;
	ASSERT(mstack.size() == 1 && mstack.top() == 42);
}

// ---- Compare with std::list ----

void test_compare_with_list() {
	TEST("compare behavior with std::list");
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	std::list<int> lst;
	lst.push_back(5);
	lst.push_back(17);
	lst.push_back(3);
	lst.push_back(5);
	lst.push_back(737);
	lst.push_back(0);

	bool ok = true;
	MutantStack<int>::iterator mit = mstack.begin();
	std::list<int>::iterator lit = lst.begin();
	while (mit != mstack.end() && lit != lst.end()) {
		if (*mit != *lit)
			ok = false;
		++mit;
		++lit;
	}
	ASSERT(ok && mit == mstack.end() && lit == lst.end());
}

// ---- Different types ----

void test_string_stack() {
	TEST("MutantStack<std::string>");
	MutantStack<std::string> mstack;
	mstack.push("hello");
	mstack.push("world");
	mstack.push("42");

	std::string concat;
	for (MutantStack<std::string>::iterator it = mstack.begin(); it != mstack.end(); ++it)
		concat += *it + " ";
	ASSERT(concat == "hello world 42 ");
}

void test_float_stack() {
	TEST("MutantStack<float>");
	MutantStack<float> mstack;
	mstack.push(1.5f);
	mstack.push(2.5f);
	mstack.push(3.5f);

	float sum = 0;
	for (MutantStack<float>::iterator it = mstack.begin(); it != mstack.end(); ++it)
		sum += *it;
	ASSERT(sum > 7.4f && sum < 7.6f);
}

// ---- Subject example ----

void test_subject_example() {
	TEST("subject example");
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << "top: " << mstack.top() << std::endl;

	mstack.pop();

	std::cout << "size: " << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;
	int count = 0;
	while (it != ite) {
		std::cout << *it << std::endl;
		++it;
		count++;
	}
	std::stack<int> s(mstack);
	ASSERT(mstack.size() == 5 && count == 5 && s.size() == 5);
}

// ---- Large stack ----

void test_large_stack() {
	TEST("large stack - 10000 elements");
	MutantStack<int> mstack;
	for (int i = 0; i < 10000; i++)
		mstack.push(i);

	int sum = 0;
	int n = 0;
	for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it) {
		sum += *it;
		n++;
	}
	// sum of 0..9999 = 49995000
	ASSERT(n == 10000 && sum == 49995000);
}

int main() {
	std::cout << "========================================\n";
	std::cout << "      MutantStack Class Unit Tests\n";
	std::cout << "========================================\n\n";

	test_default_constructor();
	test_push_and_top();
	test_push_multiple();
	test_pop();
	test_empty();

	std::cout << "\n--- Iterator Tests ---\n";
	test_begin_end();
	test_const_iterator();
	test_iterator_modify();
	test_empty_stack_iterators();

	std::cout << "\n--- Copy / Assignment ---\n";
	test_copy_constructor();
	test_copy_independence();
	test_assignment_operator();
	test_assignment_independence();
	test_self_assignment();

	std::cout << "\n--- Compare with std::list ---\n";
	test_compare_with_list();

	std::cout << "\n--- Different Types ---\n";
	test_string_stack();
	test_float_stack();

	std::cout << "\n--- Large Stack ---\n";
	test_large_stack();

	std::cout << "\n--- Subject Example ---\n";
	test_subject_example();

	std::cout << "\n========================================\n";
	std::cout << "Results: " << g_passed << "/" << g_tests << " tests passed\n";
	std::cout << "Success: " << (g_tests > 0 ? (g_passed * 100 / g_tests) : 0) << "%\n";
	std::cout << "========================================\n";

	return (g_passed == g_tests) ? 0 : 1;
}
