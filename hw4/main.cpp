#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <algorithm>

using namespace std;

template <typename T, template<typename> class Container>
void printData(const Container<T>& data) {
    for(const auto& a: data){
        cout << a << " ";
    }
    cout << endl;
}

template <typename T, template<typename> class Container>
void insert_sorted(Container<T>& data, T num) {
    auto pos = find_if(data.begin(), data.end(), [num](T item) {
    	return item > num;
    });
    data.insert(pos, num);
}

int main(int argc, char const *argv[])
{
	cout << "---------------- Task 1 ------------------" << endl;

	vector<int> vec = { 12, 23, 34, 45, 54, 61, 65, 71, 88, 93 };
	printData(vec);
	int num_int = 48;
	insert_sorted(vec, num_int);
	printData(vec);

	cout << endl;

	deque<string> deq = { "d12", "d23", "d34", "d45", "d54", "d61", "d65", "d71", "d88", "d93" };
	printData(deq);
	string num_str = "d63";
	insert_sorted(deq, num_str);
	printData(deq);

	cout << endl;

	list<float> lst = { 1.2, 2.3, 3.4, 4.5, 5.4, 6.1, 6.5, 7.1, 8.8, 9.3 };
	printData(lst);
	float num_flt = 7.5;
	insert_sorted(lst, num_flt);
	printData(lst);

	cout << endl;

	cout << "---------------- Task 2 ------------------" << endl;

	vector<float> analog(100);
	generate(analog.begin(), analog.end(), []() {
		float part1 = 1 + rand() % 100;
		float part2 = 1 + rand() % 100;
		return part1 + part2 / 100.0;
	});

	cout << "Analog signal:" << endl;
	printData(analog);

	cout << endl;

	vector<int> digital(100);
	copy_if(analog.begin(), analog.end(), digital.begin(), [](float num) {
		return static_cast<int>(num);
	});
	cout << "Digital signal:" << endl;
	printData(digital);

	cout << endl;

	// К сожалению, я не учился в институте и не понимаю формулу подсчета из задачи
	// поэтому как делать дальше я не знаю :(

	cout << "Sorry, I don't know what to do next..." << endl;

	return 0;
}
