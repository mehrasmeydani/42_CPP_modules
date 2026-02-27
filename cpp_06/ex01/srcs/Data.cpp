#include "../header/Data.hpp"


Data::Data(void) : i(0) {}

Data::Data(const Data& in) : i(in.i) {}

Data &Data::operator=(const Data& in) {
	this->i = in.i;
	return (*this);
}

Data::~Data(void) {}
