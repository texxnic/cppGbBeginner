#pragma once

#include "OffTheField.h"
#include "IllegalCommand.h"

#include <iostream>

class Robot
{
private:
	const int iN = 10;
	std::string** ptrArr;
	std::string robotDown = "\\['-']/";
	std::string robotUp = " \\[ ]/ ";
	std::string robotLeft = "\\['-'\\]";
	std::string robotRight = "[/'-']/";
	std::string robotError = "\\['o']/";
	std::string robotIllegal = "/[-_-]\\";
	std::string robot = "~[^-^]~";
	bool isRobotOver;
	
	struct Position
	{
		int x,
			y;
	};

	enum class eDirection 
	{ 
		STOP = 0,
		LEFT,
		RIGHT,
		UP,
		DOWN 
	};
	
public:
	eDirection route;
	Position pos;
	Robot();
	void printField();
	void robotMovement();
	void Input();
	void Logic();
	void ClearScreen();
	~Robot();
};

