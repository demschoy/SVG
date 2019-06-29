#pragma once

#include "Messages.hpp"

struct Point
{
	double x;
	double y;

	Point(double _x = DEFAULT_X, double _y = DEFAULT_Y);
	Point& operator=(const Point &other);

	void print();
};