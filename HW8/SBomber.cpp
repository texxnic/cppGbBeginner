#include "SBomber.h"
#include "SBomberImpl.h"

SBomber::SBomber()
    : impl_(new SBomberImpl())
{}

SBomber::~SBomber()
{}

SBomber::SBomber(SBomber&& rhs) = default;

SBomber& SBomber::operator=(SBomber&& rhs) = default;

SBomber::SBomber(const SBomber& rhs)
    :impl_(new SBomberImpl(*rhs.impl_))
{}

SBomber& SBomber::operator=(const SBomber& rhs)
{
    if (this != &rhs)
        impl_.reset(new SBomberImpl(*rhs.impl_));

    return *this;
}

bool SBomber::GetExitFlag() const
{
    return Pimpl()->GetExitFlag();
}

void SBomber::MoveObjects()
{
    Pimpl()->MoveObjects();
};

void SBomber::CheckObjects()
{
    Pimpl()->CheckObjects();
}

void SBomber::AnimateScrolling()
{
    impl_->AnimateScrolling();
}

const SBomberImpl* SBomber::Pimpl() const
{
    return impl_.get();
}

SBomberImpl* SBomber::Pimpl()
{
    return impl_.get();
}
;

void SBomber::ProcessKBHit()
{
    Pimpl()->ProcessKBHit();
}

void SBomber::DrawFrame()
{
    Pimpl()->DrawFrame();
}

void SBomber::TimeStart()
{
    Pimpl()->TimeStart();
}

void SBomber::TimeFinish()
{
    Pimpl()->TimeFinish();
}
