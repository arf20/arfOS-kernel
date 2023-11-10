// PS/2 Compatible keyboard driver and functions


#ifndef _H_KEYB
#define _H_KEYB

void KeyboardInit();
void ISRKeyboardHandler();
unsigned char KeyboardPoll();

#endif

