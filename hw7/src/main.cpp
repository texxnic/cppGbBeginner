#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <numeric>
#include "students.pb.h"

class FullName
{
    std::string _surname;
    std::string _name;
    std::string _patronymic;

public:
    FullName() {}
    FullName(std::string surname, std::string name, std::string patronymic)
        : _surname(surname),
          _name(name),
          _patronymic(patronymic) {}
    FullName(const serialization::FullName &serFname)
    {
        _surname = serFname.surname();
        _name = serFname.name();
        _patronymic = serFname.patronymic();
    }
    void ConvertToSerializationType(serialization::FullName *serFname)
    {
        serFname->set_name(_name);
        serFname->set_surname(_surname);
        serFname->set_patronymic(_patronymic);
    }
    friend bool operator==(const FullName &lhs, const FullName &rhs)
    {
        return lhs._surname == lhs._surname && lhs._name == rhs._name && rhs._patronymic == rhs._patronymic;
    }
    friend std::ostream &operator<<(std::ostream &out, const FullName &serFname)
    {
        out << serFname._surname << " " << serFname._name << " " << serFname._patronymic;
        return out;
    }
};

class Student
{
    FullName _full_name;
    std::vector<int> _grades;
    int _average_grade;

public:
    Student(const FullName &full_name, std::vector<int> grades, int average_grade)
        : _full_name(full_name),
          _grades(grades),
          _average_grade(average_grade) {}
    Student(const serialization::Student &sSt)
    {
        _average_grade = sSt.averagegrade();
        for (size_t i = 0; i < sSt.grades_size(); ++i)
        {
            _grades.push_back(sSt.grades(i));
        }
        _full_name = FullName(sSt.fullname());
    }

    void ConvertToSerializationType(serialization::Student *sSt)
    {
        for_each(_grades.begin(), _grades.end(), [&sSt](int value)
                 { sSt->add_grades(value); });
        sSt->set_averagegrade(_average_grade);
        serialization::FullName *fName = sSt->mutable_fullname();
        _full_name.ConvertToSerializationType(fName);
    }

    friend std::ostream &operator<<(std::ostream &out, const Student &student)
    {
        out << student._full_name << " ";
        copy(student._grades.begin(), student._grades.end(), std::ostream_iterator<int>(out, " "));
        return out;
    }

    const FullName &GetFullName() const { return _full_name; }
    const std::vector<int> &GetGrades() const { return _grades; }
};

class IRepository
{
    virtual void Open() = 0;
    virtual void Save() = 0;
};

class IMethods
{
    virtual int GetAverageScore(const FullName &name) = 0;
    virtual std::string GetAllInfo(const FullName &name) = 0;
    virtual std::string GetAllInfo() = 0;
};

class StudentsGroup : public IRepository, public IMethods
{
private:
    std::vector<Student> _students;
    serialization::StudentsGroup ConvertToSerializationType(std::vector<Student> students)
    {
        serialization::StudentsGroup stGroup;
        for (auto student : students)
        {
            serialization::Student *st = stGroup.add_students();
            student.ConvertToSerializationType(st);
        }
        return stGroup;
    }
    std::vector<Student> ConvertFromSerializationType(serialization::StudentsGroup students)
    {
        std::vector<Student> stGroup;
        for (size_t i = 0; i < students.students_size(); i++)
        {
            serialization::Student st = students.students(i);
            stGroup.push_back(Student(students.students(i)));
        }
        return stGroup;
    }

public:
    StudentsGroup() {}
    StudentsGroup(std::vector<Student> students)
        : _students(students) {}
    void Open() override
    {
        serialization::StudentsGroup s;
        std::ifstream in("students.bin", std::ios_base::binary);
        _students = ConvertFromSerializationType(s);
    }
    void Save() override
    {
        serialization::StudentsGroup s = ConvertToSerializationType(_students);
        std::ofstream out("students.bin", std::ios_base::binary);
        s.SerializeToOstream(&out);
    }

    friend std::ostream &operator<<(std::ostream &out, const StudentsGroup &stGroup)
    {
        copy(stGroup._students.begin(), stGroup._students.end(), std::ostream_iterator<Student>(out, "\n"));
        return out;
    }

    int GetAverageScore(const FullName &name) override
    {
        auto finded = std::find_if(_students.begin(), _students.end(), [&](const Student &st)
                                   { return name == st.GetFullName(); });
        if (finded != _students.end())
        {
            auto grades = finded->GetGrades();
            return std::accumulate(grades.begin(), grades.end(), 0) / grades.size();
        }
        return 0;
    }
    std::string GetAllInfo(const FullName &name) override
    {
        auto finded = std::find_if(_students.begin(), _students.end(), [&](const Student &st)
                                   { return name == st.GetFullName(); });
        if (finded != _students.end())
        {
            std::ostringstream ss;
            ss << *finded;
            return ss.str();
        }
        return std::string();
    }
    std::string GetAllInfo() override
    {
        std::ostringstream ss;
        ss << *this;
        return ss.str();
    }
};

int main()
{
    StudentsGroup groupA(std::vector<Student>{
        Student({"Ivanov", "Ivan", "Ivanovitch"}, {4, 2, 3, 8, 10}, 6),
        Student({"Vasiliy", "Vasilyev", "Vasilyevic"}, {6, 4, 5, 7, 10}, 7),
        Student({"Roman", "Romanov", "Romanovic"}, {7, 9, 8, 6, 4}, 8)});
    groupA.Save();
    StudentsGroup groupB;
    groupB.Open();
    std::cout << groupB.GetAverageScore(FullName("Vasiliy", "Vasilyev", "Vasilyevic")) << std::endl;
    std::cout << groupB.GetAllInfo(FullName("Roman", "Roman", "Roman")) << std::endl;
    std::cout << groupB.GetAllInfo() << std::endl;

    return 0;
}
