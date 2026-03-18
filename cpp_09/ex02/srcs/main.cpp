#include "../header/PmergeMe.hpp"

#include <cstdlib>
#include <deque>
#include <iostream>
#include <vector>
#include <ctime>
#include <climits>
#include <cerrno>

int main(int argc, char ** argv)
{

	PmergeMe	me;
	std::vector<unsigned int>	vec;
	std::deque<unsigned int>	deq;
	if (argc < 2)
	{
		std::cerr << "Usage: ./PmergeMe <input numbers>\n";
		return 1;
	}
	for (int i = 1; i < argc; i++)
	{
		for (int j = 0 ; argv[i][j]; j++) {
			if ((argv[i][j] > '9' || argv[i][j] < '0'))
			{
				std::cerr << "only positive integers are accepted as input\n";
				return 1;
			}
		}
		errno = 0;
		double	num = strtod(argv[i], NULL);
		if (num > INT_MAX || num < 0 || errno != 0 || !argv[i][0])
		{
			std::cerr << "only positive integers are accepted as input\n";
			return 1;
		}
		vec.push_back(static_cast<unsigned int>(num));
		deq.push_back(static_cast<unsigned int>(num));
	}

	for (std::vector<unsigned int>::iterator it = vec.begin(); it != vec.end(); it ++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	clock_t start = std::clock();
	me.merge_insert_sort(vec, 1);
	clock_t end = std::clock();
	double elapsed_us = (double)(end - start) * 1000.0 / CLOCKS_PER_SEC;
	std::cout << "vec: " << elapsed_us << " us\n";
	me.get_n_comparison();

	me.reset_n_comparison();

	start = std::clock();
	me.merge_insert_sort(deq, 1);
	end = std::clock();
	elapsed_us = (double)(end - start) * 1000.0 / CLOCKS_PER_SEC;
	std::cout << "deq: " << elapsed_us << " us\n";
	me.get_n_comparison();
	
	for (std::vector<unsigned int>::iterator it = vec.begin(); it != vec.end(); it ++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}