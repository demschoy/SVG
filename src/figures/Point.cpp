#include <iostream>
#include "Point.hpp"


Point::Point(double _x, double _y) : x(_x), y(_y) {	}

Point& Point::operator=(const Point &other)
{
	if (this != &other) 
	{
		x = other.x;
		y = other.y;
	}
	return *this;
}

void Point::print()
{
	std::cout << "(" << x << ", " << y << ")";
}
