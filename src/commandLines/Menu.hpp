#pragma once

#include <string>
#include <fstream>

#include "Command.hpp"

class Menu
{
public:
	void program();

private:
	Command command;
	int commandCode;
	std::string fileName;
	std::fstream file;

	bool isOpened = false;
	bool isLoaded = false;

	void operationOpen();
	void operationLoad();
	void operationCreate();
	void operationErase();
	void operationWithin();
	void printWithinFigures(std::vector<Figure*> withinFigures);
	void operationTranslate();
	void operationPrint();
	void operationClose();
	void operationExit();
	void invalidOperation();

	void enterRectangle(Point &coordinates, double &width, double &height);
	void enterCircle(Point &centerCoordinates, double &radius);
	void enterEllipse(Point &centerCoordinates, Point &radius);
};