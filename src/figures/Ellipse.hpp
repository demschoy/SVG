#pragma once

#include "Figure.hpp"

class Ellipse : public Figure
{
public:
	Ellipse(Point center, double radiusX, double radiusY, std::string color);
	Ellipse(Point center, Point radius, std::string color);
	Ellipse(double radiusX, double radiusY, std::string color);
	Ellipse(Point radius, std::string color);
	Ellipse(const Ellipse &other);
	Ellipse& operator=(const Ellipse &other);

	Point getCenterCoordinates() const;
	double getRadiusX() const;
	double getRadiusY() const;

	Figure* read(std::string fileName, int position);

	bool withinRectangle(Point rectangle, double width, double height);
	bool withinCircle(Point upperCircleCenter, double upperCircleRadius);
	
	void translate(Point translated);

	Figure* create(Point coordinate, std::string color, double radiusX, double radiusY);

	void print();
private:
	Point center;
	double radiusX;
	double radiusY;

	void copyFrom(const Ellipse &other); 
	void writeToFile(std::string fileName, Figure *figure);
};