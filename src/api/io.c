#include "io.h"

void outb( unsigned short port, unsigned char val) {
   asm volatile("outb %0, %1" : : "a"(val), "Nd"(port) );
}

unsigned char inb(unsigned short int __port) {
  unsigned char _v;
  __asm__ __volatile__ ("inb %w1,%0":"=a" (_v):"Nd" (__port));
  return _v;
}