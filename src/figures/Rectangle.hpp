#pragma once

#include "Figure.hpp"

class Rectangle : public Figure
{
public:
	Rectangle(Point coordinates, double width, double height, std::string color, Point roundedCoordinates = Point());
	Rectangle(double width, double height, std::string color, Point roundedCoordinates = Point());
	Rectangle(const Rectangle &other);
	Rectangle& operator=(const Rectangle &other);
	
	Point getCoordinates() const;
	Point getRoundedCoordinates() const;
	double getWidth() const;
	double getHeight() const;

	Figure* read(std::string fileName);

	bool withinRectangle(Point rectangle, double width, double height);
	bool withinCircle(Point upperCircleCenter, double upperCircleRadius);

	void translate(Point translated);

	Figure* create(Point coordinate, std::string color, double width, double height);

	void print(); 
private:
	Point coordinates;
	double height;
	double width;
	Point roundedCoordinates;

	void copyFrom(const Rectangle &other);
	void writeToFile(std::string fileName, Figure *figure);

	void errorProperlySpecifiedRounded(Point &rounded);
	void errorLongerSide(double &roundedSide, double &side);
};