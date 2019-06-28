#pragma once

#include "Figure.hpp"
#include <vector>

#define CIRCLE "circle"
#define RECT "rect"
#define ELLIPSE "ellipse"
#define SVG_END "/svg>"
#define SVG_START_SYMBOL '<'
#define ALL_FIGURES "all figures"

class Command
{
public:
	Command();
	
	void openFile(std::string fileName, std::fstream &openedFile);
	void loadFile(std::fstream& file);
	void closeFile(std::fstream& file);
	
	void erase(int position);
	
	void createCircle(Point coordinates, double radius, std::string color);
	void createEllipse(Point coordinates, Point radius, std::string color);
	void createRectangle(Point coordinates, double width, double height, std::string color);
	
	std::vector<Figure*> withinCircle(Point center, double radius);
	std::vector<Figure*> withinRectangle(Point coordinates, double width, double height);
	
	void translate(Point translated, std::string figureType = ALL_FIGURES);
	
	void print();

	void deleteFigures();
private:
	std::vector<Figure*> figures;
	std::string fileName;

	void readUntilStartSymbol(std::fstream &file);
	std::string readUntilShapeFounded(std::fstream &file);
	void readShapes();
};