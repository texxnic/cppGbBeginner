#pragma once
#include "phonenumber.h"
#include "person.h"
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <string>
#include <tuple>

class PhoneBook
{
public:
    PhoneBook(std::ifstream &file);
    void SortByName();
    void SortByPhone();
    std::tuple<std::string, PhoneNumber> GetPhoneNumber(const std::string &surname);
    void ChangePhoneNumber(const Person &person, const PhoneNumber &phonenumber);
    friend std::ostream &operator<<(std::ostream &os, const PhoneBook &PhoneBook);

    std::vector<std::pair<Person, PhoneNumber> > m_data;
};
