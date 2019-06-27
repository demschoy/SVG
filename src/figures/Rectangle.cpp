#include "./src/figures/Rectangle.hpp"

#include <iostream>
#include <fstream>

Rectangle::Rectangle(Point coordinates, double width, double height, std::string color, Point roundedCoordinates)
{
	//TODO check for negatives.

	this->coordinates = coordinates;
	this->width = width;
	this->height = height;
	this->color = color;
	this->roundedCoordinates = roundedCoordinates;
}

Rectangle::Rectangle(double width, double height, std::string color, Point roundedCoordinates) 
	: Rectangle(Point(0, 0), width, height, color, roundedCoordinates) {	}

Rectangle::Rectangle(const Rectangle &other)
{
	copyFrom(other);
}

Rectangle& Rectangle::operator=(const Rectangle &other)
{
	if (this != &other)
	{
		copyFrom(other);
	}
	return *this;
}

Point Rectangle::getCoordinates() const
{
	return coordinates;
}

Point Rectangle::getRoundedCoordinates() const
{
	return roundedCoordinates;
}

double Rectangle::getWidth() const
{
	return width;
}

double Rectangle::getHeight() const
{
	return height;
}

Figure * Rectangle::read(std::string fileName)
{
	std::ifstream file(fileName);
	
	int skippedBytes = 3;
	Point readCoordinates;
	readParameter(file, skippedBytes, readCoordinates.x);

	skippedBytes = 4;
	readParameter(file, skippedBytes, readCoordinates.y);

	skippedBytes = 8;
	double readWidth;
	readParameter(file, skippedBytes, readWidth);
	
	skippedBytes = 9;
	double readHeight;
	readParameter(file, skippedBytes, readHeight);

	skippedBytes = 7;
	std::string readColour;
	readColor(file, skippedBytes, readColour);

	Figure* rectangle = new Rectangle(readCoordinates, readWidth, readHeight, readColour);
	return rectangle;
}

bool Rectangle::withinRectangle(Point rectangle, double width, double height)
{
	bool areCoordinatesSmaller = coordinates.x >= rectangle.x && coordinates.y >= rectangle.y;

	bool isWithin = areCoordinatesSmaller && this->width <= width && this->height <= height;
	return isWithin;
}

bool Rectangle::withinCircle(Point upperCircleCenter, double upperCircleRadius)
{
	bool isSmallerWidth = coordinates.x + width < upperCircleRadius;
	bool isSmallerHeight = coordinates.y + height < upperCircleRadius;
	double squaredSum = coordinates.x * coordinates.x + coordinates.y * coordinates.y;
	bool isSquaredSmallerThanRadius = sqrt(squaredSum) <= upperCircleRadius;

	bool isWithin = isSquaredSmallerThanRadius || (isSmallerWidth && isSmallerHeight);
	return isWithin;
}

void Rectangle::translate(Point translated)
{
	coordinates.x += translated.x;
	coordinates.y += translated.y;
}

void Rectangle::print()
{
	if (width == 0 || height == 0)
	{
		std::cout << "The rectangle cannot be displayed.\n";
		return;
	}
	std::cout << "Rectangle: center ";
	coordinates.print();
	std::cout << ", width " << width << ", height " << height << ", color " << color;
	if (roundedCoordinates.x != DEFAULT_X && roundedCoordinates.y != DEFAULT_Y)
	{
		std::cout << ", rounded coordinates ";
		roundedCoordinates.print();
	}
	std::cout << std::endl;

}

void Rectangle::copyFrom(const Rectangle &other)
{
	coordinates = other.coordinates;
	width = other.width;
	height = other.height;
	color = other.color;
	roundedCoordinates = other.roundedCoordinates;
}

void Rectangle::writeToFile(std::string fileName, Figure *figure)
{
	std::ofstream file(fileName, std::ios_base::app || std::ios_base::ate);
	int endingPosition = findFileEndPosition(fileName) - 6;
	file.seekp(endingPosition);
	Rectangle* rectangle = (Rectangle*)(figure);
	file << "  <rect x=\"" << rectangle->getCoordinates().x
		<< "\" y=\"" << rectangle->getCoordinates().y
		<< "\" width=\"" << rectangle->getWidth()
		<< "\" height=\"" << rectangle->getHeight()
		<< "\" fill=\"" << rectangle->getColor()
		<< "\" />\n</svg>";

	std::cout << "Successfully created rectangle.\n";
	file.close();
}
