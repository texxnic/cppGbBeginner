#include "BombIterator.h"

BombIterator::BombIterator(const std::vector<DynamicObject*>& reference)
    : refVector_(reference), curIdx_(-1), ptr_(nullptr)
{
    ++(*this);
}

BombIterator::BombIterator(const BombIterator& src)
    :refVector_(src.refVector_), curIdx_(src.curIdx_), ptr_(src.ptr_)
{}

void BombIterator::reset()
{
    curIdx_ = -1;
    ptr_ = nullptr;
}

BombIterator& BombIterator::operator++()
{
    ++curIdx_;

    if (curIdx_ == -1)
        curIdx_ = 0;

    for (; curIdx_ < refVector_.size(); ++curIdx_)
    {
        ptr_ = dynamic_cast<IBomb*>(refVector_.at(curIdx_));
        if (ptr_ != nullptr)
            break;
    }

    if (curIdx_ == refVector_.size())
    {
        curIdx_ = -1;
        ptr_ = nullptr;
    }

    return *this;
}

BombIterator& BombIterator::operator--()
{
    if (curIdx_ == -1)
        curIdx_ = refVector_.size();

    for (;curIdx_ >= 0; --curIdx_)
    {
        ptr_ = dynamic_cast<IBomb*>(refVector_.at(curIdx_));
        if (ptr_ != nullptr)
            break;
    }

    if (curIdx_ == -1)
        ptr_ = nullptr;

    return *this;
}

IBomb* BombIterator::operator*()
{
    return ptr_;
}

bool BombIterator::operator==(BombIterator other)
{
    if (curIdx_ == other.curIdx_ &&
        refVector_ == other.refVector_ &&
        ptr_ == other.ptr_)
        return true;

    return false;
}

bool BombIterator::operator!=(BombIterator other)
{
    return !(*this == other);
}
