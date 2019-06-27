#pragma once

#define DEFAULT_X 0.0
#define DEFAULT_Y 0.0

struct Point
{
	double x;
	double y;

	Point(double _x = DEFAULT_X, double _y = DEFAULT_Y);
	Point& operator=(const Point &other);

	void print();
};