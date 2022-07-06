#include "gdt.h"

/*static void GDTLoad() {
    asm volatile("lgdt %0\n"
		"pushq %%rbp\n"
		"movq %%rsp, %%rbp\n"
		"pushq %1\n"
		"pushq %%rbp\n"
		"pushfq\n"
		"pushq %2\n"
		"pushq $1f\n"
		"iretq\n"
		"1:\n"
		"popq %%rbp\n"
		"mov %1, %%ds\n"
		"mov %1, %%es\n"
		"mov %1, %%fs\n"
		"mov %1, %%gs\n"
		"mov %1, %%ss\n"
		:: "m"(gpointer), "r"((uint64_t)0x10), "r"((uint64_t)0x08)
		: "memory");
}*/

void GDTNewEntry(DWORD base, DWORD limit, BYTE access, BYTE flags) {
    struct GDTEntry *entry = &GDT[entry_ptr++];

    entry->base_low  = (base & 0x0000ffff);
    entry->base_mid  = (base & 0x00ff0000) >> 16;
    entry->base_high = (base & 0xff000000) >> 24;

    entry->access = access;
    entry->flags = flags;
    
    entry->limit_low  = (limit & 0x0000ffff);
    entry->limit_high = (limit & 0x00ff0000) >> 16;
}

void GDTInit() {
	entry_ptr = 0;
	
    // Initialize 3 entries
    // Null
    GDTNewEntry(0, 0, GDT_ACCESS_ATTR_NULL, GDT_FLAG_ATTR_NULL);
    // Code
    BYTE access = GDT_ACCESS_ATTR_CODEDATA | GDT_ACCESS_ATTR_PRESENT | GDT_ACCESS_ATTR_EXEC | GDT_ACCESS_ATTR_READABLE;
    GDTNewEntry(0, 0xffffffff, access, GDT_FLAG_ATTR_GRAN4K | GDT_FLAG_ATTR_S32B);
    // Data
    access = GDT_ACCESS_ATTR_CODEDATA | GDT_ACCESS_ATTR_PRESENT | GDT_ACCESS_ATTR_WRITABLE;
    GDTNewEntry(0, 0xffffffff, access, GDT_FLAG_ATTR_GRAN4K | GDT_FLAG_ATTR_S32B);

    // Pointer to GDT
    gdt_ptr.addr = (DWORD)GDT;
    gdt_ptr.size = sizeof(GDT) - 1;

    // Load GDT in to the CPU from ptr
    GDTLoad(gdt_ptr);
}