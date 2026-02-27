#pragma once

#include <vector>
#include <exception>

class Span {
	private:
		unsigned int max;
		std::vector<int> nums;

	public:
		void	addNumber(int in);
		Span(void);
		Span(unsigned int N);
		Span(const Span& in);
		Span& operator=(const Span& in);
		~Span();
		unsigned int		shortestSpan();
		unsigned int		longestSpan();
		void	populate();

		class FullStack : public std::exception {
			public:
				virtual const char * what() const throw();
		};
		class StackTooSmall : public std::exception {
			public:
				virtual const char * what() const throw();
		};
};
