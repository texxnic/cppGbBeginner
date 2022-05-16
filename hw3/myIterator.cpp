#include "myIterator.h"

myIterator::myIterator(std::vector<int> &vecIn)
{
    p_begin = vecIn.empty() ? 0 : &vecIn.front();
    p_end = p_begin + vecIn.size();
}

int *myIterator::begin()
{
    return p_begin;
}
int *myIterator::end()
{
    return p_end;
}
int myIterator::operator*()
{
    return *p_begin;
}
int *myIterator::operator++()
{
    return p_begin++;
}
