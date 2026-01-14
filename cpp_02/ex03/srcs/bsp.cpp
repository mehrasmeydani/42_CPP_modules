#include "../header/Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed	dom;
	dom = ((b.getY() - c.getY()) * (a.getX() - c.getX())
		+ (c.getX() - b.getX()) * (a.getY() - c.getY()));
	if (dom == Fixed(0))
		return false;
	Fixed	w[3];
	w[0] = (((b.getY() - c.getY()) * (point.getX() - c.getX()) + (c.getX() - b.getX()) * (point.getY() - c.getY())) / dom);
	w[1] = (((c.getY() - a.getY()) * (point.getX() - c.getX()) + (a.getX() - c.getX()) * (point.getY() - c.getY())) / dom);
	w[2] = Fixed(1.0f) - w[0] - w[1];
	
	for (int i = 0; i < 3; i++)
	{
		if (w[i] <= Fixed(0.0f) || w[i] >= Fixed(1.0f))
			return false;
	}
	return true;
}
