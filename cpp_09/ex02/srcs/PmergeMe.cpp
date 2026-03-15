#include "../header/PmergeMe.hpp"
#include <iomanip>
#include <iostream>
#include <ostream>
#include <vector>

template<typename T>
static void	swap_buckets(typename T::iterator& a, typename T::iterator& b, int bucket_size)
{
	while (bucket_size > 0) {
		std::iter_swap(a - (bucket_size - 1), b - (bucket_size - 1));
		bucket_size--;
	}
}

template<typename T>
bool	PmergeMe::compare(typename T::iterator &a, typename T::iterator &b)
{
	this->increase_n_comparison();
	if (*a > *b)
		return true;
	return false;
}

template <typename T>
void	PmergeMe::print_merge_level(T& container, int bucket_size, int n_buckets) {
	int i = 0;
	int j = 0;
	
	for (typename T::iterator it = container.begin();it != container.end();it ++)
	{
		if (i == 0)
			std::cout << "[";
		i++;
		std::cout << std::setw(2) << *it;
		if (i == bucket_size)
		{
			std::cout << "]";
			j++;
			i = 0;
		}
		if (j == n_buckets)
		{
			j++;
			std::cout << " |";
		}
		if (it + 1 != container.end())
			std::cout << " ";
	}
	if (i != 0)
		std::cout << "]";
	std::cout << std::endl;
	
}

template<typename T>
void	PmergeMe::merge(T& container, int bucket_size, int n_buckets)
{
	typename T::iterator	a_node = container.begin() + bucket_size - 1;
	typename T::iterator	b_node = a_node + bucket_size;
	for (int i = 0; i < n_buckets / 2; i++) {
		if (compare<T>(a_node, b_node))
			swap_buckets<T>(a_node, b_node, bucket_size);
		a_node += (2 * bucket_size);
		b_node = a_node + bucket_size;
	}
}

template<typename T>
void	PmergeMe::merge_insert_sort(T& container, int bucket_size){
	int	n_buckets = container.size() / bucket_size;
	if (n_buckets == 1)
		return ;
	
	merge(container, bucket_size, n_buckets);
	merge_insert_sort(container, bucket_size * 2);

	if (n_buckets == 2)
		return ;
	T main;
	T pend;
	main.insert(main.end(), container.begin(), container.begin() + bucket_size);
	for (int i = 1; i < n_buckets; i++) {
		typename T::iterator insert = container.begin() + i * bucket_size;
		if (i % 2 && !(n_buckets % 2 && i == n_buckets - 1))
			main.insert(main.end(), insert, insert + bucket_size);
		else
			pend.insert(pend.end(), insert, insert + bucket_size);
	}

	std::cout << "\noriginal: ";
	print_merge_level(container, bucket_size, n_buckets);
	std::cout << "main:     ";
	print_merge_level(main, bucket_size, n_buckets);
	std::cout << "pend: ";
	for (int i = 0; i < bucket_size * 6 + 8; ++i) {
		std::cout << " ";
	}
	print_merge_level(pend, bucket_size, n_buckets);

}

PmergeMe::PmergeMe(void) {this->n_comparison = 0;}

PmergeMe::PmergeMe(const PmergeMe& in) {(void)in;}

PmergeMe &PmergeMe::operator=(const PmergeMe& in) {
	(void)in;
	return (*this);
}

PmergeMe::~PmergeMe(void) {}

void	PmergeMe::get_n_comparison() const
{
	std::cout << this->n_comparison << std::endl;
}

void	PmergeMe::increase_n_comparison()
{
	this->n_comparison++;
}

void	PmergeMe::reset_n_comparison()
{
	this->n_comparison = 0;
}

template void	PmergeMe::merge_insert_sort<std::vector<unsigned int> >(std::vector<unsigned int>& container, int bucket_size);
