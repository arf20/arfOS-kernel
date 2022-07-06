// string.h: Standard C string manipulation library

#ifndef _STRING_H
#define _STRING_H

// Start
#ifndef NULL
#define NULL 0x00000000
#endif

#ifndef _SIZE_T
#define _SIZE_T
typedef unsigned int size_t;
#endif

const char *strcpy(char *dst, const char *src);

const char *strncpy(char *dst, const char *src, size_t count);

const char *strcat(char *dst, const char *src);

const char *strncat(char *dst, const char *src, size_t count);

size_t strlen(const char *str);

int strcmp(const char *str1, const char *str2);

int strncmp(const char *str1, const char *str2, size_t count);

const char *strchr(const char *str, const char c);

const char *strrchr(const char *str, const char c);

size_t strspn(const char *str, const char *set);

size_t strcspn(const char *str, const char *set);

const char *strpbrk(const char *str, const char *set);

const char *strstr(const char *str1, const char *str2);

#endif