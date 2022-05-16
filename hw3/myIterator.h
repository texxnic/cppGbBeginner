#pragma once
#include <iostream>
#include <vector>

class myIterator
{
private:
    int *p_begin;
    int *p_end;

public:
    myIterator(std::vector<int> &vecIn);
    int *begin();
    int *end();
    int *operator++();
    int operator*();
};
