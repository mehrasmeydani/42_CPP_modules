#include "../header/Base.hpp"

Base::Base(void) {}

Base::Base(const Base& in) {(void)in;}

Base &Base::operator=(const Base& in) {
	(void)in;
	return (*this);
}

Base::~Base(void) {}
