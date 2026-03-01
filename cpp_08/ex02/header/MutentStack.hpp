#pragma once
#include <stack>

template <typename T>
class MutantStack : public std::stack<T> {
	public:
		MutantStack() {}
		MutantStack(const MutantStack& in) {(void)in;}
		MutantStack& operator=(const MutantStack& in) {
			(void)in;
			return *this;
		}
		~MutantStack() {}
		
};
