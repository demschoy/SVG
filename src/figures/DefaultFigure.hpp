#pragma once

#include "Circle.hpp"
#include "Rectangle.hpp"
#include "Ellipse.hpp"

Figure* getDefaultFigure(std::string figureType)
{
	Figure* validFigure = nullptr;
	if (figureType == CIRCLE)
	{
		validFigure = new Circle(Point(DEFAULT_X, DEFAULT_Y), 0, DEFAULT_COLOR);
	}
	if (figureType == RECT)
	{
		validFigure = new Rectangle(Point(DEFAULT_X, DEFAULT_Y), 0, 0, DEFAULT_COLOR);
	}
	if (figureType == ELLIPSE)
	{
		validFigure = new Ellipse(Point(DEFAULT_X, DEFAULT_Y), Point(DEFAULT_X, DEFAULT_Y), DEFAULT_COLOR);
	}
	return validFigure;

}