// idt.c: Initialize IDT and load it

#include "defs.h"
#include "idt.h"
#include "keyb.h"
#include "io.h"

void IDTNewEntry(BYTE idx, DWORD offset, WORD selector, BYTE type) {
	IDT[idx].offset_low = 	(offset >>  0) & 0xFFFF;
    IDT[idx].offset_high = 	(offset >> 16) & 0xFFFF;
    IDT[idx].selector = selector * 8;
    IDT[idx].type = type;
    IDT[idx].zero = 0x00;
}

void IDTInit()
{
	for (BYTE i = 0; i < 256; i++) {
        IDTNewEntry(i, (DWORD)&ASM_ISR0, 0x01, IDT_ATTR_PRESENT | IDT_ATTR_TYPE_TRAP | IDT_ATTR_PRIV_3);
    }
}