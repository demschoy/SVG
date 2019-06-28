#pragma once

#include "./src/figures/Figure.hpp"
#include <vector>

#define CIRCLE "circle"
#define RECTANGLE "rect"
#define ELLIPSE "ellipse"
#define SVG_END "/svg>"
#define SVG_START_SYMBOL '<'

class Command
{
public:
	Command();
	
	std::fstream openFile(std::string fileName);
	void loadFile(std::fstream& file);
	void closeFile(std::fstream& file);
	void erase(int position);
	void create(std::string figureType);
private:
	std::vector<Figure*> figures;
	std::string fileName;

	void readUntilStartSymbol(std::fstream &file);
	std::string readUntilShapeFounded(std::fstream &file);
	void readShapes();
};