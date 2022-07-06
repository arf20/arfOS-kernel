#include "defs.h"
#include "vga.h"
#include "io.h"

void VGAInit() {
	VGABuff = (unsigned short *)VGA_ADDRESS;
}

void VGAWriteChar(unsigned char x, unsigned char y, char c, unsigned char forec, unsigned char backc, unsigned char blink) {
	VGABuff[x + (80 * y)] = (unsigned short)((unsigned short)c | ((unsigned short)forec << 8) | ((unsigned short)backc << 12) | ((unsigned short)blink << 15));
}

void VGAClear() {
	for (int y = 0; y < VGA_HEIGHT; y++)
		for (int x = 0; x < VGA_WIDTH; x++)
			VGABuff[x + (VGA_WIDTH * y)] = (unsigned short)0x0000;
}

void VGAScroll() {
	for (int y = 1; y < VGA_HEIGHT; y++)
		for (int x = 0; x < VGA_WIDTH; x++)
			VGABuff[x + (VGA_WIDTH * (y - 1))] = VGABuff[x + (VGA_WIDTH * y)];
		
	for (int x = 0; x < VGA_WIDTH; x++)
		VGABuff[x + (VGA_WIDTH * (VGA_HEIGHT - 1))] = (unsigned short)0x0000;
}

void VGACursorEnable(unsigned char cursorStart, unsigned char cursorEnd) {
	outb(0x3D4, 0x0A);
	outb(0x3D5, (inb(0x3D5) & 0xC0) | cursorStart);
 
	outb(0x3D4, 0x0B);
	outb(0x3D5, (inb(0x3D5) & 0xE0) | cursorEnd);
}

void VGACursorDisable() {
	outb(0x3D4, 0x0A);
	outb(0x3D5, 0x20);
}

void VGACursorSet(unsigned short x, unsigned short y) {
	unsigned short pos = (unsigned short)x + ((unsigned short)y * VGA_WIDTH);
 
	outb(0x3D4, 0x0F);
	outb(0x3D5, (unsigned char)(pos & 0xFF));
	outb(0x3D4, 0x0E);
	outb(0x3D5, (unsigned char)((pos >> 8) & 0xFF));
}

unsigned short VGACursorGet() {
	unsigned short pos = 0;
    outb(0x3D4, 0x0F);
    pos |= inb(0x3D5);
    outb(0x3D4, 0x0E);
    pos |= ((unsigned short)inb(0x3D5)) << 8;
    return pos;
}