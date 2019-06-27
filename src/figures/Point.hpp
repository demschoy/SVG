#pragma once

struct Point
{
	double x;
	double y;

	Point(double _x, double _y);
	Point& operator=(const Point &other);

	void print();
};