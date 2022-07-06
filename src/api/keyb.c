//keyb.c: IRQ1 Keyboard input handler, and polling routine

#include "keyb.h"
#include "conio.h"
#include "io.h"
#include "defs.h"

void KeyboardInit() {
	
}

void ISRKeyboardHandler() {
	print("Key hit\r\n");
}


/*
0x60	Read/Write	Data Port
0x64	Read	Status Register
0x64	Write	Command Register
*/

unsigned char KeyboardPoll() {
	while (true) {
		if (inb(0x64) & 0x01) {
			char keyCode = inb(0x60);
			if (keyCode > 0)
				return (unsigned char)keyCode;
		}
	}
}