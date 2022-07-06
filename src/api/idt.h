// idt.h: Interrupt descriptor table init and load
#include "defs.h"

#define IDT_SIZE 256
#define KERNEL_CODE_SEGMENT_OFFSET 0x08
#define INTERRUPT_GATE 0x8e

#define IDT_ATTR_PRESENT    0x80
#define IDT_ATTR_PRIV_3     0x60
#define IDT_ATTR_PRIV_2     0x40
#define IDT_ATTR_PRIV_1     0x20
#define IDT_ATTR_TYPE_INT   0x0E
#define IDT_ATTR_TYPE_TRAP  0x0F
#define IDT_ATTR_TYPE_TASK  0x15

struct IDTEntry {
	WORD offset_low;
	WORD selector;
	BYTE zero;
	BYTE type;
	WORD offset_high;
};

struct IDTPointer {
	WORD size;
	DWORD addr;
};

struct IDTEntry IDT[IDT_SIZE];


extern void ASM_ISR0(void);
extern void ASM_ISRPIT(void);
extern void ASM_ISRKeyboard(void);
extern void ASM_ISRFloppy(void);
extern void ASM_ISRSysCall(void);

extern void _isr0(void);
extern void _isr1(void);
extern void _isr2(void);
extern void _isr3(void);
extern void _isr4(void);
extern void _isr5(void);
extern void _isr6(void);
extern void _isr7(void);
extern void _isr8(void);
extern void _isr9(void);
extern void _isr10(void);
extern void _isr11(void);
extern void _isr12(void);
extern void _isr13(void);
extern void _isr14(void);
extern void _isr15(void);
extern void _isr16(void);
extern void _isr17(void);
extern void _isr18(void);
extern void _isr19(void);
extern void _isr20(void);
extern void _isr21(void);
extern void _isr22(void);
extern void _isr23(void);
extern void _isr24(void);
extern void _isr25(void);
extern void _isr26(void);
extern void _isr27(void);
extern void _isr28(void);
extern void _isr29(void);
extern void _isr30(void);
extern void _isr31(void);

extern void IDTLoad();

void IDTInit();