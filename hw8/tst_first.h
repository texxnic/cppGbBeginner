#pragma once
#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include "person.h"
#include "phonebook.h"
#include "phonenumber.h"
#include <memory>
#include <iostream>

class TestEntry : public testing::Test
{
public:
    void SetUp() override
    {
        person = std::make_unique<Person>("AAAA", "BB");
        number = std::make_unique<PhoneNumber>(7, 945, "1234567", 1);
    }
    std::unique_ptr<Person> person;
    std::unique_ptr<PhoneNumber>number;
};

TEST_F(TestEntry, Name)
{
    ASSERT_STREQ(person->getName().c_str(),"BB");
}
TEST_F(TestEntry, Surname)
{
    ASSERT_STREQ(person->getSurname().c_str(),"AAAA");
}
