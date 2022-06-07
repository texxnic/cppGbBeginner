#include "phonenumber.h"

PhoneNumber::PhoneNumber()
{

}
std::ostream& operator<< (std::ostream& os, const PhoneNumber& phNum)
{
     os <<"+"<<phNum.m_countryCode<<"("<<phNum.m_cityCode<<")"<<phNum.m_number;
     if(phNum.m_addNumber.has_value())
         os<<" "<<phNum.m_addNumber.value();
     return os;
}

bool operator<(const PhoneNumber& p1, const PhoneNumber& p2)
{
    return std::tie(p1.m_countryCode, p1.m_cityCode, p1.m_number, p1.m_addNumber) <
           std::tie(p2.m_countryCode, p2.m_cityCode, p2.m_number, p2.m_addNumber);
}
bool operator==(const PhoneNumber& p1, const PhoneNumber& p2)
{
    return std::tie(p1.m_countryCode, p1.m_cityCode, p1.m_number, p1.m_addNumber) ==
           std::tie(p2.m_countryCode, p2.m_cityCode, p2.m_number, p2.m_addNumber);
}
