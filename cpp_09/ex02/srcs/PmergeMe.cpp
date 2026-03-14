#include "../header/PmergeMe.hpp"



template<typename T>
static void	swap_buckets(typename T::iterator& a, typename T::iterator& b, int bucket_size)
{
	while (bucket_size > 0) {
		std::swap(a - (bucket_size - 1), b - (bucket_size - 1));
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
void	PmergeMe::print_merge_level(T& container, typename T::iterator &a, typename T::iterator &b, int bucket_size, int n_buckets) {
	
}

template<typename T>
void	PmergeMe::merge(T& container, int bucket_size, int n_buckets)
{
	typename T::iterator	a_node = container.begin() + bucket_size - 1;
	typename T::iterator	b_node = a_node + bucket_size;
	for (int i = 0; i < n_buckets / 2; i++) {
		print_merge_level(container, a_node, b_node, bucket_size, n_buckets);
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
}

PmergeMe::PmergeMe(void) {}

PmergeMe::PmergeMe(const PmergeMe& in) {(void)in;}

PmergeMe &PmergeMe::operator=(const PmergeMe& in) {
	(void)in;
	return (*this);
}

PmergeMe::~PmergeMe(void) {}
