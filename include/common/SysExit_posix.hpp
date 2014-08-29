#ifndef SYSEXIT_POSIX_HPP
#define SYSEXIT_POSIX_HPP

#include <sysexits.h>

namespace common
{

enum class SysExit: int
{
	/** Base value for error messages. **/
	_BASE = EX__BASE,

	/** The command was used incorrectly, e.g., with the wrong number of arguments, a bad flag, a bad syntax in a parameter, or whatever. */
	INVALID_COMMAND_LINE = EX_USAGE,


	/** The input data was incorrect in some way. This should only be used for user's data & not system files. */
	INVALID_DATA = EX_DATAERR,


	/** No more data is available. */
	NO_MORE_ITEMS = EX_NOINPUT,


	/** An input file (not a system file) did not exist or was not readable. This could also include errors like "No message" to a mailer (if it cared to catch it). */
	FILE_NOT_FOUND = EX_NOINPUT,


	/** An input path (not a system path) did not exist or was not readable. */
	PATH_NOT_FOUND = EX_NOINPUT,


	/** The user specified did not exist. This might be used for mail addresses or remote logins. */
	NO_SUCH_USER = EX_NOUSER,


	/** The host specified did not exist. This is used in mail addresses or network requests. */
	HOST_UNAVAILABLE = EX_NOHOST,


	/** The specified service does not exist. */
	SERVICE_UNAVAILABLE = EX_UNAVAILABLE,


	/** An internal software error has been detected. This should be limited to non-operating system related errors as possible. */
	INTERNAL_ERROR = EX_SOFTWARE,


	/** A (user specified) file or directory cannot be created. */
	CANNOT_CREATE_PATH = EX_CANTCREAT,


	/**  An error occurred while doing I/O on some file. */
	IO_DEVICE_ERROR = EX_IOERR,


	/** The requested protocol has not been configured into the system, or no implementation for it exists. */
	PROTOCOL_UNSUPPORTED = EX_PROTOCOL,


	/** You did not have sufficient permission to perform the operation. This is not intended for file system problems, which should use NOINPUT or CANTCREAT, but rather for higher level permissions. */
	PRIVILEGE_NOT_HELD = EX_NOPERM,


	/** The configuration data for this product is corrupt. Contact your support personnel. */
	BAD_CONFIGURATION = EX_CONFIG
};


}

#endif // SYSEXIT_POSIX_HPP
