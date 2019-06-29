#pragma once

#include <string>

#define ALL_FIGURES "all figures"
#define	RECTANGLE "rectangle"
#define RECT "rect"
#define CIRCLE "circle"
#define ELLIPSE "ellipse"

#define DEFAULT_X 0.0
#define DEFAULT_Y 0.0
#define DEFAULT_COLOR "no color"

#define SVG_START_SYMBOL '<'
#define SVG_END "/svg>"
#define SVG_START_WORD "<svg>"

std::string printEllipseCenter = "Ellipse, center ";
std::string printEllipseRadiusX = ", radius x ";
std::string printEllipseRadiusY = ", radius y ";
std::string printColor = ", color ";
std::string printCircleCenter = "Circle, center ";
std::string printRadius = ", radius ";
std::string printWidth = ", width ";
std::string printHeight = ", height ";
std::string printRoundedCoordinates = ", rounded coordinates ";
std::string printRectangleCoordinates = "Rectangle, coordinates ";

std::string successfullyOpened = "Successfully opened file ";
std::string successfullyLoaded = "Successfully loaded file ";
std::string successfullyClosed = "Successfully closed file ";
std::string successfullyErasedMessage = "Successfully erased ";
std::string successfullyCreatedMessage = "Successfully created ";

std::string errorWritingToFileMessage = "Error writing to the file ";
std::string errorReadingFileMessage = "Error reading the file ";
std::string errorClosingFileMessage = "Error closing the file ";
std::string errorNoFigureMessage = "There is no figure number ";
std::string errorPrintingFigure = "The figure cannot be displayed.\n";
std::string errorClosingFileMessage = "Error closing the file ";
std::string errorOpeningFileMessage = "Error opening the file ";

std::string positionMessage = " at position ";
std::string emptyPrintMessage = "No figures to be displayed.\n";

std::string noFiguresWithin = "No figures are located within the figure\n";

std::string welcomeMessage = "Welcome to SVG. \n";
std::string continueMessage = "Do you want to continue? Enter from 0 from 8.\n";
std::string suggestedLoading = "If you want to load the file, please enter 1: ";
std::string endingMessage = "Thank you for using SVG. \n";

std::string operationList = "Please choose operation. \n";
std::string openMessage = "For OPEN enter: 0\n";
std::string loadMessage = "For LOAD enter: 1\n";
std::string createMessage = "For CREATE enter 2\n";
std::string eraseMessage = "For ERASE enter 3\n";
std::string withinMessage = "For WITHIN enter 4\n";
std::string translateMessage = "For TRANSLATE enter 5\n";
std::string printMessage = "For PRINT enter 6\n";
std::string closeMessage = "For CLOSE enter 7\n";
std::string exitMessage = "For EXIT enter 8\n";

std::string operationsMessage = openMessage + loadMessage + createMessage + eraseMessage + withinMessage +
							translateMessage + printMessage + closeMessage + exitMessage;

std::string invalidOperationSelected = "The selected operation is invalid. Please try again.\n";

std::string alreadyLoaded = "File is already loaded.\n";
std::string alreadyOpened = "File is already opened.\n";

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

