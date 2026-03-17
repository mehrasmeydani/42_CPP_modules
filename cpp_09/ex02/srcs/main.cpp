#include "../header/PmergeMe.hpp"

#include <cstdlib>
#include <deque>
#include <iostream>
#include <vector>
#include <ctime>

int main(int argc, char ** argv)
{

	PmergeMe	me;
	std::vector<unsigned int>	vec;
	std::deque<unsigned int>	deq;
	if (argc < 2)
		return 1;
	for (int i = 1; i < argc; i++)
	{
		vec.push_back(strtod(argv[i], NULL));
		deq.push_back(strtod(argv[i], NULL));
	}
	for (std::vector<unsigned int>::iterator it = vec.begin(); it != vec.end(); it ++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	// clock_t start = std::clock();
	me.merge_insert_sort(vec, 1);
	me.merge_insert_sort(deq, 1);
	// clock_t end = std::clock();

	//double elapsed_us = (double)(end - start) * 1000.0 / CLOCKS_PER_SEC;
	//std::cout << "time " << elapsed_us << " us\n";

	//me.get_n_comparison();
	me.reset_n_comparison();
	std::cout << "vec: \n";
	for (std::vector<unsigned int>::iterator it = vec.begin(); it != vec.end(); it ++) {
		std::cout << *it << " ";
	}
	std::cout << "\ndeq: \n";
	for (std::vector<unsigned int>::iterator it = vec.begin(); it != vec.end(); it ++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}