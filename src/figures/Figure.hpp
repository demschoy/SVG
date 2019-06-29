#pragma once

#include <string>

#include "Point.hpp"

class Figure 
{
public:
	enum FigureTypes
	{
		ellipse,
		rectangle,
		circle
	};

	static int findFileEndPosition(std::string fileName);
	
	virtual std::string getType() const;
	virtual std::string getColor() const;

	void setType(FigureTypes type);
	void setColor(std::string color);

	virtual Figure* read(std::string fileName, int position) = 0;

	virtual bool withinRectangle(Point rectangle , double width, double height) = 0;
	virtual bool withinCircle(Point upperCircleCenter, double upperCircleRadius) = 0;
	virtual void translate(Point translated) = 0;

	virtual Figure* create(Point coordinate, std::string color, double firstParameter1, double secondParameter = 0) = 0;

	virtual void print() = 0;

	virtual void writeToFile(std::string fileName, Figure *figure) = 0;
protected:
	std::string color;
	FigureTypes type;
	
	void readSkippedBytes(std::ifstream &file, int skippedBytes);
	void readParameter(std::ifstream &file, int skippedBytes, double& parameter);
	void readColor(std::ifstream &file, int skippedBytes, std::string& color);
};