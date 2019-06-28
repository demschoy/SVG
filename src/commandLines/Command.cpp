#include "Command.hpp"

#include <fstream>
#include <iostream>

Command::Command()
{
	figures = std::vector<Figure*>();
	fileName = "output.svg";
}

void Command::loadFile(std::fstream& file)
{
	while (!file.eof())
	{
		readUntilStartSymbol(file);
		std::string text = readUntilShapeFounded(file);

		if (text == RECT || text == ELLIPSE || text == CIRCLE)
		{
			readShapes();
		}

		if (text == SVG_END)
		{
			char readSymbolEnd;
			file >> readSymbolEnd;
		}
	}
}

void Command::closeFile(std::fstream& file)
{
	if (file.eof())
	{
		try
		{
			file.close();
		}
		catch (std::fstream::failure e)
		{
			std::cerr << "Error closing the file " << fileName << std::endl;
		}
	}
}

void Command::erase(int position)
{
	if (position > figures.size())
	{
		std::cout << "There is no figure number " << position << "!\n";
		return;
	}

	std::cout << "Successfully erased " << figures[position - 1]->getType() << " at positon " << position << std::endl;
	figures.erase(figures.begin() + position - 1);
}

void Command::createCircle(Point coordinates, double radius, std::string color)
{
	Figure* circle = figures[0]->create(coordinates, color, radius);
	figures.push_back(circle);
	figures[0]->writeToFile(fileName, circle);
}

void Command::createEllipse(Point coordinates, Point radius, std::string color)
{
	Figure* ellipse = figures[0]->create(coordinates, color, radius.x, radius.y);
	figures.push_back(ellipse);
	figures[0]->writeToFile(fileName, ellipse);
}

void Command::createRectangle(Point coordinates, double width, double height, std::string color)
{
	Figure* rectangle = figures[0]->create(coordinates, color, width, height);
	figures.push_back(rectangle);
	figures[0]->writeToFile(fileName, rectangle);
}

std::vector<Figure*> Command::withinCircle(Point center, double radius)
{
	std::vector<Figure*> withinFigure;
	int size = figures.size();
	for (int i = 0; i < size; i++)
	{
		if (figures[i]->withinCircle(center, radius))
		{
			withinFigure.push_back(figures[i]);
		}
	}
	return withinFigure;
}

std::vector<Figure*> Command::withinRectangle(Point coordinates, double width, double height)
{
	std::vector<Figure*> withinFigure;
	int size = figures.size();
	for (int i = 0; i < size; i++)
	{
		if (figures[i]->withinRectangle(coordinates, width, height))
		{
			withinFigure.push_back(figures[i]);
		}
	}
	return withinFigure;
}

void Command::translate(Point translated, std::string figureType)
{
	int size = figures.size();
	for (int i = 0; i < size; i++)
	{
		if (figureType == ALL_FIGURES || figures[i]->getType() == figureType)
		{
			figures[i]->translate(translated);
		}
	}

}

void Command::print()
{
	int size = 0;
	for (int i = 0; i < size; i++)
	{
		figures[i]->print();
	}
}

void Command::deleteFigures()
{
	int size = figures.size();
	for (int i = 0; i < size; i++)
	{
		delete figures[i];
	}
	figures.clear();
}


void Command::readUntilStartSymbol(std::fstream &file)
{
	char peekedSymbol = file.peek(), readSymbol;
	while (peekedSymbol != SVG_START_SYMBOL)
	{
		file >> readSymbol;
		peekedSymbol = file.peek();
	}
	file >> readSymbol;
}

std::string Command::readUntilShapeFounded(std::fstream &file)
{
	std::string text;
	file >> text;

	while (text != RECT && text != ELLIPSE && text != CIRCLE && text != SVG_END)
	{
		char readSymbol;
		file >> readSymbol >> text;
	}
	return text;
}

void Command::readShapes()
{
	Figure* figure = figures[0]->read(fileName);
	figures.push_back(figure);
}

void Command::openFile(std::string fileName, std::fstream &openedFile)
{
	try
	{
		openedFile.open(fileName);
		openedFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	}
	catch (std::fstream::failure e)
	{
		std::cerr << "Error opening the file " << fileName << std::endl;
	}
}
