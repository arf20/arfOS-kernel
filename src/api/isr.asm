align   4
global _isr0
global _isr1
global _isr2
global _isr3
global _isr4
global _isr5
global _isr6
global _isr7
global _isr8
global _isr9
global _isr10
global _isr11
global _isr12
global _isr13
global _isr14
global _isr15
global _isr16
global _isr17
global _isr18
global _isr19
global _isr20
global _isr21
global _isr22
global _isr23
global _isr24
global _isr25
global _isr26
global _isr27
global _isr28
global _isr29
global _isr30
global _isr31

_isr0:
    cli
    push 0
    push 0
    jmp isr_common_stub

_isr1:
    cli
    push 0
    push 1
    jmp isr_common_stub

_isr2:
    cli
    push 0
    push 2
    jmp isr_common_stub

_isr3:
    cli
    push 0
    push 3
    jmp isr_common_stub

_isr4:
    cli
    push 0
    push 4
    jmp isr_common_stub

_isr5:
    cli
    push 0
    push 5
    jmp isr_common_stub

_isr6:
    cli
    push 0
    push 6
    jmp isr_common_stub

_isr7:
    cli
    push 0
    push 7
    jmp isr_common_stub

_isr8:
    cli
    push 8
    jmp isr_common_stub

_isr9:
    cli
    push 9
    jmp isr_common_stub

_isr10:
    cli
    push 10
    jmp isr_common_stub

_isr11:
    cli
    push 11
    jmp isr_common_stub

_isr12:
    cli
    push 12
    jmp isr_common_stub

_isr13:
    cli
    push 13
    jmp isr_common_stub

_isr14:
    cli
    push 14
    jmp isr_common_stub

_isr15:
    cli
    push 15
    jmp isr_common_stub

_isr16:
    cli
    push 16
    jmp isr_common_stub

_isr17:
    cli
    push 17
    jmp isr_common_stub

_isr18:
    cli
    push 18
    jmp isr_common_stub

_isr19:
    cli
    push 19
    jmp isr_common_stub

_isr20:
    cli
    push 20
    jmp isr_common_stub

_isr21:
    cli
    push 21
    jmp isr_common_stub

_isr22:
    cli
    push 22
    jmp isr_common_stub

_isr23:
    cli
    push 23
    jmp isr_common_stub

_isr24:
    cli
    push 24
    jmp isr_common_stub

_isr25:
    cli
    push 25
    jmp isr_common_stub

_isr26:
    cli
    push 26
    jmp isr_common_stub

_isr27:
    cli
    push 27
    jmp isr_common_stub

_isr28:
    cli
    push 28
    jmp isr_common_stub

_isr29:
    cli
    push 29
    jmp isr_common_stub

_isr30:
    cli
    push 30
    jmp isr_common_stub

_isr31:
    cli
    push 31
    jmp isr_common_stub

extern _fault_handler
isr_common_stub:
    pusha
    push ds
    push es
    push fs
    push gs
    mov ax, 0x10
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax
    mov eax, esp
    push eax
    call _fault_handler
    pop eax
    pop gs
    pop fs
    pop es
    pop ds
    popa
    add esp, 8
    iret

extern ISR0
global ASM_ISR0
ASM_ISR0:
    pusha
    push ds
    push es
    push fs
    push gs
    push ebx
    mov bx, 0x10
    mov ds, bx
    pop ebx

    cld 		; C code following the sysV ABI requires DF to be clear on function entry
    call ISR0

    pop gs
    pop fs
    pop es
    pop ds
    popa
    iret

extern ISRPIT
global ASM_ISRPIT
ASM_ISRPIT:
    pusha
    push ds
    push es
    push fs
    push gs
    push ebx
    mov bx, 0x10
    mov ds, bx
    pop ebx

    cld 		; C code following the sysV ABI requires DF to be clear on function entry
    call ISRPIT

    pop gs
    pop fs
    pop es
    pop ds
    popa
    iret

extern ISRKeyboard
global ASM_ISRKeyboard
ASM_ISRKeyboard:
    pusha
    push ds
    push es
    push fs
    push gs
    push ebx
    mov bx, 0x10
    mov ds, bx
    pop ebx

    cld 		; C code following the sysV ABI requires DF to be clear on function entry
    call ISRKeyboard

    pop gs
    pop fs
    pop es
    pop ds
    popa
    iret

extern ISRFloppy
global ASM_ISRFloppy
ASM_ISRFloppy:
    pusha
    push ds
    push es
    push fs
    push gs
    push ebx
    mov bx, 0x10
    mov ds, bx
    pop ebx

    cld 		; C code following the sysV ABI requires DF to be clear on function entry
    call ISRFloppy

    pop gs
    pop fs
    pop es
    pop ds
    popa
    iret

extern ISRSysCall
global ASM_ISRSysCall
ASM_ISRSysCall:
    pusha
    push ds
    push es
    push fs
    push gs
    push ebx
    mov bx, 0x10
    mov ds, bx
    pop ebx
    
    cld 		; C code following the sysV ABI requires DF to be clear on function entry
    push edx
    push ecx
    push ebx
    push eax
    call ISRSysCall
    pop eax
    pop ebx
    pop ecx
    pop edx
    
    pop gs
    pop fs
    pop es
    pop ds
    popa
    iret