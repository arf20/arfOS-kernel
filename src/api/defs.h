// defs.h: OS Wide defines

#ifndef _DEFS_H
#define _DEFS_H

#ifndef _TRUE_FALSE
#define _TRUE_FALSE
typedef enum { false, true } bool;
#endif

#define PACKED __attribute__((packed))

typedef unsigned char	BYTE;
typedef unsigned short	WORD;
typedef unsigned int	DWORD;
typedef void*			PTR;

typedef char*			PCSTR;

#endif