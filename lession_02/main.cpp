#include <iostream>

//task 1 || 4
extern int a;
extern int b;

float divResult = static_cast<float>(a) / b;

//task 2
int compareTo21(int number)
{
    int diff = 21 - number;
    return number <= 21 ? diff : diff * 2;
}

//task 3
int numbers[3][3][3] = {1};
int *numPtr = &numbers[1][1][1];

int main(int argc, char const *argv[])
{
    int task2Number;
    numbers[1][1][1] = 2;

    std::cout << "task 1 || 4 result: " << divResult << std::endl;
    std::cout << "Enter number for comparision: ";
    std::cin >> task2Number;
    std::cout << "taks 2 result: " << compareTo21(task2Number) << std::endl;
    std::cout << "taks 3 result: " << *numPtr << std::endl;
    return 0;
}
