// kernel.c: Kernel main routine, init everything

#include "../api/gdt.h"
#include "../api/idt.h"
#include "../api/defs.h"
#include "../api/vga.h"
//#include "../api/conio.h"
#include "../api/keyb.h"

#include "../libc/stdio.h"

void kernel_main() {
	GDTInit();

	VGAInit();
	VGACursorEnable(13, 15);
	VGACursorSet(0, 0);
	
	printf("arfOS very alpha indeed, by arf20\r\nSo alpha you shouldn't be installing this on real hardware, are you stupid?\r\nAnyways, this is a keyboard and libc printf test (do note this is the first time ever I implement libc)\r\n\r\n");
	
	//IDTInit();
	
	//scan();
	
	/*while (true) {
		KeyboardPoll();
		print("AAAAAAAAAAAAAAAAA\r\n");
	}*/


	int i = 0;
	
	while (true) {
		KeyboardPoll();
		const char *str = uintstr(i, 10);
		printf("printf & keyb test %s xD\r\n", str);
		i++;
	}
	
    return;
}
