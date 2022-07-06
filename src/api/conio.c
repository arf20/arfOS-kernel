// conio.c: Console Input Output routines

#include "conio.h"
#include "defs.h"
#include "vga.h"
#include "keyb.h"
#include "keymap.h"

#ifndef _H_CONIO
	#define _H_CONIO
#endif

unsigned char consoleX = 0;
unsigned char consoleY = 0;

void conPutChar(char c) {
	if (c == '\0') {
		return;
	}
	else if (c == '\r') {
		consoleX = 0;
	}
	else if (c == '\n') {
		if (consoleY + 1 < 25) consoleY++;
		else VGAScroll();
	}
	else if (c == '\b') {
		consoleX--;
	}
	else {
		VGAWriteChar(consoleX, consoleY, c, VGAC_WHITE, VGAC_BLACK, 0);
	
		if (consoleX > VGA_WIDTH) {
			consoleX = 0;
			consoleY++;
		}
		
		consoleX++;
	}
	
	VGACursorSet(consoleX, consoleY);
}

char conGetChar() {
	return keymap_US[KeyboardPoll()];
}

void print(char* str) {
	int i = 0;
	while (true) {
		if (str[i] == '\0') {
			return;
		}
		else if (str[i] == '\r') {
			consoleX = 0;
			i++;
		}
		else if (str[i] == '\n') {
			if (consoleY + 1 < 25) consoleY++;
			else VGAScroll();
			i++;
		}
		else if (str[i] == '\b') {
			consoleX--;
			i++;
		}
		else {
			VGAWriteChar(consoleX, consoleY, str[i], VGAC_WHITE, VGAC_BLACK, 0);
			
			i++;
		
			if (consoleX >= VGA_WIDTH) {
				consoleX = 0;
				if (consoleY + 1 < 25) consoleY++;
				else VGAScroll();
			}
			
			consoleX++;
		}
		
		VGACursorSet(consoleX, consoleY);
	}
}

void scan() {
	while (true) {
		//putchar(KeyboardPoll());
		char code = KeyboardPoll();
		switch (code) {
			case '\n': 
				print("\r\n\0");
			break;
			case '\b':
				print("\b \b");
			break;
			default: conPutChar(code);
		}
	}
}