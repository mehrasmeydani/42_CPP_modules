#include "../header/Point.hpp"

Point::Point() : x(0), y(0)
{
}

Point::Point(const Fixed& x, const Fixed& y) : x(x), y(y)
{
}

Point::Point(const Point& in) : x(in.x), y(in.y)
{	
}

Point& Point::operator=(Point& in)
{
	(void)in;
	return (*this);
}

const Point& Point::operator=(const Point& in)
{
	(void)in;
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

