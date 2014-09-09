#ifndef OS_CHECK_H
#define OS_CHECK_H

#ifndef UNIX
	#if defined (__unix__) || (defined (__APPLE__) && defined (__MACH__))
		#define UNIX true
	#endif
#endif

#endif // OS_CHECK_H
