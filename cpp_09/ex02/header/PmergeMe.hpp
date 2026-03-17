#pragma once

#include <algorithm>
#include <iostream>
#include <deque>
#include <vector>

class PmergeMe {
	private:
		PmergeMe(const PmergeMe& in);
		PmergeMe& operator=(const PmergeMe& in);
		int	n_comparison;
		template<typename T>
		void	merge(T& container, int bucket_size, int n_buckets);
		template<typename T>
		bool	compare(typename T::iterator &a, typename T::iterator &b);
		template<typename T>
		void	print_merge_level(T& container, int bucket_size, int n_buckets);
		template<typename T>
		void	insert(T& container, T& main, T& pend, int bucket_size);

	public:
		void	get_n_comparison() const;
		void	increase_n_comparison();
		void	reset_n_comparison();
		template<typename T>
		void	merge_insert_sort(T& container, int bucket_size);
		PmergeMe(void);
		~PmergeMe();
};

