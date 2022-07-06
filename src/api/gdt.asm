; gdt.asm: GDTLoad
global GDTLoad

GDTLoad:
    mov edx, [esp + 4]
    lgdt [edx]
    ;call GDTFlush
    ret


GDTFlush:
    mov ebx, [esp]

    
    mov eax, 0x10
    mov ds, eax
    mov es, eax
    mov fs, eax
    mov gs, eax
    mov ss, eax

    hlt
    push ebx
    ret

GDTFlush_old3:
    ;mov ebp, esp
    mov ebx, esp
    ;pushfd

    mov eax, 0x10
    mov ds, eax
    mov es, eax
    mov fs, eax
    mov gs, eax
    mov ss, eax

    ;mov esp, ebp
    push ebx
    ;popfd
    ret



GDTFlush_old2:
    mov ebp, esp
    pushfd

    mov eax, 0x10
    mov ds, eax
    mov es, eax
    mov fs, eax
    mov gs, eax
    mov ss, eax

    mov esp, ebp
    iretd


GDTFlush_old:
    push ebp
    mov ebp, esp

    pushfd             ; EFLAGS
    push DWORD 0x08    ; return code segment selector
    push DWORD .L0     ; return instruction pointer
    iretd
.L0:
    pop ebp
    mov eax, 0x10
    mov ds, eax
    mov es, eax
    mov fs, eax
    mov gs, eax
    mov ss, eax
    ret
