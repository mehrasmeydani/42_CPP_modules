#include "../header/PmergeMe.hpp"
#include <iomanip>
#include <iostream>
#include <ostream>
#include <cstddef>
#include <vector>

// Set to 0 to disable this pend->main insertion path quickly.
#ifndef PMERGEME_ENABLE_PEND_INSERTION
#define PMERGEME_ENABLE_PEND_INSERTION 0
#endif

template<typename T>
static void	swap_buckets(typename T::iterator& a, typename T::iterator& b, int bucket_size)
{
	while (bucket_size > 0) {
		std::iter_swap(a - (bucket_size - 1), b - (bucket_size - 1));
		bucket_size--;
	}
}

template<typename T>
static std::size_t	bucket_lower_bound_bounded(
	PmergeMe& sorter,
	T& main,
	int bucket_size,
	std::size_t upper_bound_bucket_pos,
	T& pend,
	std::size_t pend_bucket_pos)
{
	std::size_t lo = 0;
	std::size_t hi = upper_bound_bucket_pos;

	while (lo < hi) {
		std::size_t mid = lo + (hi - lo) / 2;
		typename T::iterator pend_key_it = pend.begin()
			+ (pend_bucket_pos + 1) * static_cast<std::size_t>(bucket_size) - 1;
		typename T::iterator main_key_it = main.begin()
			+ (mid + 1) * static_cast<std::size_t>(bucket_size) - 1;
		if (sorter.compare<T>(pend_key_it, main_key_it))
			lo = mid + 1;
		else
			hi = mid;
	}
	return lo;
}

static std::vector<std::size_t>	build_jacobsthal_diff_reverse_order(std::size_t pend_bucket_count)
{
	std::vector<std::size_t> order;
	if (pend_bucket_count == 0)
		return order;

	// pend[0] is b2 and is inserted first.
	order.push_back(0);
	if (pend_bucket_count == 1)
		return order;

	// b-indices available are b2..b(max_b), where max_b = pend_bucket_count + 1.
	// Jacobsthal boundary insertion: b3, then b5..b4, then b11..b6, ...
	std::size_t max_b = pend_bucket_count + 1;
	std::size_t prev_boundary_b = 2;
	std::size_t prev_j = 1;
	std::size_t curr_j = 3;

	while (prev_boundary_b < max_b) {
		std::size_t boundary_b = curr_j;
		if (boundary_b > max_b)
			boundary_b = max_b;
		for (long b = static_cast<long>(boundary_b); b > static_cast<long>(prev_boundary_b); --b) {
			std::size_t pend_pos = static_cast<std::size_t>(b - 2);
			order.push_back(pend_pos);
		}
		prev_boundary_b = boundary_b;
		if (prev_boundary_b == max_b)
			break;
		std::size_t next_j = curr_j + 2 * prev_j;
		prev_j = curr_j;
		curr_j = next_j;
	}
	return order;
}

static std::size_t	find_label_pos(const std::vector<int>& labels, int label)
{
	for (std::size_t i = 0; i < labels.size(); ++i) {
		if (labels[i] == label)
			return i;
	}
	return labels.size();
}

template<typename T>
static void	insert_pend_into_main_with_labels(
	PmergeMe& sorter,
	T& main,
	T& pend,
	std::vector<int>& main_labels,
	const std::vector<int>& pend_labels,
	const std::vector<int>& pend_partner_winner_labels,
	int bucket_size)
{
	std::vector<std::size_t> order = build_jacobsthal_diff_reverse_order(pend_labels.size());

	for (std::size_t k = 0; k < order.size(); ++k) {
		std::size_t pend_bucket_pos = order[k];
		int partner_label = pend_partner_winner_labels[pend_bucket_pos];
		std::size_t bound = main_labels.size();

		if (partner_label != 0) {
			std::size_t found = find_label_pos(main_labels, partner_label);
			if (found != main_labels.size())
				bound = found;
		}

		std::size_t insert_bucket_pos = bucket_lower_bound_bounded(sorter, main, bucket_size, bound, pend, pend_bucket_pos);
		typename T::const_iterator src_begin = pend.begin() + pend_bucket_pos * static_cast<std::size_t>(bucket_size);
		typename T::const_iterator src_end = src_begin + bucket_size;
		typename T::iterator dst = main.begin() + insert_bucket_pos * static_cast<std::size_t>(bucket_size);
		main.insert(dst, src_begin, src_end);
		main_labels.insert(main_labels.begin() + insert_bucket_pos, pend_labels[pend_bucket_pos]);
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
	std::vector<int> main_labels;
	std::vector<int> pend_labels;
	std::vector<int> pend_partner_winner_labels;
	main.insert(main.end(), container.begin(), container.begin() + bucket_size);
	main_labels.push_back(-1);
	for (int i = 1; i < n_buckets; i++) {
		typename T::iterator insert = container.begin() + i * bucket_size;
		int pair_id = i / 2 + 1;
		if (i % 2 && !(n_buckets % 2 && i == n_buckets - 1)) {
			main.insert(main.end(), insert, insert + bucket_size);
			main_labels.push_back(pair_id);
		}
		else {
			pend.insert(pend.end(), insert, insert + bucket_size);
			pend_labels.push_back(-pair_id);
			if ((2 * pair_id - 1) < n_buckets)
				pend_partner_winner_labels.push_back(pair_id);
			else
				pend_partner_winner_labels.push_back(0);
		}
	}

#if PMERGEME_ENABLE_PEND_INSERTION
	insert_pend_into_main_with_labels(
		*this,
		main,
		pend,
		main_labels,
		pend_labels,
		pend_partner_winner_labels,
		bucket_size);

	T rebuilt;
	rebuilt.insert(rebuilt.end(), main.begin(), main.end());
	rebuilt.insert(rebuilt.end(), container.begin() + n_buckets * bucket_size, container.end());
	container.swap(rebuilt);
#endif

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
