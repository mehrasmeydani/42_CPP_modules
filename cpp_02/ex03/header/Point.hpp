#pragma once

#include "Fixed.hpp"

class Point
{
	private:
		const	Fixed x;
		const	Fixed y;
	public:
		Point();
		Point(const Fixed& x, const Fixed& y);
		Point(const Point& in);
		Point&	operator=(const Point& in);
		~Point();

		const Fixed&	getX(void) const;
		const Fixed&	getY(void) const;
};

std::ostream& operator<<(std::ostream& os, const Point& in);
bool bsp( Point const a, Point const b, Point const c, Point const point);
