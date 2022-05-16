#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include "myIterator.h"
#include "matrix.h"

using namespace std;

template <class T>
void printList(const list<T> &lst)
{
	for (const auto &a : lst)
	{
		cout << a << " ";
	}
	cout << endl;
}

void addAverage(list<float> &lst)
{
	size_t cnt = 0;
	float sum = 0;
	for (const auto &a : lst)
	{
		sum += a;
		cnt++;
	}
	float avr = sum / static_cast<float>(cnt);
	lst.push_back(avr);
}

int main(int argc, char const *argv[])
{
	cout << "TSK 1" << endl;

	list<float> lst = {0, 7, 4, 8, 3, 9, 2, 1, 5, 6};
	printList(lst);
	addAverage(lst);
	printList(lst);

	cout << "TSK 2" << endl;

	Matrix m(3);
	m.fillMatrix();
	std::cout << "матрица: " << std::endl;
	m.printMatrix();
	std::cout << std::endl
			  << "определителем матрицы является: " << m.determinant() << std::endl;
	m.determinant();
	return 0;

	cout << "TSK 3" << endl;
	std::vector<int> v{2, 5, 3, 8, 4, 0};
	auto it = myIterator(v);
	std::cout << "my iterator:\n";
	for (auto i : it)
		std::cout << i << " ";

	return 0;
}
