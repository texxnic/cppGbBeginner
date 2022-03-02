#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cassert>

class ArrayInt
{
private:
	int m_lenght;
	int *m_data;
	void merge(int *arr, int first, int mid, int last);
	void mergeSort(int *arr, int first, int last);

public:
	ArrayInt() : m_lenght(0), m_data(nullptr){};
	ArrayInt(int lenght);
	~ArrayInt();
	void erase();
	int getLenght() const;
	int &operator[](int index);
	void resize(int newLenght);
	void insertBefore(int value, int index);
	void push_back(int value);
	void pop_back();
	void pop_front();
	void sort();
	void print() const;
};