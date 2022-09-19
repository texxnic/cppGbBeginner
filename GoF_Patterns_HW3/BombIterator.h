#pragma once

#include <vector>

#include "IBomb.h"

class BombIterator
{
public:

    BombIterator(const std::vector<DynamicObject*>& reference);

    BombIterator(const BombIterator& src);

    void reset();

    BombIterator& operator++();

    BombIterator& operator--();

    IBomb* operator*();

    bool operator==(BombIterator other);

    bool operator!=(BombIterator other);

private:

    const std::vector<DynamicObject*>& refVector_;
    int curIdx_;
    IBomb* ptr_;
};

