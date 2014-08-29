#ifndef CONSOLE_DIMENSIONS_POSIX_HPP
#define CONSOLE_DIMENSIONS_POSIX_HPP

#include <sys/ioctl.h>
#include <unistd.h>

// See: http://www.linuxquestions.org/questions/programming-9/get-width-height-of-a-terminal-window-in-c-810739/#post3985193

namespace console
{

#ifdef TIOCGWINSZ
Dimensions getDimensions()
	{
		struct winsize ts;
		ioctl(STDIN_FILENO, TIOCGWINSZ, &ts);
		return Dimensions(ts.ws_col, ts.ws_row);
    }
#elif defined(TIOCGSIZE)
	Dimensions getDimensions()
	{
		struct ttysize ts;
		ioctl(STDIN_FILENO, TIOCGSIZE, &ts);
		return Dimensions(ts.ts_cols, ts.ts_lines);
	}
#else
	#include "dimensions_default.hpp"
#endif // TIOCGWINSZ

}

#endif // CONSOLE_DIMENSIONS_POSIX_HPP
