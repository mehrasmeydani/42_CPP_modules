#pragma once

#include <algorithm>

class PmergeMe {
	private:
		PmergeMe(const PmergeMe& in);
		PmergeMe& operator=(const PmergeMe& in);
		int	n_comparison = 0;
		template<typename T>
		void	merge(T& container, int bucket_size, int n_buckets);
		template<typename T>
		bool	compare(typename T::iterator &a, typename T::iterator &b);

		template<typename T>
		void	print_merge_level(T& container, typename T::iterator &a, typename T::iterator &b, int bucket_size, int n_buckets);

	public:
		void	get_n_comparison() const;
		void	increase_n_comparison();
		void	set_n_comparison();
		template<typename T>
		void	merge_insert_sort(T& container, int bucket_size);
		PmergeMe(void);
		~PmergeMe();
};

