#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "help.h"

//Задание 1
void quickSortImproved(int* arr, int first, int last) {
    if(last - first <= 10 && last - first > 0) {
        int sizeTemp = abs(last - first);
        sortInserts(arr, sizeTemp);
    } else {
        int start = arr[first], end = arr[last], mid = arr[(first+last) / 2];
        if ((start > end && end > mid) || (mid > end && end > start)) {
            swapInt(&arr[last], &arr[(first+last) / 2]);
        } else if ((end > start && start > mid) || (mid > start && start > end)) {
            swapInt(&arr[first], &arr[(first+last) / 2]);
        }
    }
    int a = first;
    int b = last;

    int x = arr[(first + last) / 2];

    do {
        while (arr[a] < x) a++;
        while (arr[b] > x) b--;

        if (a <= b) {
            swapInt(&arr[a], &arr[b]);
            a++;
            b--;
        }
    } while (a <= b);

    if (a < last) quickSortImproved(arr, a, last);
    if (first < b) quickSortImproved(arr, first, b);
}

//Задание 2

void blockSort(int* arr, int len) {
    int max = len;
    int b = 10;
    int block[b][max+1];

    for (int i = 0; i < b; ++i) {
        block[i][max] = 0;
    }

    for (int digit = 1; digit < len; ++digit) {
        for (int i = 0; i < max; ++i) {
                int d = (arr[i] / digit) % b;
                block[d][block[d][max]++] = arr[i];
        }
        int idx = 0;
        for (int i = 0; i < b; ++i) {
            for (int j = 0; j < block[i][max]; ++j) {
                if(arr[idx] % 2 == 0 && block[i][j] % 2 == 0) {
                    arr[idx++] = block[i][j];
                } else if (arr[idx] % 2 != 0 && block[i][j] % 2 != 0) {
                    idx++;
                } else if (arr[idx] % 2 != 0 && block[i][j] % 2 == 0) {
                    idx++;
                    j--;
                }
            }
            block[i][max] = 0;
        }

    }
}


int main( int argc, const char* argv[] ) {

    int size = 40;
    int arr[size];
    fillIntRandom(arr, size, 100);
    printIntArray(arr, size, 3);
    quickSortImproved(arr, 0, size - 1);
    printIntArray(arr, size, 3);
    printf("\n");
    fillIntRandom(arr, size, 100);
    printIntArray(arr, size, 3);
    blockSort(arr, size);
    printIntArray(arr, size, 3);
}