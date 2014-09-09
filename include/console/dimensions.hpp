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

#include "../common/os_check.h"

#if UNIX
#include "dimensions_posix.hpp"
#else
#include "dimensions_default.hpp"
#endif // UNIX


#endif // CONSOLE_DIMENSIONS_HPP
