#include <iostream>
#include <fstream> 

using namespace std;

void printArray(int *arr, int *arrSize)
{
    for (size_t i = 0; i < *arrSize; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// TASK1

void fillDinamicArray(int *arrSize, int *arrPtr)
{
    arrPtr = new (std::nothrow) int[*arrSize];
    if (arrPtr != nullptr)
    {
        arrPtr[0] = 1;
        for (size_t i = 1; i < *arrSize; i++)
        {

            arrPtr[i] = arrPtr[i - 1] << 1;
        }
        printArray(arrPtr, arrSize);
        delete[] arrPtr;
        arrPtr = nullptr;
    }
    else
    {
        std::cout << "Error! Can not allocate memory!";
    }
}

// TASK2
void fillMatrixArray(int m, int n)
{
    int **ptrArr;
    ptrArr = new int *[m];
    for (size_t i = 0; i < m; i++)
    {
        ptrArr[i] = new int[n];

        for (size_t s = 0; s < n; s++)
        {
            ptrArr[i][s] = rand() % 100;
        }
    }

    for (size_t i = 0; i < m; i++)
    {
        printArray(ptrArr[i], &n);
    }

    for (size_t i = 0; i < m; i++)
    {
        delete[] ptrArr[i]; 
    }
    delete[] ptrArr; 
    ptrArr = nullptr;
}

// task3
 
void writeTextToFile(string filename, string text){
    ofstream fout(filename);
    fout << text;
    fout.close();
}

int main(int argc, char const *argv[])
{
    cout << "task1" << endl;
    int *arrPtr;
    int arrSize1;
    cout << "Enter array lenth:" << endl;
    cin >> arrSize1;
    fillDinamicArray(&arrSize1, arrPtr);

    cout << "task2" << endl;
    fillMatrixArray(4, 4);

    cout << "task3" << endl;
    string firstFileName;
    string secondFileName;
    cout << "Введите имя первого файла:" << endl;
    cin >> firstFileName;
    cout << "Введите имя второго файла:" << endl;
    cin >> secondFileName;
    writeTextToFile(firstFileName, "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.");
    writeTextToFile(secondFileName, "Lorem ipsum2 dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.");
    /* code */
    return 0;
}
