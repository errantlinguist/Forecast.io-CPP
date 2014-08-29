/*
 * to_string_win32.hpp
 *
 *  Created on: 29.01.2014
 *      Author: errantlinguist
 *
 * This header file is a workaround for a bug which appears in MinGW due to a non-standard declaration of the function "vswprintf" --
 * see the relevant GCC bug at "http://gcc.gnu.org/bugzilla/show_bug.cgi?id=37522" and an explanation of the workaround at "http://stackoverflow.com/a/8543540/1391325".
 *
 * For the (missing) definitions this header is a workaround for, see the standard MinGW heade filer ".../lib/gcc/mingw32/<VERSION>/include/c++/bits/basic_string.h";
 * The broken condition (In MinGW version 4.8.1, this starts on line 2812):
 *
 * #if ((__cplusplus >= 201103L) && defined(_GLIBCXX_USE_C99) \
 *   && !defined(_GLIBCXX_HAVE_BROKEN_VSWPRINTF))
 *
 *   ...
 *
 * #endif
 *
 */

#ifndef TO_STRING_MINGW_HPP
#define TO_STRING_MINGW_HPP


#if (!((__cplusplus >= 201103L) && defined(_GLIBCXX_USE_C99) \
     && !defined(_GLIBCXX_HAVE_BROKEN_VSWPRINTF)))

#include <sstream>
#include <string>

namespace std
{

template<typename T>
constexpr string to_string(const T& value)
{
	stringstream ss(stringstream::out);
	ss << value;
	const string result = ss.str();
	return result;
}

}


#endif

#endif /* TO_STRING_MINGW32_HPP */
