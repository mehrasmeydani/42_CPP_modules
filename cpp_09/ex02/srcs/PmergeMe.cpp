#include "../header/PmergeMe.hpp"
#include <algorithm>
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
static typename T::iterator	bucket_end(T& container, int bucket_size, int bucket_index)
{
	return container.begin() + (bucket_index + 1) * bucket_size - 1;
}

template<typename T>
bool	PmergeMe::compare(typename T::iterator &bigger, typename T::iterator &smaller)
{
	this->increase_n_comparison();
	bool result = (*bigger > *smaller);
	if (VERBOSE)
		std::cout << "cmp[" << this->n_comparison << "]: " << *bigger << " > " << *smaller << " -> " << (result ? "true" : "false") << std::endl;
	return result;
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
void	PmergeMe::insert(T& container, T& main, T& pend, int bucket_size) {
	int	jackobs_prev = 1;
	int	jackobs_curr = 3;
	int	jackobs_diff = jackobs_curr - jackobs_prev;
	int	inserted = 0;
	int	pend_size = pend.size() / bucket_size;
	int	inserted_this_diff = 0;
	std::vector<int> pair_bounds(pend_size + 1);
	for (int i = 1; i < pend_size + 1; i++)
		pair_bounds[i] = i;
	while (inserted < pend_size) {
		int	current_bucket_end = std::min(inserted + jackobs_diff, pend_size);
		int	chosen_element = current_bucket_end - inserted_this_diff;
		int low_bound = 0;
		int	up_bound;
		if (container.size() / bucket_size % 2 == 0 || chosen_element != pend_size)
			up_bound = std::min(pair_bounds[chosen_element], static_cast<int>(main.size() / bucket_size) - 1);
		else
			up_bound = main.size() / bucket_size - 1;
		int	mid;

		typename T::iterator mid_iter;
		typename T::iterator insert_element = bucket_end(pend, bucket_size, chosen_element - 1);
		int	insertion_bucket_index;
		if (VERBOSE)
		{
			std::cout << "\n[insert] step " << (inserted + inserted_this_diff + 1) << "/" << pend_size
				<< " bucket_size=" << bucket_size
				<< " value=" << *insert_element
				<< " pair_bound=" << pair_bounds[chosen_element]
				<< " range=[" << low_bound << "," << up_bound << "]" << std::endl;
		}
		while (low_bound < up_bound)
		{
			mid = low_bound + (up_bound - low_bound) / 2;
			mid_iter = bucket_end(main, bucket_size, mid);
			bool go_left = compare<T>(mid_iter, insert_element);
			if (go_left)
				up_bound = mid - 1;
			else
				low_bound = mid + 1;
			if (VERBOSE)
			{
				std::cout << "  probe mid=" << mid
					<< " mid_val=" << *mid_iter
					<< " decision=" << (go_left ? "left" : "right")
					<< " next_range=[" << low_bound << "," << up_bound << "]" << std::endl;
			}
		}
		mid = low_bound;
		if (up_bound < 0)
		{
			insertion_bucket_index = 0;
			main.insert(main.begin(), insert_element - (bucket_size - 1), insert_element + 1);
		}
		else if (mid >= static_cast<int>(main.size() / bucket_size))
		{
			insertion_bucket_index = main.size() / bucket_size;
			main.insert(main.end(), insert_element - (bucket_size - 1), insert_element + 1);
		}
		else
		{
			mid_iter = bucket_end(main, bucket_size, mid);
			bool	insert_before_mid = compare<T>(mid_iter, insert_element);
			if (insert_before_mid)
				mid_iter = mid_iter - (bucket_size - 1);
			else
				mid_iter = mid_iter + 1;
			insertion_bucket_index = mid + (insert_before_mid ? 0 : 1);
			main.insert(mid_iter, insert_element - (bucket_size - 1), insert_element + 1);
		}
		if (VERBOSE)
		{
			std::cout << "  placed_at_bucket=" << insertion_bucket_index << std::endl;
			std::cout << "  main_after: ";
			print_merge_level(main, bucket_size, main.size() / bucket_size);
		}
		for (int i = 0; i <= pend_size; ++i) {
			if (pair_bounds[i] + 1 >= insertion_bucket_index)
				pair_bounds[i]++;
		}
		inserted_this_diff++;
		if (inserted_this_diff + inserted == pend_size)
			break;
		if (inserted_this_diff == jackobs_diff)
		{
			inserted += inserted_this_diff;
			int	previous_curr = jackobs_curr;
			jackobs_curr += 2 * jackobs_prev;
			jackobs_prev = previous_curr;
			jackobs_diff = jackobs_curr - jackobs_prev;
			inserted_this_diff = 0;
		}
	}
	typename T::iterator remainder = container.begin() + (container.size() / bucket_size) * bucket_size;
	main.insert(main.end(), remainder, container.end());
	container = main;
}

template<typename T>
void	PmergeMe::merge(T& container, int bucket_size, int n_buckets) {
	if (VERBOSE)
	{
		std::cout << "\nmerge stage bucket_size=" << bucket_size << " n_buckets=" << n_buckets << std::endl;
		print_merge_level(container, bucket_size, n_buckets);
	}
	for (int i = 0; i < n_buckets / 2; i++) {
		typename T::iterator	a_node = container.begin() + ((2 * i + 1) * bucket_size) - 1;
		typename T::iterator	b_node = a_node + bucket_size;
		if (compare<T>(a_node, b_node))
			swap_buckets<T>(a_node, b_node, bucket_size);
	}
	if (VERBOSE)
		print_merge_level(container, bucket_size, n_buckets);
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
	if (VERBOSE)
	{
		std::cout << "\ninsert stage bucket_size=" << bucket_size << std::endl;
		std::cout << "main: ";
		print_merge_level(main, bucket_size, main.size() / bucket_size);
		std::cout << "pend: ";
		print_merge_level(pend, bucket_size, pend.size() / bucket_size);
	}

	insert(container, main, pend, bucket_size);

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
template void	PmergeMe::merge_insert_sort<std::deque<unsigned int> >(std::deque<unsigned int>& container, int bucket_size);
