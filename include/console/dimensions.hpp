#ifndef CONSOLE_DIMENSIONS_HPP
#define CONSOLE_DIMENSIONS_HPP

namespace console
{

struct Dimensions
{
    int width;
    int height;

public:
    Dimensions(int width, int height) : width(width), height(height)
    {
    }
};

Dimensions getDimensions();

}

#include "../common/os_check.hpp"

#if UNIX
#include "dimensions_posix.hpp"
#else
#include "dimensions_default.hpp"
#endif // UNIX
// See: http://www.linuxquestions.org/questions/programming-9/get-width-height-of-a-terminal-window-in-c-810739/#post3985193


#endif // CONSOLE_DIMENSIONS_HPP
