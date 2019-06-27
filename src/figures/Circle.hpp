#pragma once

#include "./src/figures/Figure.hpp"

class Circle : public Figure 
{
public:
	Circle(Point center, double radius, std::string color);
	Circle(double radius, std::string color);
	Circle(const Circle &other);
	Circle& operator=(const Circle &other);
	
	Point getCenterCoordinates() const;
	double getRadius() const;

	Figure* read(std::string fileName);
	bool withinRectangle(Point rectangle, double width, double height);
	bool withinCircle(Point upperCircleCenter, double upperCircleRadius);

	void translate(Point translated);

	void print();
private:
	Point center;
	double radius;

	void copyFrom(const Circle &other);
	void writeToFile(std::string fileName, Figure* figure);
};