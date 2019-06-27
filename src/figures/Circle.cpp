#include "./src/figures/Circle.hpp"

#include <iostream>
#include <cmath>
#include <fstream>

Circle::Circle(Point center, double radius, std::string color)
{
	//TODO check for negative radius!

	this->center = center;
	this->radius = radius;
	this->color = color;
}

Circle::Circle(double radius, std::string color) : Circle(Point(0, 0), radius, color) {	}

Circle::Circle(const Circle &other)
{
	copyFrom(other);
}

Circle& Circle::operator=(const Circle &other)
{
	if (this != &other)
	{
		copyFrom(other);
	}
	return *this;
}

Point Circle::getCenterCoordinates() const
{
	return center;
}

double Circle::getRadius() const
{
	return radius;
}

Figure* Circle::read(std::string fileName)
{
	std::ifstream file(fileName);
	
	int skippedBytes = 4;
	Point readCenter(0, 0);
	readParameter(file, skippedBytes, readCenter.x);

	skippedBytes = 5;
	readParameter(file, skippedBytes, readCenter.y);

	skippedBytes = 4;
	double readRadius;
	readParameter(file, skippedBytes, readRadius);

	skippedBytes = 7;
	std::string readColour;
	readColor(file, skippedBytes, readColour);

	file.close();

	Figure* circle = new Circle(center, readRadius, readColour);
	return circle;
}

bool Circle::withinRectangle(Point rectangle, double width, double height)
{
	bool areSmallerThanSides = 2 * radius < width && 2 * radius < height;
	bool areSmallerThanWidth = center.x + radius < width + rectangle.x && center.x >= rectangle.x;
	bool areSmallerThanHeight = center.y <= rectangle.y && center.x - radius > rectangle.y + height;

	bool isWithin = areSmallerThanSides && areSmallerThanWidth && areSmallerThanHeight;
	return isWithin;
}

bool Circle::withinCircle(Point upperCircleCenter, double upperCircleRadius)
{
	double differenceX = upperCircleCenter.x - center.x;
	double differenceY = upperCircleCenter.y - center.y;
	double differenceRadius = upperCircleRadius - radius;

	bool isWithin = sqrt(differenceX * differenceX + differenceY * differenceY) <= differenceRadius;
	return isWithin;
}

void Circle::translate(Point translated)
{
	center.x += translated.x;
	center.y += translated.y;
}

void Circle::print()
{
	if (radius == 0)
	{
		std::cout << "The circle cannot be displayed.\n";
		return;
	}

	std::cout << "Circle: center ";
	center.print();
	std::cout<< ", radius " << radius << ", color " << color << std::endl;
}

void Circle::copyFrom(const Circle &other)
{
	center = other.center;
	radius = other.radius;
	color = other.color;

	//TODO check for negative radius!
}

void Circle::writeToFile(std::string fileName, Figure *figure)
{
	std::ofstream file(fileName, std::ios_base::app || std::ios_base::ate);
	int endingPosition = findFileEndPosition(fileName) - 6;
	file.seekp(endingPosition);
	Circle* circle = (Circle*)(figure);
	file << "  <circle cx=\"" << circle->getCenterCoordinates().x
		<< "\" cy=\"" << circle->getCenterCoordinates().y
		<< "\" r=\"" << circle->getRadius()
		<< "\" fill=\"" << circle->getColor()
		<< "\" />\n</svg>";
	std::cout << "Successfully created circle.\n";
	file.close();
}
