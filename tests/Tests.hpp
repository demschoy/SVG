#pragma once

#include "Menu.hpp"
#include "Command.hpp"
#include "Figure.hpp"
#include "Circle.hpp"
#include "Ellipse.hpp"
#include "Rectangle.hpp"

#include <iostream>

int testsCounter = 0;
int failedTestsCounter = 0;

class UnitTests {
public:
	template <typename T>
	static void AssertEqual(T expected, T value)
	{
		testsCounter++;
		if (expected != value) 
		{
			std::cerr << "FAIL(" << testsCounter << "): Values mismatch!"
				<< "\n-- expected: " << expected << "\n---- actual: " << value << std::endl;
			failedTestsCounter++;
		}
		else 
		{
			std::cout << "." << std::endl;
		}
	}

	static void PrintTestsResult() {
		if (failedTestsCounter)
			std::cout << "Failure: ";
		else
			std::cout << "Success: ";
		std::cout << testsCounter - failedTestsCounter << "|" << testsCounter << " tests." << std::endl;
	}
};

void testOpenFile()
{
	std::cout << "Test open file\n";
	Command command;
	std::string fileName = "figures.svg";
	std::fstream file;
	
	command.openFile(fileName, file);
	bool value = file.is_open();
	bool expected = true;
	UnitTests::AssertEqual(expected, value);
	file.close();
}

void testLoadFile()
{
	std::cout << "Test load file\n";
	Command command;
	std::string fileName = "figures.svg";
	std::fstream file;

	command.openFile(fileName, file);
	command.setFileName(fileName);
	command.loadFile(file);

	std::vector<Figure*> figures = command.getFigures();
	int expected = 3;
	int value = figures.size();
	UnitTests::AssertEqual(expected, value);
	file.close();
}

void testEraseFigure()
{
	std::cout << "Test erasing figure\n";
	Command command;
	std::string fileName = "figures.svg";
	std::fstream file;
	command.openFile(fileName, file);
	command.setFileName(fileName);

	command.loadFile(file);
	std::vector<Figure*> figures = command.getFigures();

	UnitTests::AssertEqual(3, (int)figures.size());
	UnitTests::AssertEqual((std::string)RECTANGLE, figures[0]->getType());
	UnitTests::AssertEqual((std::string)CIRCLE, figures[1]->getType());
	UnitTests::AssertEqual((std::string)RECTANGLE, figures[2]->getType());

	command.erase(1);
	figures = command.getFigures();
	UnitTests::AssertEqual(2, (int)figures.size());
	UnitTests::AssertEqual((std::string)CIRCLE, figures[0]->getType());

	command.erase(9);
	UnitTests::AssertEqual(2, (int)figures.size());
	file.close();
}

void testCreateCircle()
{
	std::cout << "Test creating circles\n";
	Command command;
	command.setFileName("svg.svg");

	std::vector<Figure*> figures = command.getFigures();

	UnitTests::AssertEqual(0, (int)figures.size());

	Point center(0, 0);
	double radius = 5;
	std::string color = "red";
	command.createCircle(center, radius, color);
	figures = command.getFigures();

	UnitTests::AssertEqual(1, (int)figures.size());
	UnitTests::AssertEqual((std::string)CIRCLE, figures[0]->getType());
	UnitTests::AssertEqual((std::string)"red",figures[0]->getColor());

	Circle* circle = (Circle*)figures[0];
	UnitTests::AssertEqual(0.0, circle->getCenterCoordinates().x);
	UnitTests::AssertEqual(0.0, circle->getCenterCoordinates().y);
	UnitTests::AssertEqual(5.0, circle->getRadius());
}

void testCreateRectangle()
{
	std::cout << "Test creating rectangles\n";
	Command command;
	command.setFileName("svg.svg");

	std::vector<Figure*> figures = command.getFigures();

	UnitTests::AssertEqual(0, (int)figures.size());

	Point coordinated(0, 0);
	double width = 2, height = 3;
	std::string color = "blue";

	command.createRectangle(coordinated, width, height, color);
	figures = command.getFigures();

	UnitTests::AssertEqual(1, (int)figures.size());
	UnitTests::AssertEqual((std::string)RECTANGLE, figures[0]->getType());
	UnitTests::AssertEqual((std::string)"blue", figures[0]->getColor());
}

