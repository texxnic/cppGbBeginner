#include "person.h"

Person::Person()
{

}
std::ostream& operator<< (std::ostream& os, const Person& prsn)
{
    os << prsn.m_surname << " " << prsn.m_name;
    if (prsn.m_patronymic.has_value())
        os  << " " << prsn.m_patronymic.value();
    return os;
}

bool operator<(const Person& p1, const Person& p2)
{
    return std::tie(p1.m_surname, p1.m_name, p1.m_patronymic) <
           std::tie(p2.m_surname , p2.m_name, p2.m_patronymic);
}
bool operator==(const Person& p1, const Person& p2)
{
    return std::tie(p1.m_surname, p1.m_name, p1.m_patronymic) ==
           std::tie(p2.m_surname , p2.m_name, p2.m_patronymic);
}
std::string Person::getName()
{
    return m_name;
}
std::string Person::getSurname()
{
    return m_surname;
}
std::string Person::getPatronynic()
{
    if (m_patronymic.has_value())
        return m_patronymic.value();
    return "";
}
