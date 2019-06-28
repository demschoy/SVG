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

		if (text == RECTANGLE || text == ELLIPSE || text == CIRCLE)
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
		file.close();
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

void Command::create(std::string figureType)
{
	//TODO
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

	while (text != RECTANGLE && text != ELLIPSE && text != CIRCLE && text != SVG_END)
	{
		char readSymbol;
		file >> readSymbol >> text;
	}
	return text;
}

void Command::readShapes()
{
	Figure* figure;
	figures.push_back(figure->read(fileName));
}

std::fstream Command::openFile(std::string fileName)
{
	std::fstream file;
	file.open(fileName);
	return file;
}
