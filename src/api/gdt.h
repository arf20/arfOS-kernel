// gdt.h: Global descriptor table init and load
#ifndef _GDT_H
#define _GDT_H

#include "defs.h"

#define GDT_ACCESS_ATTR_NULL        0x00
#define GDT_ACCESS_ATTR_PRESENT     (1 << 7)
#define GDT_ACCESS_ATTR_RING_3      (1 << 5 | 1 << 6)
#define GDT_ACCESS_ATTR_CODEDATA    (1 << 4)
#define GDT_ACCESS_ATTR_EXEC        (1 << 3)
#define GDT_ACCESS_ATTR_READABLE    (1 << 1)
#define GDT_ACCESS_ATTR_WRITABLE    (1 << 1)
#define GDT_ACCESS_ATTR_GROWDOWN    (1 << 2)
#define GDT_ACCESS_ATTR_ALLOWLOW    (1 << 2)

#define GDT_FLAG_ATTR_NULL          0x00
#define GDT_FLAG_ATTR_GRAN1B        0x00
#define GDT_FLAG_ATTR_GRAN4K        (1 << 3)
#define GDT_FLAG_ATTR_S16B          0x00
#define GDT_FLAG_ATTR_S32B          (1 << 2)
#define GDT_FLAG_ATTR_S64B          (1 << 1)

struct GDTEntry {
    WORD limit_low;
    WORD base_low;
    BYTE base_mid;
    BYTE access;
    BYTE limit_high : 4;
    BYTE flags : 4;
    BYTE base_high;
} PACKED;

struct GDTPointer {
    WORD size;
    DWORD addr;
} PACKED;

extern struct GDTEntry GDT[3];
extern BYTE entry_ptr;
extern struct GDTPointer gdt_ptr;

void GDTLoad();

void GDTNewEntry(DWORD base, DWORD limit, BYTE access, BYTE flags);
void GDTInit();

#endif

