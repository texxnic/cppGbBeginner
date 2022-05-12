#include <iostream>
#include <string>
#include <optional>
#include <variant>
#include <tuple>
#include <vector>
#include <fstream>
#include <algorithm>
#include <iomanip>

using namespace std;

class Person
{
private:
	string lastname, firstname;
	optional<string> middlename;

public:
	Person() : lastname(""), firstname("") {}
	Person(string ln, string fn) : lastname(ln), firstname(fn) {}
	Person(string ln, string fn, string mn) : lastname(ln), firstname(fn), middlename(mn) {}

	bool isMatchLastName(const string &lname)
	{
		return lastname == lname;
	}

	bool isFullMatch(const Person &pers)
	{
		return lastname == pers.lastname && firstname == pers.firstname && middlename == pers.middlename;
	}

	friend ostream &operator<<(ostream &os, const Person &pers);
	friend bool operator<(const Person &p1, const Person &p2);
	friend bool operator==(const Person &p1, const Person &p2);
};

ostream &operator<<(ostream &os, const Person &pers)
{
	string middlename = pers.middlename.has_value() ? pers.middlename.value() : " ";
	return os << setiosflags(ios::left) << setw(15) << pers.lastname << setw(14) << pers.firstname << setw(14) << middlename;
}

bool operator<(const Person &p1, const Person &p2)
{
	return tie(p1.lastname, p1.firstname, p1.middlename) < tie(p2.lastname, p2.firstname, p2.middlename);
}

bool operator==(const Person &p1, const Person &p2)
{
	return tie(p1.lastname, p1.firstname, p1.middlename) == tie(p2.lastname, p2.firstname, p2.middlename);
}

class PhoneNumber
{
private:
	int country, city;
	string number;
	optional<int> additional;

public:
	PhoneNumber() : country(0), city(0), number("") {}
	PhoneNumber(int co, int ct, string num) : country(co), city(ct), number(num) {}
	PhoneNumber(int co, int ct, string num, int add) : country(co), city(ct), number(num), additional(add) {}

	friend ostream &operator<<(ostream &os, const PhoneNumber &phone);
	friend bool operator<(const PhoneNumber &ph1, const PhoneNumber &ph2);
};

ostream &operator<<(ostream &os, const PhoneNumber &phone)
{
	string additional = phone.additional.has_value() ? to_string(phone.additional.value()) : "";
	return os << "+" << phone.country << "(" << phone.city << ")" << phone.number << " " << additional;
}

bool operator<(const PhoneNumber &ph1, const PhoneNumber &ph2)
{
	return tie(ph1.country, ph1.city, ph1.number, ph1.additional) < tie(ph2.country, ph2.city, ph2.number, ph2.additional);
}

class PhoneBook
{
private:
	vector<pair<Person, PhoneNumber> > contacts;

	vector<string> splitString(const string &s)
	{
		vector<string> result;
		size_t space_pos = 0;

		while (true)
		{
			size_t pos = s.find(' ', space_pos);
			if (pos == s.npos)
			{
				result.push_back(s.substr(space_pos, s.size() - space_pos));
				break;
			}
			result.push_back(s.substr(space_pos, pos - space_pos));
			space_pos = pos + 1;
		}

		return result;
	}

	Person getPerson(string lastname, string firstname, string middlename)
	{
		return middlename == "-"
				   ? Person{lastname, firstname}
				   : Person{lastname, firstname, middlename};
	}

	PhoneNumber getPhoneNumber(string country, string city, string number, string additional)
	{
		return additional == "-"
				   ? PhoneNumber{stoi(country), stoi(city), number}
				   : PhoneNumber{stoi(country), stoi(city), number, stoi(additional)};
	}

public:
	PhoneBook(ifstream &fl)
	{
		string line;
		vector<string> parts;

		while (getline(fl, line))
		{
			parts = splitString(line);

			Person pers = getPerson(parts[0], parts[1], parts[2]);
			PhoneNumber number = getPhoneNumber(parts[3], parts[4], parts[5], parts[6]);

			contacts.push_back(make_pair(pers, number));
		}
	}

	void SortByName()
	{
		sort(contacts.begin(), contacts.end(), [](auto &contact1, auto &contact2)
			 { return contact1.first < contact2.first; });
	}

	void SortByPhone()
	{
		sort(contacts.begin(), contacts.end(), [](auto &contact1, auto &contact2)
			 { return contact1.second < contact2.second; });
	}

	tuple<string, PhoneNumber> GetPhoneNumber(const string &lastname)
	{
		vector<PhoneNumber> result;
		string str = "not found";
		PhoneNumber number;

		for_each(contacts.begin(), contacts.end(), [lastname, &result](auto &contact)
				 {
			if (contact.first.isMatchLastName(lastname)) {
				result.push_back(contact.second);
			} });

		if (result.size() > 1)
		{
			str = "found more than 1";
			number = result[0];
		}
		else if (result.size() > 0)
		{
			str = "";
			number = result[0];
		}

		return make_tuple(str, number);
	}

	void ChangePhoneNumber(Person pers, PhoneNumber number)
	{
		auto result = find_if(contacts.begin(), contacts.end(), [pers](auto &contact)
							  { return contact.first.isFullMatch(pers); });

		if (result != end(contacts))
		{
			(*result).second = number;
		}
	}

	friend ostream &operator<<(ostream &os, const PhoneBook &book);
};

ostream &operator<<(ostream &os, const PhoneBook &book)
{
	for_each(book.contacts.begin(), book.contacts.end(), [&os](const auto &contact)
			 { os << contact.first << "\t" << contact.second << "\n"; });

	return os;
}

int main(int argc, char const *argv[])
{
	ifstream file("PhoneBook.txt");
	PhoneBook book(file);
	cout << book;

	cout << "------SortByPhone-------" << endl;
	book.SortByPhone();
	cout << book;

	cout << "------SortByName--------" << endl;
	book.SortByName();
	cout << book;

	cout << "-----GetPhoneNumber-----" << endl;
	auto print_phone_number = [&book](const string &surname)
	{
		cout << surname << "\t";
		auto answer = book.GetPhoneNumber(surname);
		if (get<0>(answer).empty())
		{
			cout << get<1>(answer);
		}
		else
		{
			cout << get<0>(answer);
		}
		cout << endl;
	};

	print_phone_number("Ivanov");
	print_phone_number("Petrov");

	cout << "----ChangePhoneNumber----" << endl;
	book.ChangePhoneNumber(Person{"Kotov", "Vasilii", "Eliseevich"}, PhoneNumber{7, 123, "15344458"});
	book.ChangePhoneNumber(Person{"Mironova", "Margarita", "Vladimirovna"}, PhoneNumber{16, 465, "9155448", 13});
	cout << book;

	return 0;
}
