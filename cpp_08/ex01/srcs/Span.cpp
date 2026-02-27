#include "../header/Span.hpp"

#include <algorithm>
#include <cstdlib>
#include <ctime>

void	Span::populate() {
	srand(time(0));
	while (nums.size() < max) {
		nums.push_back(rand());
	}
}

unsigned int	Span::longestSpan() {
	if (this->nums.size() < 2)
		throw Span::StackTooSmall();
	std::vector<int> tmp = this->nums;
	std::sort(tmp.begin(), tmp.end());
	return (static_cast<unsigned int>(tmp.back()) - static_cast<unsigned int>(tmp.front()));
}

unsigned int Span::shortestSpan() {
	if (this->nums.size() < 2)
		throw Span::StackTooSmall();
	std::vector<int> tmp = this->nums;
	std::sort(tmp.begin(), tmp.end());
	std::vector<int>::iterator ptr1 = tmp.begin();
	std::vector<int>::iterator ptr2 = ptr1 + 1;
	unsigned int min = static_cast<unsigned int>(*ptr2) - static_cast<unsigned int>(*ptr1);
	while (ptr2 != tmp.end())
	{
		if (min > static_cast<unsigned int>(*ptr2) - static_cast<unsigned int>(*ptr1))
			min = static_cast<unsigned int>(*ptr2) - static_cast<unsigned int>(*ptr1);
		ptr1++;
		ptr2++;
	}
	return min;
}

void Span::addNumber(int i) {
	if (max == nums.size())
		throw Span::FullStack();
	nums.push_back(i);
}

Span::Span(void) {}

Span::Span(unsigned int N) {
	this->max = N;
}

Span::Span(const Span& in) {
	this->max = in.max;
	this->nums = in.nums;
}

const char * Span::FullStack::what() const throw() {
	return "Stack Is Full";
}

const char * Span::StackTooSmall::what() const throw() {
	return "Stack Too Small";
}


Span &Span::operator=(const Span& in) {
	this->max = in.max;
	nums = in.nums;
	return (*this);
}

Span::~Span(void) {}
