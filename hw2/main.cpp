#include <iostream>
#include "Timer.h"
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>

using namespace std;

void swap(int *pt1, int *pt2)
{
	int tmp = *pt1;
	*pt2 = *pt1;
	*pt1 = tmp;
}

void sortPointers(vector<int *> &pts)
{
	sort(pts.begin(), pts.end(), [](auto &item1, auto &item2)
		 { return *item1 < *item2; });
}

void countVowels_1(const string &s, const string &c)
{
	Timer timer("Method: count_if + find");

	int cnt = count_if(s.begin(), s.end(), [c](auto letter)
					   {
    	auto pos = find(c.begin(), c.end(), letter);
    	return pos != end(c); });

	timer.print(cnt);
}

void countVowels_2(const string &s, const string &c)
{
	Timer timer("Method: count_if + for");

	int cnt = count_if(s.begin(), s.end(), [c](auto letter)
					   {
    	for (auto compare : c) {
    		if (letter == compare) {
    			return true;
    		}
    	}
    	return false; });

	timer.print(cnt);
}

void countVowels_3(const string &s, const string &c)
{
	Timer timer("Method: for + find");

	int cnt = 0;

	for (auto letter : s)
	{
		auto pos = find(c.begin(), c.end(), letter);
		if (pos != end(c))
		{
			cnt++;
		}
	}

	timer.print(cnt);
}

void countVowels_4(const string &s, const string &c)
{
	Timer timer("Method: for + for");

	int cnt = 0;

	for (auto letter : s)
	{
		for (auto compare : c)
		{
			if (letter == compare)
			{
				cnt++;
			}
		}
	}

	timer.print(cnt);
}

int main(int argc, char const *argv[])
{
	cout << "TSK 1" << endl;

	int x = 100;
	int y = 200;

	int *pt1 = &x;
	int *pt2 = &y;

	cout << x << " " << y << endl;
	swap(x, y);
	cout << x << " " << y << endl;

	cout << "TSK 2" << endl;

	vector<int *> pointers;

	for (int i = 0; i < 100; ++i)
	{
		int *num = new int;
		*num = 1 + rand() % 100;
		pointers.push_back(num);
	}

	sortPointers(pointers);

	for (int *p : pointers)
	{
		cout << *p << " ";
	}

	cout << endl;
	cout << "TSK 3" << endl;

	string vowels = "AaEeIiOoUu";

	ifstream file("War and peace.txt");
	file.seekg(0, ios::end);
	size_t size = file.tellg();
	file.seekg(0);
	string s(size, ' ');
	file.read(&s[0], size);

	countVowels_1(s, vowels);
	countVowels_2(s, vowels);
	countVowels_3(s, vowels);
	countVowels_4(s, vowels);

	return 0;
}
