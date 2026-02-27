#pragma once

#include <stddef.h>
#include <exception>

template<typename T>
class Array {
	private:
		unsigned int	len;
		T				*array;

	public:
		Array() {
			this->len = 0;
			this->array = NULL;
		}

		Array(unsigned int len) {
			this->len = len;
			if (len == 0)
			{
				array = NULL;
				return ;
			}
			array = new T[len];
			for (unsigned int i = 0; i < len; i++)
				array[i] = T();
		}

		Array(const Array& in) {
			len = in.size();
			if (len == 0)
			{
				array = NULL;
				return ;
			}
			array = new T[len];
			for (unsigned int i = 0; i < len; i++)
				array[i] = in.array[i];
		}

		Array& operator=(const Array& in) {
			delete [] array;
			len = in.size();
			if (len == 0)
			{
				array = NULL;
				return *this;
			}
			array = new T[len];
			for (unsigned int i = 0; i < len; i++)
				array[i] = in.array[i];
			return *this;
		}

		class InvalidIndex : public std::exception {
			public:
				virtual const char * what() const throw() {
					return "Invalid Index";
				}
		};

		T& operator[](unsigned int i) {
			if (i >= len)
				throw InvalidIndex();
			return (this->array[i]);
		}

		const T& operator[](unsigned int i) const {
			if (i >= len)
				throw InvalidIndex();
			return (this->array[i]);
		}

		unsigned int size(void) const {
			return this->len;
		}

		~Array() {
			delete [] array;
		}
};
