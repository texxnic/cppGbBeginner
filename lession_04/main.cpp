#include <iostream>
#include <tuple>

using namespace std;

// TASK 1
void printDouble(double *arr, int size)
{
    for (size_t i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}

// TASK 2
void reverseBits(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = arr[i] ^= 1;
    }
}

// TASK 3
bool fillArray(int *arr, int size)
{
    int v = 1;

    for (size_t i = 0; i < size; i++)
    {
        arr[i] = v;
        v += 3;
    }
    return true;
}

int main(int argc, char const *argv[])
{
    double arrOfDouble[] = {2.3, 2.5, 0.4, 0.7};
    int arrOfDoubleSize = sizeof arrOfDouble / sizeof arrOfDouble[0];
    printDouble(arrOfDouble, arrOfDoubleSize);
    cout << endl;


    int arrOfBool[] = {1, 1, 0, 0, 1, 0, 1, 1, 0, 0};
    int arrOfBoolSize = sizeof arrOfBool / sizeof arrOfBool[0];
    copy(begin(arrOfBool), end(arrOfBool), ostream_iterator<int>(cout, " "));
    cout << endl;
    reverseBits(arrOfBool, arrOfBoolSize);
    copy(begin(arrOfBool), end(arrOfBool), ostream_iterator<int>(cout, " "));
    cout << endl;

    int arrToFillSize = 8;
    int arrTofill[arrToFillSize];
    fillArray(arrTofill, arrToFillSize);
    for (size_t i = 0; i < arrToFillSize; i++)
    {
        cout << arrTofill[i];
    }
    cout << endl;

    return 0;
}
