#include "./src/figures/Figure.hpp"

#include <fstream>

int Figure::findFileEndPosition(std::string fileName)
{
	std::ifstream file(fileName, std::ios_base::app);
	file.seekg(0, std::ios_base::end);
	std::ios_base::streampos endPosition = file.tellg();
	file.close();

	return endPosition;
}

std::string Figure::getType() const
{
	switch (type)
	{
	case eclipse: return "eclipse"; break;
	case rectangle: return "rectangle"; break;
	case circle: return "eclipse"; break;
	}
}

std::string Figure::getColor() const
{
	return color;
}

void Figure::setType(FigureTypes type)
{
	this->type = type;
}

void Figure::setColor(std::string color)
{
	this->color = color;
}

void Figure::readSkippedBytes(std::ifstream &file, int skippedBytes)
{
	char skipped;
	for (int i = 0; i < skippedBytes; i++)
	{
		file >> skipped;
	}
}

void Figure::readParameter(std::ifstream &file, int skippedBytes, double &parameter)
{
	readSkippedBytes(file, skippedBytes);
	file >> parameter;
}

void Figure::readColor(std::ifstream &file, int skippedBytes, std::string &color)
{
	readSkippedBytes(file, skippedBytes);
	file >> color;
	color.pop_back();
}

