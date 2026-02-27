#pragma once

#include "Data.hpp"
#include <stdint.h>

class Serializer {
	private:
		Serializer(void);
		Serializer(const Serializer& in);
		Serializer& operator=(const Serializer& in);
		~Serializer();
	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};
