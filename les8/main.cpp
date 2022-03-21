#include <iostream>
#include <sstream>

double numericValidation();

template <typename T>
const double &div(const T &num1, const T &num2)
{
    if (num2 == 0)
        throw "Division by zero!";
    return (num1 / num2);
}

#include "Ex.h"
#include "Bar.h"

#include "Robot.h"

int main()
{

    std::cout << "Задание 1\n\n";

    double num1 = 0;
    double num2 = 0;
    double valueDiv = 0;

    std::cout << "Enter first number : \n";
    num1 = numericValidation();
    std::cout << "Enter second number : \n";
    num2 = numericValidation();
    try
    {
        valueDiv = div(num1, num2);
        std::cout << "Division : " << valueDiv << std::endl;
    }
    catch (const char *message)
    {
        std::cout << message << std::endl;
    }

    std::cout << "Задание 2\n\n";

    double n;
    Bar bar;

    try
    {
        do
        {
            std::cout << "Enter number : ";
            n = numericValidation();
            bar.setBar(n);
            std::cout << "y = " << bar.getBar() << "\n";
        } while (n != 0);
    }
    catch (Ex ex)
    {
        std::cout << "Error!\n";
        std::cout << bar.getBar() << " + " << n << " > 100 , so " << bar.getBar() << " * " << n << " = " << ex.getEx() << "\n";
    }

    std::cout << "Задание 3\n\n";

    Robot robot;
    robot.robotMovement();

    return 0;
}

double numericValidation()
{
    std::string userInput = "";

    int numCount = 0,
        floatCount = 0;
    double userConvertedNum;

    bool isIntNumber = false;
    bool isExit = false;

    do
    {
        std::cin >> userInput;
        if (userInput[0] == '#')
        {
            isExit = true;
            numCount = 0;
            break;
        }
        else
        {
            for (size_t i = 0; i < userInput.size(); i++)
            {
                if (isdigit(userInput[i]))
                {
                    numCount++;
                    isIntNumber = true;
                }
                else if (isalnum(userInput[i]))
                {
                    isIntNumber = false;
                    numCount = 0;
                    break;
                }
                if (userInput[i] == '.')
                {
                    numCount++;
                    floatCount++;
                    isIntNumber = true;
                }
            }
        }
        if (userInput[0] == '-')
        {
            numCount++;
            for (size_t i = numCount; i < userInput.size(); i++)
            {
                if (isdigit(userInput[i]))
                {
                    numCount++;
                    isIntNumber = true;
                }
                else if (isalnum(userInput[i]))
                {
                    isIntNumber = false;
                    numCount = 0;
                    break;
                }
                if (userInput[i] == '.')
                {
                    numCount++;
                    floatCount++;
                    isIntNumber = true;
                }
            }
        }
        if (floatCount > 1)
        {
            isIntNumber = false;
            numCount = 0;
            break;
        }
        if (numCount == userInput.size())
        {
            std::stringstream ssInput(userInput);
            ssInput >> userConvertedNum;
        }
        else
        {
            if (isIntNumber == false && numCount == 0)
                std::cout << "It's not a number!\nEnter the number (only digits without letters, symbols): ";
            else if (isExit == true)
                break;

            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            numCount = 0;
            isIntNumber = false;
        }

    } while (isIntNumber == false && isExit == false);

    if (isExit == true)
        userConvertedNum = 0;

    return static_cast<double>(userConvertedNum);
}