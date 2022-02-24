
#include <iostream>

using namespace std;

class Stack
{
private:
	static const int StackSize = 10;
	int StackArray[StackSize];
	int CurrentStackSize;

public:
	void reset()
	{
		CurrentStackSize = 0;

		for (int i = 0; i < StackSize; i++)
		{
			StackArray[i] = 0;
		}
	}

	bool push(int num)
	{
		if (CurrentStackSize == StackSize)
		{
			return false;
		}
		else
		{
			StackArray[CurrentStackSize++] = num;
			return true;
		}
	}

	int pop()
	{
		if (CurrentStackSize == 0)
		{
			cout << "Stack empty!" << endl;
		}
		else
		{
			return StackArray[--CurrentStackSize];
		}
	}

	void print()
	{
		cout << "( ";
		for (int i = 0; i < CurrentStackSize; i++)
		{
			cout << StackArray[i] << " ";
		}
		cout << ")" << endl;
	}
};

int main(int argc, char **args)
{

	Stack stack;
	stack.reset();
	stack.print();

	stack.push(3);
	stack.push(7);
	stack.push(6);
	stack.print();

	stack.pop();
	stack.print();

	stack.pop();
	stack.pop();
	stack.print();

	return 1;
}