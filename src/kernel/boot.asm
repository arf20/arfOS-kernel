bits 32

section .multiboot               ;according to multiboot spec
        dd 0x1BADB002            ;set magic number for bootloader
        dd 0x0                   ;set flags
        dd - (0x1BADB002 + 0x0)  ;set checksum

section .text
global start
extern kernel_main               ;defined in kernel.c

start:
        cli                      ;block interrupts
        mov esp, stack_space     ;set stack pointer
        call kernel_main
        hlt                      ;halt the CPU

section .bss
resb 8192                        ;8KB for stack
stack_space:
