// stdio.h: Standard C input output library
#ifndef _STDIO_H
#define _STDIO_H

// Macros
#ifndef EOF
#define EOF -1
#endif

#ifndef _SIZE_T
#define _SIZE_T
typedef unsigned int size_t;
#endif

// Functions
// Unformatted I/O
// Prints a char in the console
int putchar(const char c);

// Gets a char from the console input
int getchar();

// Prints a string and insersts "\r\n"
int puts(const char *str);

// Formatted I/O
const char *uintstr(unsigned int num, int base);

// Prints formatted strings and data
int printf(const char *format, ...);

#endif