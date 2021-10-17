#include <iostream>
#include "mylib.h"

using namespace std;

#define IN_RANGE(x, range) (x >= 0 && x < range)
#define ARR_SIZE 5

int main(int argc, char const *argv[])
{
    // TASK 1
    int arrSize = 5;
    float arr[arrSize];
    initalizeArr(arr, &arrSize);
    printFloatArray(arr, &arrSize);
    printPosAndNegativeCount(arr, &arrSize);

    // TASK 2
    int firstNum;
    cout << "Напишите число:" << endl;
    cin >> firstNum;

    cout << IN_RANGE(firstNum, 5) << endl;

    // task3
    int arrToSort[ARR_SIZE];

    for(size_t i = 0; i < ARR_SIZE; i++){
        cout << "Введите число для индекса " << i << endl;
        cin >> arrToSort[i];
    }

    int arrSizeCont = ARR_SIZE;
    printIntArray(arrToSort, &arrSizeCont);
    bubbleSort(arrToSort, arrSizeCont);
    printIntArray(arrToSort, &arrSizeCont);
    /* code */
    return 0;
}
