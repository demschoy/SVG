#pragma once

#include <string>
#include <fstream>

#include "Command.hpp"

#define RECTANGLE "rectangle"

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
	std::string welcomeMessage = "Welcome to SVG. \n";
	std::string operationList = "Please choose operation: \n";
	std::string openMessage = "For OPEN enter: 0\n";
	std::string loadMessage = "For LOAD enter: 1\n";
	std::string createMessage = "For CREATE enter 2\n";
	std::string eraseMessage = "For ERASE enter 3\n";
	std::string withinMessage = "For WITHIN enter 4\n";
	std::string translateMessage = "For TRANSLATE enter 5\n";
	std::string printMessage = "For PRINT enter 6\n";
	std::string closeMessage = "For CLOSE enter 7\n";
	std::string exitMessage = "For EXIT enter 8\n";
	
	std::string invalidOperationSelected = "The selected operation is invalid. Please try again.\n";
	std::string alreadyLoaded = "File is already loaded.\n";
	std::string alreadyOpened = "File is already opened.\n";

	std::string continueMessage = "Do you want to continue? Enter from 0 from 8.\n";
	
	std::string enterFileName = "Please enter file name: ";
	std::string enterErasePosition = "Please enter the position of the figure to be erased: ";
	std::string enterWithinFigure = "Please enter within figure - rectangle or circle: ";
	std::string enterRectangleCoordinates = "Please enter rectangle coordinates: ";
	std::string enterWidth = "Please enter rectangle width: ";
	std::string enterHeight = "Please enter rectangle height: ";
	std::string enterCircleCoordinates = "Please enter circle center coordinates: ";
	std::string enterRadius = "Please enter circle radius: ";
	std::string enterEllipseCoordinates = "Please enter ellipse center: ";
	std::string enterEllipseRadius = "Please enter ellipse radiuses: ";
	std::string enterTranslatedFigureType = "Please enter figure type to be translated - circle, rect, ellipse or all figures: ";
	std::string enterTranslatedCoordinates = "Please enter coordinates of the translating point: ";
	std::string enterCreatedFigureType = "Please enter a figure you want to create - circle, rectangle, ellipse: ";
	std::string enterColor = "Please enter color: ";

	std::string successfullyOpened = "Successfully opened file ";
	std::string successfullyLoaded = "Successfully loaded file ";
	std::string successfullyClosed = "Successfully closed file ";
	
	std::string suggestedLoading = "If you want to load the file, please enter 1.";
	
	std::string noFiguresWithin = "No figures are located within the figure\n";

	std::string operationsMessage = openMessage + loadMessage + createMessage + eraseMessage + withinMessage +
		translateMessage + printMessage + closeMessage + exitMessage; 

	void operationOpen();
	void operationLoad();
	void operationCreate();
	void operationErase();
	void operationWithin();
	void printWithinFigures(std::vector<Figure*> withinFigures);
	void operationTranslate();
	void operationPrint();
	void operationClose();
	void invalidOperation();

	void enterRectangle(Point &coordinates, double &width, double &height);
	void enterCircle(Point &centerCoordinates, double &radius);
	void enterEllipse(Point &centerCoordinates, Point &radius);
};