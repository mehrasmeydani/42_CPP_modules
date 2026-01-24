#include "../header/Point.hpp"

Point::Point() : x(0), y(0)
{
	//std::cout << "def" << std::endl;
}

Point::Point(const Fixed& x, const Fixed& y) : x(x), y(y)
{
}

Point::Point(const Point& in) : x(in.x), y(in.y)
{
	//std::cout << "copy" << std::endl;
}

Point::Point(const float x, const float y) : x(x), y(y)
{
}

Point& Point::operator=(const Point& in)
{
	(void)in;
	//std::cout << "assign" << std::endl;
	return (*this);
}

Point::~Point()
{
}


const Fixed&	Point::getX() const
{
	return this->x;
}

const Fixed&	Point::getY() const
{
	return this->y;
}

std::ostream& operator<<(std::ostream& os, const Point& in)
{
	os << "[" << in.getX() << ", " << in.getY() << "]" << std::flush; 
	return os;
}

