// Memory management
#include "defs.h"

#ifndef _H_MEMM
#define _H_MEMM

#define	MEMS_RESERVED	0
#define MEMS_ALLOC		1
#define MEMS_FREE		2

struct MemEntry {
	BYTE status;
	WORD PID;
}

// Kernel side
void MemManInit();

// Application side
PTR RealAlloc();
void RealFree();

#endif

