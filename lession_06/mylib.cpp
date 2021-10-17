#include <iostream>

void initalizeArr(float *arr, int *arrSize)
{
    for (size_t i = 0; i < *arrSize; i++)
    {
        arr[i] = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
        //Рандомное отрицательное число
        if (rand() > (RAND_MAX / 2))
        {
            arr[i] = -arr[i];
        }
    }
};

void printFloatArray(float *arr, int *arrSize)
{
    for (size_t i = 0; i < *arrSize; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void printIntArray(int *arr, int *arrSize)
{
    for (size_t i = 0; i < *arrSize; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void printPosAndNegativeCount(float *arr, int *arrSize)
{
    int positive = 0;
    int negative = 0;

    for (size_t i = 0; i < *arrSize; i++)
    {
        if (arr[i] >= static_cast<float>(0))
        {
            positive++;
        }
        else
        {
            negative++;
        }
    }

    std::cout << "Положительных:" << positive << std::endl;
    std::cout << "Отрицательных:" << negative << std::endl;
}

void swapINT(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
                swapINT(&arr[j], &arr[j + 1]);
        }
    }
}