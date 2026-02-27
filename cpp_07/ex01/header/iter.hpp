#pragma once
#include <stddef.h>

template <typename T> void iter(const T *a, const size_t size, void f(const T&)) {
	for (size_t i = 0; i < size; i++) {
		f(a[i]);
	}
}

template <typename T> void iter(T *a, const size_t size, void f(T&)) {
	for (size_t i = 0; i < size; i++) {
		f(a[i]);
	}
}