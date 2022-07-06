// stdlib.c: C standard library
#ifndef _STDLIB_H
#define _STDLIB_H

// Macros
#ifndef _SIZE_T
#define _SIZE_T
typedef unsigned int size_t;
#endif

#ifndef NULL
#define NULL 0x00000000
#endif

#ifndef EXIT_FAILURE
#define EXIT_FAILURE -1
#endif

#ifndef EXIT_SUCCESS
#define EXIT_SUCCESS 0
#endif

#ifndef RAND_MAX
#define RAND_MAX 0xffff
#endif


#endif