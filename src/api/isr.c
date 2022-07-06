#include "panic.h"
#include "io.h"

struct regs
{
    unsigned int gs, fs, es, ds;      /* pushed the segs last */
    unsigned int edi, esi, ebp, esp, ebx, edx, ecx, eax;  /* pushed by 'pusha' */
    unsigned int int_no, err_code;    /* our 'push byte #' and ecodes do this */
    unsigned int eip, cs, eflags, useresp, ss;   /* pushed by the processor automatically */ 
};

char *exception_messages[] ={
    "Division By Zero",
    "Debug",
    "Non Maskable Interrupt",
    "Break Point",
    "Into Detect Overflow",
    "Out of bounds Exception",
    "Invalid Opcode",
    "No Coprocessor",
    "Double Fault",
    "Coprocessor Segment Overrun",
    "Bad TSS Exception",
    "Segment not present",
    "Stack Fault",
    "General Protection Fault",
    "Page Fault",
    "Unknown Interrupt",
    "Coprocessor Fault",
    "Alignement Check Exception",
    "Machine Check Exception",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved"
};

void ISR0(void) {
	outb(0x20,0x20); // STFU no one cares XD
}

void ISRPIT(void) {
	outb(0x20,0x20);
	//system tick
}

void ISRKeyboard(void) {
	//update keuboard
	outb(0x20,0x20);
}

void ISRFloppy(void) {
	//floppy shit
	outb(0x20,0x20);
}

void ISRSysCall(DWORD id, DWORD ebx, DWORD ecx, DWORD edx) {
	//execute syscall
}

void _fault_handler(struct regs *r) {
	if (r->int_no < 32)
	{
		DWORD val;
		asm volatile ( "mov %%cr2, %0" : "=r"(val) );
		kernel_panic(val, exception_messages[r->int_no]);
		for (;;);
	}
}