#pragma once

#include "Figure.hpp"
#include <vector>

class Command
{
public:
	Command(std::string fileName = "figures.svg");
	
	void setFileName(std::string fileName);

	void openFile(std::string fileName, std::fstream &openedFile);
	void loadFile(std::fstream& file);
	void closeFile(std::fstream& file);
	
	void erase(int position);

	std::vector<Figure*> getFigures() const;
	
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
	void readUntilSVGStart(std::fstream &file);
	std::string readUntilShapeFounded(std::fstream &file);
	void readShapes(std::string figureType, int position);


	std::string errorClosingFileMessage = "Error closing the file ";
	std::string errorNoFigureMessage = "There is no figure number ";
	std::string errorOpeningFileMessage = "Error opening the file ";

	std::string positionMessage = " at position ";
	std::string emptyPrintMessage = "No figures to be displayed.\n";

	std::string noFiguresWithin = "No figures are located within the figure\n";

	std::string successfullyOpened = "Successfully opened file ";
	std::string successfullyLoaded = "Successfully loaded file ";
	std::string successfullyClosed = "Successfully closed file ";
	std::string successfullyErasedMessage = "Successfully erased ";
	

};