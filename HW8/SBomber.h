#pragma once

#include <memory>

class SBomberImpl;

class SBomber
{
public:

    SBomber();
    ~SBomber();

    SBomber(SBomber&& rhs);
    SBomber& operator=(SBomber&& rhs);
    
    SBomber(const SBomber& rhs);
    SBomber& operator=(const SBomber& rhs);

    bool GetExitFlag() const;

    void ProcessKBHit();
    void TimeStart();
    void TimeFinish();

    void DrawFrame();
    void MoveObjects();
    void CheckObjects();

    void AnimateScrolling();

private:

    const SBomberImpl* Pimpl() const;
    SBomberImpl* Pimpl();

    std::unique_ptr<SBomberImpl> impl_;
};