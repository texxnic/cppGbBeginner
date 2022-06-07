#include "phonebook.h"

PhoneBook::PhoneBook(std::ifstream &file)
{
       if (!file) std::cout<<"file error"<<std::endl;

       std::string str;
       while (std::getline(file, str))
       {
           std::string name, sname, number, addNumber, patronymic;

           int32_t countryCode, cityCode;
           std::istringstream strStream(str);
           strStream >> sname >> name >> patronymic >> countryCode >> cityCode >> number >> addNumber;
          std::optional<std::string>  oPatronymic;
           std::optional<int32_t> oAddNumber;

          if(patronymic == "-")
              oPatronymic = std::nullopt;
          else
              oPatronymic=patronymic;

          if (addNumber == "-")
             oAddNumber = std::nullopt ;
          else
          {
             oAddNumber = std::stoi(addNumber.c_str());
          }

           m_data.push_back(std::make_pair(Person(sname, name, oPatronymic), PhoneNumber(countryCode, cityCode, number, oAddNumber)));
       }
       file.close();
}
void PhoneBook::ChangePhoneNumber(const Person &person, const PhoneNumber &phonenumber)
{

    for_each(m_data.begin(), m_data.end(), [&](std::pair<Person,PhoneNumber> &note)mutable
    {
        if (note.first==person)
        {
            note.second=phonenumber;
        }
    });
}
std::tuple<std::string, PhoneNumber> PhoneBook::GetPhoneNumber(const std::string &surname)
{

    int16_t count=0;
    PhoneNumber phN(0,0," ",0);

    for_each(m_data.begin(), m_data.end(), [&count, &phN, &surname](const std::pair<Person,PhoneNumber> &note)
    {
        if (note.first.m_surname==surname)
        {
            count++;
            phN=note.second;

        }
    });
    if(count==0)
        return {"not found", 0 };
    else if(count==1)
        return {"", phN};
    return {"found more than 1",0};


}
void PhoneBook::SortByName()
{
    std::sort(m_data.begin(), m_data.end(), [](const std::pair<Person,PhoneNumber> &p1, const std::pair<Person,PhoneNumber> &p2) {
        return p1.first < p2.first;
    });
}
void PhoneBook::SortByPhone()
{
    std::sort(m_data.begin(), m_data.end(), [](const std::pair<Person,PhoneNumber> &p1, const std::pair<Person,PhoneNumber> &p2) {
        return p1.second < p2.second;
    });
}

std::ostream& operator<< (std::ostream &os, const PhoneBook &PhoneBook)
{
    for (auto[first, second] : PhoneBook.m_data)
    {
       std::cout<<first<<" "<<second<<std::endl;
    }
    return os;
}
