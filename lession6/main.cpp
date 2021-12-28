#include <stdio.h>
#include <iostream>

using namespace std;
#define LIMIT 1000

//Сделал только задание 2, первое сделаю на НГ

int pointer = -1;
int Stack[LIMIT];

bool pushToStack(int data) {
    if (pointer < LIMIT) {
        Stack[++pointer] = data;
        return true;
    } else {
        cout <<  "Стек переполнен" << endl;
        return false;
    }
}

int popFromStack() {
    if (pointer != -1) {
        return Stack[pointer--];
    } else {
        cout <<  "Стек пустой" << endl;
        return -1;
    }
}

void stackBinaryConverter(int num) {
    if  (num == 0) printf("0\n");
    int count = 0;
    while(num > 0) {
        int temp = num % 2;
        pushToStack(temp);
        num /= 2;
        count++;
    }
    for (int i = 0; i < count; i++) {
        cout <<  popFromStack();
    }
    cout << endl;
}

int main( int argc, const char* argv[] ) {
    cout <<  "Введите десятичное число:" << endl;
    int numb;
    cin >> numb;
    stackBinaryConverter(numb);
    return 0;
}