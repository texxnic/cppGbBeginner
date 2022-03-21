#include "Robot.h"

#include <conio.h>
#include <windows.h>

Robot::Robot()
{
	ptrArr = new std::string *[iN];
	for (int i = 0; i < iN; i++)
	{
		ptrArr[i] = new std::string[iN];
	}

	system("pause");
	for (int i = 0; i < iN; i++)
	{
		for (int j = 0; j < iN; j++)
		{
			ptrArr[i][j] = "   .   ";
		}
	}
	pos.x = 0;
	pos.y = 0;
	ptrArr[pos.y][pos.x] = robot;
	isRobotOver = false;
	route = eDirection::STOP;
}

void Robot::robotMovement()
{
	do
	{
		ClearScreen();
		printField();
		try
		{
			Input();
		}
		catch (OffTheField &f)
		{
			std::cout << "Error! " << f.getError();
			system("pause");
		}
		catch (IllegalCommand &c)
		{
			std::cout << "Error! " << c.getError();
			system("pause");
		}
	} while (!isRobotOver);
}

void Robot::Logic()
{
	ptrArr[pos.y][pos.x] = "   .   ";
	if (isRobotOver)
	{
		ClearScreen();
		ptrArr[pos.y][pos.x] = robot;
		printField();
		std::cout << "Bye!\n";
	}
	switch (route)
	{
	case eDirection::LEFT:
		if (pos.x - 1 < 0)
		{
			pos.x = 0;
			ptrArr[pos.y][pos.x] = robotError;
			throw OffTheField("OffTheField\n");
		}
		else
		{
			pos.x--;
			ptrArr[pos.y][pos.x] = robotLeft;
		}
		break;
	case eDirection::RIGHT:
		if (pos.x + 1 > iN - 1)
		{
			pos.x = iN - 1;
			ptrArr[pos.y][pos.x] = robotError;
			throw OffTheField("OffTheField\n");
		}
		else
		{
			pos.x++;
			ptrArr[pos.y][pos.x] = robotRight;
		}
		break;
	case eDirection::UP:
		if (pos.y - 1 < 0)
		{
			pos.y = 0;
			ptrArr[pos.y][pos.x] = robotError;
			throw OffTheField("OffTheField\n");
		}
		else
		{
			pos.y--;
			ptrArr[pos.y][pos.x] = robotUp;
		}
		break;
	case eDirection::DOWN:
		if (pos.y + 1 > iN - 1)
		{
			pos.y = iN - 1;
			ptrArr[pos.y][pos.x] = robotError;
			throw OffTheField("OffTheField\n");
		}
		else
		{
			pos.y++;
			ptrArr[pos.y][pos.x] = robotDown;
		}
		break;
	}
}

void Robot::Input()
{
	switch (_getch())
	{
	case 'a':
		route = eDirection::LEFT;
		break;
	case 'd':
		route = eDirection::RIGHT;
		break;
	case 'w':
		route = eDirection::UP;
		break;
	case 's':
		route = eDirection::DOWN;
		break;
	case 'q':
		isRobotOver = true;
		break;
	default:
	{
		ClearScreen();
		ptrArr[pos.y][pos.x] = robotIllegal;
		printField();
		throw IllegalCommand("IllegalCommand!\n");
	}
	break;
	}

	Logic();
}

void Robot::ClearScreen()
{
	COORD topLeft = {0, 0};
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO screen;
	DWORD written;

	GetConsoleScreenBufferInfo(console, &screen);
	FillConsoleOutputCharacterA(
		console, ' ', screen.dwSize.X * screen.dwSize.Y, topLeft, &written);
	FillConsoleOutputAttribute(
		console, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE,
		screen.dwSize.X * screen.dwSize.Y, topLeft, &written);
	SetConsoleCursorPosition(console, topLeft);
}

void Robot::printField()
{
	for (int i = 0; i < iN; i++)
	{
		for (int j = 0; j < iN; j++)
		{
			std::cout << ptrArr[i][j] << ' ';
		}
		std::cout << "\n\n";
	}
	std::cout << "\n";
}

Robot::~Robot()
{
	for (int i = 0; i < iN; i++)
	{
		delete[] ptrArr[i];
	}
	delete[] ptrArr;
	ptrArr = nullptr;
}