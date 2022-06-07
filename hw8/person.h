#pragma once
#include <iostream>
#include <optional>
#include <tuple>

struct Person
{
    Person();
    Person(std::string surname = "", std::string name = "", std::optional<std::string> patronymic = std::nullopt) : m_surname(surname), m_name(name)
    {
        if (patronymic.has_value())
            m_patronymic = patronymic.value();
    };

    friend std::ostream &operator<<(std::ostream &os, const Person &prsn);
    // friend std::istream& operator<< (std::istream& is, const Person& prsn);
    friend bool operator<(const Person &p1, const Person &p2);
    friend bool operator==(const Person &p1, const Person &p2);
    std::string getName();
    std::string getSurname();
    std::string getPatronynic();
    std::string m_surname{};                   //фамилия
    std::string m_name{};                      //имя
    std::optional<std::string> m_patronymic{}; //отчество
};
