// VGA 80x25 text mode driver and functions

#ifndef _H_VGA
#define _H_VGA

#define VGA_ADDRESS 0xB8000

#define VGA_WIDTH     80
#define VGA_HEIGHT    25

#define VGAC_BLACK    0
#define VGAC_BLUE     1
#define VGAC_GREEN    2
#define VGAC_LBLUE    3
#define VGAC_RED      4
#define VGAC_PURPLE   5
#define VGAC_BROWN    6
#define VGAC_LGREY    7
#define VGAC_GREY     8
#define VGAC_CBLUE    9
#define VGAC_LGREEN   10
#define VGAC_CYAN     11
#define VGAC_LRED     12
#define VGAC_LPURPLE  13
#define VGAC_YELLOW   14
#define VGAC_WHITE    15

extern unsigned short *VGABuff;

void outb( unsigned short port, unsigned char val );
unsigned char inb (unsigned short int __port);

void VGAInit();
void VGAWriteChar(unsigned char x, unsigned char y, char c, unsigned char forec, unsigned char backc, unsigned char blink);
void VGAClear();
void VGAScroll();
void VGACursorEnable(unsigned char start, unsigned char end);
void VGACursorDisable();
void VGACursorSet(unsigned short x, unsigned short y);
unsigned short VGACursorGet();

#endif

