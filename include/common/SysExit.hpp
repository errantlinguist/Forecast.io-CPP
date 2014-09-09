#ifndef SYSEXIT_HPP
#define SYSEXIT_HPP

#include "os_check.h"

#if UNIX
	#include "SysExit_posix.hpp"
#elif _WIN32
	#include "SysExit_windows.hpp"
#else
	#include "SysExit_default.hpp"
#endif

namespace common
{

constexpr int getSysExitCode(SysExit value)
{
	return static_cast<int>(value);
}

}

#endif // SYSEXIT_HPP
