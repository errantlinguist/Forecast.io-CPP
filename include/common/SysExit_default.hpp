#ifndef SYSEXIT_DEFAULT_HPP
#define SYSEXIT_DEFAULT_HPP

#include <cstdlib>

namespace common
{

enum class SysExit: int
{
	/** Base value for error messages. **/
	_BASE = EXIT_FAILURE,

	/** The command was used incorrectly, e.g., with the wrong number of arguments, a bad flag, a bad syntax in a parameter, or whatever. */
	INVALID_COMMAND_LINE = _BASE,


	/** The input data was incorrect in some way. This should only be used for user's data & not system files. */
	INVALID_DATA = _BASE,


	/** No more data is available. */
	NO_MORE_ITEMS = _BASE,


	/** An input file (not a system file) did not exist or was not readable. This could also include errors like "No message" to a mailer (if it cared to catch it). */
	FILE_NOT_FOUND = _BASE,


	/** An input path (not a system path) did not exist or was not readable. */
	PATH_NOT_FOUND = _BASE,


	/** The user specified did not exist. This might be used for mail addresses or remote logins. */
	NO_SUCH_USER = _BASE,


	/** The host specified did not exist. This is used in mail addresses or network requests. */
	HOST_UNAVAILABLE = _BASE,


	/** The specified service does not exist. */
	SERVICE_UNAVAILABLE = _BASE,


	/** An internal software error has been detected. This should be limited to non-operating system related errors as possible. */
	INTERNAL_ERROR = _BASE,


	/** A (user specified) file or directory cannot be created. */
	CANNOT_CREATE_PATH = _BASE,


	/**  An error occurred while doing I/O on some file. */
	IO_DEVICE_ERROR = _BASE,


	/** The requested protocol has not been configured into the system, or no implementation for it exists. */
	PROTOCOL_UNSUPPORTED = _BASE,


	/** You did not have sufficient permission to perform the operation. This is not intended for file system problems, which should use NOINPUT or CANTCREAT, but rather for higher level permissions. */
	PRIVILEGE_NOT_HELD = _BASE,


	/** The configuration data for this product is corrupt. Contact your support personnel. */
	BAD_CONFIGURATION = _BASE
};


}

#endif // SYSEXIT_DEFAULT_HPP
