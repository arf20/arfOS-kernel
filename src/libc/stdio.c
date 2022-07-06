// stdio.c: Standard C input output library implementation
#include "../api/conio.h"

#include <stdarg.h>

// Unformatted I/O
// Prints a char in the console
int putchar(char c) {
    conPutChar(c);
    return c;
}

// Gets a char from the console input
char getchar() {
    return conGetChar();
}

// Prints a string and insersts "\r\n"
int puts(const char *s) {
    int i = 0;
    while (s[i]) {
        putchar(s[i]);
        i++;
    }
    return i;
}

// Formatted I/O
// Prints formatted strings and data
const char *uintstr(unsigned int num, int base) {
    static char buff[33];
    char *ptr;
    ptr = &buff[sizeof(buff) - 1];
    *ptr = '\0';

    do
    {
        *--ptr = "0123456789abcdef"[num % base];
        num /= base;
    } while(num != 0);

    return(ptr);
}

int printf(char *format, ...) {
    char *p;
    int i;
    unsigned u;
    float f;
    char *s;

    va_list arg;
    va_start(arg, format);
    p = format;

    for(p = format; *p != '\0'; p++) {
        if(*p != '%') {
            putchar(*p); continue;
        }
        p++;
        switch(*p) {
            case 'c' : i = va_arg(arg, int); putchar(i); break;
            case 'd' : i = va_arg(arg, int);
            case 'i' : i = va_arg(arg, int);
            if(i < 0) { i = -i; putchar('-'); } puts(uintstr(i, 10)); break;
            case 'o': i = va_arg(arg, unsigned int); puts(uintstr(i, 8)); break;
            case 's': s = va_arg(arg, char *); puts(s); break;
            case 'u': u = va_arg(arg, unsigned int); puts(uintstr(u, 10)); break;
            case 'x': u = va_arg(arg, unsigned int); puts(uintstr(u, 16)); break;
            case 'f':
            case 'F': {
                //f = va_arg(arg, float); puts();
            } break;
            //case 'e': f = va_arg(arg, float); puts(); break;
            //case 'E': f = va_arg(arg, float); puts(); break;
            //case 'g': f = va_arg(arg, float); puts(); break;
            //case 'G': f = va_arg(arg, float); puts(); break;
            //case 'F': f = va_arg(arg, float); puts(); break;
            //case 'a': f = va_arg(arg, float); puts(); break;
            //case 'A': f = va_arg(arg, float); puts(); break;
            //case 'p': u = va_arg(arg, unsigned int); puts(uintstr(u, 16)); break;
            //case 'n': 
            case '%': putchar('%'); break;
        }
    }
    va_end(arg);
}

/*
int scanf(char *format, ...) {
    int i = 0, j=0, ret = 0;
    char buff[256] = {0}, tmp[20], c = '\0';
    char *out_loc;

    while (c != '\n') {
        c = getchar())) 
        buff[i] = c;
        i++;
 	}

    va_list arg;
 	va_start(arg, format);
 	i = 0;
    
 	while (format && format[i]) {
 	    if (format[i] == '%') {
 	       i++;
 	       switch (format[i]) {
 	           case 'c': {
	 	           *(char*)va_arg(arg, char*) = buff[j];
	 	           j++;
	 	           ret++;
	 	           break;
 	           } case 'd': {
	 	           *(int*)va_arg(arg, int*) = strtol(&buff[j], &out_loc, 10);
	 	           j+=out_loc -&buff[j];
	 	           ret++;
	 	           break;
 	            } case 'x': {
	 	           *(int*)va_arg(arg, int*) = strtol(&buff[j], &out_loc, 16);
	 	           j+=out_loc -&buff[j];
	 	           ret++;
	 	           break;
 	            }
 	        }
 	    } 
 	    else {
 	        buff[j] = format[i];
            j++;
        }
        i++;
    }

    va_end(arg);
    return ret;
}*/