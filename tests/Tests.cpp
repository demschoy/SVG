#pragma once


#include "Tests.hpp"

void executingTests()
{
	testOpenFile();
	testLoadFile();
	testCloseFile();
	testEraseFigure();
	testTranslate();
	testWithinCircle();
	testWithinRectangle();
	testCreateCircle();
	testCreateEllipse();
	testCreateRectangle();
	UnitTests::PrintTestsResult();
}

int main()
{
	executingTests();

	return 0;
	
}