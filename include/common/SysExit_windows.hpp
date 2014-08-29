#ifndef SYSEXIT_WINDOWS_HPP
#define SYSEXIT_WINDOWS_HPP

#include <WinError.h>

namespace common
{

enum class SysExit: int
{

	/** Base value for error messages. NOTE: Defined here as "1" because Windows uses a whole lot more error codes than POSIX, which defines the base as "64". **/
	_BASE = 1,


	/** The command was used incorrectly, e.g., with the wrong number of arguments, a bad flag, a bad syntax in a parameter, or whatever. */
	INVALID_COMMAND_LINE = ERROR_INVALID_COMMAND_LINE,


	/** The input data was incorrect in some way. This should only be used for user's data & not system files. */
	INVALID_DATA = ERROR_INVALID_DATA,


	/** No more data is available. */
	NO_MORE_ITEMS = ERROR_NO_MORE_ITEMS,


	/** An input file (not a system file) did not exist or was not readable. This could also include errors like "No message" to a mailer (if it cared to catch it). */
	FILE_NOT_FOUND = ERROR_FILE_NOT_FOUND,


	/** An input path (not a system path) did not exist or was not readable. */
	PATH_NOT_FOUND = ERROR_PATH_NOT_FOUND,


	/** The user specified did not exist. This might be used for mail addresses or remote logins. */
	NO_SUCH_USER = ERROR_NO_SUCH_USER,


	/** The host specified did not exist. This is used in mail addresses or network requests. */
	HOST_UNAVAILABLE = HOST_NOT_FOUND,


	/** The specified service does not exist. */
	SERVICE_UNAVAILABLE = ERROR_SERVICE_NOT_FOUND,


	/** An internal software error has been detected. This should be limited to non-operating system related errors as possible. */
	INTERNAL_ERROR = ERROR_INTERNAL_ERROR,


	/** A (user specified) file or directory cannot be created. */
	CANNOT_CREATE_PATH = ERROR_CANNOT_MAKE,


	/**  An error occurred while doing I/O on some file. */
	IO_DEVICE_ERROR = ERROR_IO_DEVICE,


	/** The requested protocol has not been configured into the system, or no implementation for it exists. */
	PROTOCOL_UNSUPPORTED = WSAEPROTONOSUPPORT,


	/** You did not have sufficient permission to perform the operation. This is not intended for file system problems, which should use NOINPUT or CANTCREAT, but rather for higher level permissions. */
	PRIVILEGE_NOT_HELD = ERROR_PRIVILEGE_NOT_HELD,


	/** The configuration data for this product is corrupt. Contact your support personnel. */
	BAD_CONFIGURATION = ERROR_BAD_CONFIGURATION


};

}

#endif // SYSEXIT_WINDOWS_HPP
