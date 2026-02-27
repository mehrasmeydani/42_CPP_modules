#pragma once

#include <algorithm>
#include <stdexcept>

template <typename T> typename T::iterator easyfind(T& haystack, int find) {
	typename T::iterator out = std::find(haystack.begin(), haystack.end(), find);
	if (out != haystack.end())
		return out;
	throw std::runtime_error("Not found");
}