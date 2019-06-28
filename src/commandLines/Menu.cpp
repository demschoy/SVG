#include "Menu.hpp"

#include <iostream>
#include <fstream>

void Menu::program()
{
	std::cout << welcomeMessage << operationList;
	std::cout << operationsMessage;

	std::cin >> commandCode;
	while (commandCode != 8)
	{
		switch (commandCode)
		{
		case 0: operationOpen(); break;
		case 1: operationLoad(); break;
		case 2: operationCreate();  break;
		case 3: operationErase(); break;
		case 4: operationWithin(); break;
		case 5: operationTranslate(); break;
		case 6: operationPrint(); break;
		case 7: operationClose(); break;
		default:
			invalidOperation();
		}
		std::cin >> commandCode;
	}

}

void Menu::operationOpen()
{
	if (isOpened)
	{
		std::cout << alreadyOpened;
		return;
	}
	
	std::cout << enterFileName;
	std::cin >> fileName;
	try
	{
		command.openFile(fileName, file);
		isOpened = true;
		std::cout << successfullyOpened << fileName << std::endl;

		std::cout << suggestedLoading;
	}
	catch (std::fstream::failure e)
	{
		std::cerr << "Error opening the file " << fileName << std::endl;
	}
}

void Menu::operationLoad()
{
	if (isLoaded)
	{
		std::cout << alreadyOpened;
		return;
	}
	
	command.loadFile(file);
	isLoaded = true;
	std::cout << successfullyLoaded << fileName << std::endl;
	std::cout << continueMessage;
}

void Menu::operationCreate()
{
	std::cout << enterCreatedFigureType;
	std::string type;
	std::cin >> type;
	
	std::cout << enterColor;
	std::string color;
	std::cin >> color;

	if (type == CIRCLE)
	{
		Point coordinates;
		double radius;
		enterCircle(coordinates, radius);
		command.createCircle(coordinates, radius, color);
	}
	if (type == RECTANGLE)
	{
		Point coordinates;
		double width, height;
		enterRectangle(coordinates, width, height);
	}
	if (type == ELLIPSE)
	{
		Point coordinatesCenter, radius;
		enterEllipse(coordinatesCenter, radius);
		command.createEllipse(coordinatesCenter, radius, color);
	}
}

void Menu::operationErase()
{
	std::cout << enterErasePosition;
	int position;
	std::cin >> position;
	
	command.erase(position);
}

void Menu::operationWithin()
{
	std::cout << enterWithinFigure;
	std::string figureType;
	std::cin >> figureType;

	if (figureType == RECTANGLE)
	{
		Point coordinates;
		double width, height;
		enterRectangle(coordinates, width, height);

		std::vector<Figure*> withinFigures = command.withinRectangle(coordinates, width, height);
		printWithinFigures(withinFigures);
	}
	if (figureType == CIRCLE)
	{
		Point coordinates;
		double radius;
		enterCircle(coordinates, radius);

		std::vector<Figure*> withinFigures = command.withinCircle(coordinates, radius);
		printWithinFigures(withinFigures);
	}
}

void Menu::printWithinFigures(std::vector<Figure*> withinFigures)
{
	int size = withinFigures.size();
	if (size == 0)
	{
		std::cout << noFiguresWithin;
		return;
	}

	for (int i = 0; i < size; i++)
	{
		withinFigures[i]->print();
	}
}

void Menu::operationTranslate()
{
	std::cout << enterTranslatedFigureType;
	std::string type;
	std::cin >> type;

	std::cout << std::endl << enterTranslatedCoordinates;
	Point translated;
	std::cin >> translated.x >> translated.y;
	
	command.translate(translated, type);
}

void Menu::operationPrint()
{
	command.print();
}

void Menu::operationClose()
{
	try
	{
		command.closeFile(file);
		command.deleteFigures();
		isOpened = false;
		isLoaded = false;
		std::cout << successfullyClosed << fileName << std::endl;
	}
	catch(std::fstream::failure e)
	{
		std::cerr << "Error closed the file " << fileName << std::endl;
	}
}

void Menu::invalidOperation()
{
	std::cout << invalidOperationSelected;
}

void Menu::enterRectangle(Point &coordinates, double &width, double &height)
{
	std::cout << enterRectangleCoordinates;
	std::cin >> coordinates.x >> coordinates.y;

	std::cout << std::endl << enterWidth;
	std::cin >> width;

	std::cout << std::endl << enterHeight;
	std::cin >> height;
}

void Menu::enterCircle(Point & centerCoordinates, double &radius)
{
	std::cout << enterCircleCoordinates;
	std::cin >> centerCoordinates.x >> centerCoordinates.y;

	std::cout << std::endl << enterRadius;
	std::cin >> radius;
}

void Menu::enterEllipse(Point &centerCoordinates, Point &radius)
{
	std::cout << enterEllipseCoordinates;
	Point coordinates;
	std::cin >> centerCoordinates.x >> centerCoordinates.y;

	std::cout << std::endl << enterEllipseRadius;
	std::cin >> radius.x >> radius.y;

}