void testCreateEllipse()
{
	std::cout << "Test creating ellipses\n";
	Command command;
	command.setFileName("svg.svg");

	std::vector<Figure*> figures = command.getFigures();

	UnitTests::AssertEqual(0, (int)figures.size());
	Point ellipseCenter(3, 4);
	double radiusX = 3, radiusY = 2;
	std::string color = "green";
	command.createEllipse(ellipseCenter, Point(radiusX, radiusY), color);
	figures = command.getFigures();

	UnitTests::AssertEqual(1, (int)figures.size());
	UnitTests::AssertEqual((std::string)ELLIPSE, figures[0]->getType());
	UnitTests::AssertEqual((std::string)"green", figures[0]->getColor());
}

void testTranslate()
{
	std::cout << "Test translating figures\n";
	Command command;
	std::string fileName = "figures.svg";
	std::fstream file;
	command.openFile(fileName, file);
	command.setFileName(fileName);

	command.loadFile(file);
	std::vector<Figure*> figures = command.getFigures();
	
	Circle* secondFigure = (Circle*)(figures[1]);
	UnitTests::AssertEqual(5.0, secondFigure->getCenterCoordinates().x);
	UnitTests::AssertEqual(5.0, secondFigure->getCenterCoordinates().y);
	UnitTests::AssertEqual(10.0, secondFigure->getRadius());
	UnitTests::AssertEqual((std::string)"blue", secondFigure->getColor());

	Point translated(1, 2);
	command.translate(translated);
	UnitTests::AssertEqual(6.0, secondFigure->getCenterCoordinates().x);
	UnitTests::AssertEqual(7.0, secondFigure->getCenterCoordinates().y);
	UnitTests::AssertEqual(10.0, secondFigure->getRadius());
	UnitTests::AssertEqual((std::string)"blue", secondFigure->getColor());
	
	command.translate(translated, "ellipse");
	UnitTests::AssertEqual(6.0, secondFigure->getCenterCoordinates().x);
	UnitTests::AssertEqual(7.0, secondFigure->getCenterCoordinates().y);
	UnitTests::AssertEqual(10.0, secondFigure->getRadius());
	UnitTests::AssertEqual((std::string)"blue", secondFigure->getColor());
	file.close();
}

void testWithinCircle()
{
	std::cout << "Test figures within circle\n";
	Command command;
	std::string fileName = "figures.svg";
	command.setFileName(fileName);
	std::fstream file;
	command.openFile(fileName, file);
	command.loadFile(file);
	std::vector<Figure*> figures = command.getFigures();

	std::vector<Figure*> withinFigures = command.withinCircle(Point(0, 0), 5);
	UnitTests::AssertEqual(0, (int)withinFigures.size());
	file.close();
}

void testWithinRectangle()
{
	std::cout << "Test figures within rectangle\n";
	Command command;
	std::string fileName = "figures.svg";
	command.setFileName(fileName);
	std::fstream file;
	command.openFile(fileName, file);
	command.loadFile(file);
	std::vector<Figure*> figures = command.getFigures();

	std::vector<Figure*> withinFigures = command.withinRectangle(Point(0, 0), 30, 30);

	UnitTests::AssertEqual(2, (int)withinFigures.size());
	UnitTests::AssertEqual((std::string)RECTANGLE, withinFigures[0]->getType());
	UnitTests::AssertEqual((std::string)"green", withinFigures[0]->getColor());
	file.close();
}

void testCloseFile()
{
	std::cout << "Test closing file\n";
	Command command;
	std::string fileName = "figures.svg";
	command.setFileName(fileName);
	std::fstream file;
	command.openFile(fileName, file);
	
	bool expected = true;
	bool value = file.is_open();
	UnitTests::AssertEqual(expected, value);
	
	command.closeFile(file);
	expected = false;
	value = file.is_open();
	UnitTests::AssertEqual(expected, value);
}

