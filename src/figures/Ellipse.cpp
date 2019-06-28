#include "Ellipse.hpp"

#include <iostream>
#include <cmath>
#include <fstream>
#include <assert.h>

Ellipse::Ellipse(Point center, double radiusX, double radiusY, std::string color)
{
	this->center = center;
	this->radiusX = radiusX;
	this->radiusY = radiusY;
	this->color = color;
	this->type = ellipse;

	assert(this->radiusX >= 0 && this->radiusY >= 0);
}

Ellipse::Ellipse(Point center, Point radius, std::string color) : Ellipse(center, radius.x, radius.y, color) { }

Ellipse::Ellipse(double rx, double ry, std::string color) : Ellipse(Point(0, 0), rx, ry, color) {	}

Ellipse::Ellipse(Point radius, std::string color) : Ellipse(radius.x, radius.y, color) { }

Ellipse::Ellipse(const Ellipse &other)
{
	copyFrom(other);
}

Ellipse & Ellipse::operator=(const Ellipse &other)
{
	if (this != &other) 
	{
		copyFrom(other);
	}
	return *this;
}

Point Ellipse::getCenterCoordinates() const
{
	return center;
}

double Ellipse::getRadiusX() const
{
	return radiusX;
}

double Ellipse::getRadiusY() const
{
	return radiusY;
}

Figure * Ellipse::read(std::string fileName)
{
	std::ifstream file(fileName);

	int skippedBytes = 4;
	Point readCenter(0, 0);
	readParameter(file, skippedBytes, readCenter.x);

	skippedBytes = 5;
	readParameter(file, skippedBytes, readCenter.y);

	readSkippedBytes(file, skippedBytes);
	double readRadiusX;
	readParameter(file, skippedBytes, readRadiusX);
	
	double readRadiusY;
	readParameter(file, skippedBytes, readRadiusY);

	skippedBytes = 7;
	std::string readColour;
	readColor(file, skippedBytes, readColour);

	file.close();

	Figure* ellipse = new Ellipse(readCenter, readRadiusX, radiusY, readColour);
	return ellipse;
}

bool Ellipse::withinRectangle(Point rectangle, double width, double height)
{
	bool areSmallerThanSides = 2 * radiusY <= height && 2 * radiusX <= width;
	bool areSmallerThanWidth = center.x > rectangle.x && center.x + radiusX < width && center.x < rectangle.x + width;
	bool areSmallerThanHeight = center.y > rectangle.y && center.y + radiusY < height && center.y < rectangle.y + height;

	bool isWithin = areSmallerThanSides && areSmallerThanWidth && areSmallerThanHeight;
	return isWithin;
}

bool Ellipse::withinCircle(Point upperCircleCenter, double upperCircleRadius)
{
	double differenceX = center.x - upperCircleCenter.x;
	double differenceY = center.y - upperCircleCenter.y;
	bool areRadiusesSmaller = radiusX <= upperCircleRadius && radiusY <= upperCircleRadius;
	bool isDistanceSmaller = sqrt(differenceX * differenceX + differenceY * differenceY) <= upperCircleRadius;

	bool isWithin = isDistanceSmaller && areRadiusesSmaller;
	return isWithin;
}

void Ellipse::translate(Point translated)
{
	center.x += translated.x;
	center.y += translated.y;
}

Figure* Ellipse::create(Point coordinate, std::string color, double radiusX, double radiusY)
{
	Figure* ellipse = new Ellipse(coordinate, radiusX, radiusY, color);
	return ellipse;
}

void Ellipse::print()
{
	if (radiusX == 0 || radiusY == 0)
	{
		std::cout << "The ellipse cannot be displayed.\n";
		return;
	}

	std::cout << "Ellipse: center ";
	center.print();
	std::cout << ", radius x " << radiusX << ", radius y " << radiusY << ", color " << color << std::endl;
}

void Ellipse::copyFrom(const Ellipse &other)
{
	//TODO check for negative radius!

	center = other.center;
	radiusX = other.radiusX;
	radiusY = other.radiusY;
	color = other.color;
}

void Ellipse::writeToFile(std::string fileName, Figure *figure)
{
	std::ofstream file(fileName, std::ios_base::app || std::ios_base::ate);
	int endingPosition = findFileEndPosition(fileName) - 6;
	file.seekp(endingPosition);
	Ellipse* ellipse = (Ellipse*)(figure);
	file << "  <ellipse cx=\"" << ellipse->getCenterCoordinates().x
		<< "\" cy=\"" << ellipse->getCenterCoordinates().y
		<< "\" rx=\"" << ellipse->getRadiusX()
		<< "\" ry=\"" << ellipse->getRadiusY()
		<< "\" fill=\"" << ellipse->getColor()
		<< "\" />\n</svg>";
	std::cout << "Successfully created ellipse.\n";
	file.close();
}
