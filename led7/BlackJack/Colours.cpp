#include "Colours.h"

Colours::Colours(const Code c_colour)
    : code_colour_(c_colour) {}

int Colours::get_code() const
{
    return static_cast<int>(code_colour_);
}

Colours::~Colours() {}