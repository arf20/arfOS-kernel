# Compile and assemble all

# Compile and assemble kernel
nasm -f elf32						        							src/kernel/boot.asm	-o   obj/boot.o
gcc  -Wall -m32 -fno-pie -fno-stack-protector -c -Wno-builtin-declaration-mismatch					src/kernel/kernel.c	-o   obj/kernel.o

# Compile and assemble API
nasm -f elf32                                      									src/api/idt.asm 	-o   obj/idtasm.o
gcc  -Wall -m32 -fno-pie -fno-stack-protector -c   									src/api/idt.c		-o   obj/idt.o
nasm -f elf32														src/api/isr.asm		-o   obj/israsm.o
gcc  -Wall -m32 -fno-pie -fno-stack-protector -c									src/api/isr.c		-o   obj/isr.o

gcc  -Wall -m32 -fno-pie -fno-stack-protector -c                                                                        src/api/panic.c           -o   obj/panic.o

nasm -f elf32                                     									src/api/gdt.asm 	-o   obj/gdtasm.o
gcc  -Wall -m32 -fno-pie -fno-stack-protector -c 									src/api/gdt.c		-o   obj/gdt.o

gcc  -Wall -m32 -fno-pie -fno-stack-protector -c -Wno-builtin-declaration-mismatch					src/api/keyb.c		-o   obj/keyb.o
gcc  -Wall -m32 -fno-pie -fno-stack-protector -c -Wno-builtin-declaration-mismatch					src/api/vga.c		-o   obj/vga.o
gcc  -Wall -m32 -fno-pie -fno-stack-protector -c -Wno-builtin-declaration-mismatch					src/api/conio.c  	-o   obj/conio.o

nasm -f elf32                                      									src/api/io.asm		-o   obj/ioasm.o
gcc  -Wall -m32 -fno-pie -fno-stack-protector -c -Wno-builtin-declaration-mismatch					src/api/io.c		-o   obj/io.o

# Compile libc
gcc  -Wall -m32 -fno-pie -fno-stack-protector -c -Wno-builtin-declaration-mismatch					src/libc/stdio.c	-o   obj/stdio.o
gcc  -Wall -m32 -fno-pie -fno-stack-protector -c -Wno-builtin-declaration-mismatch					src/libc/stdlib.c	-o   obj/stdlib.o
gcc  -Wall -m32 -fno-pie -fno-stack-protector -c -Wno-builtin-declaration-mismatch					src/libc/string.c	-o   obj/string.o

# Link everything
ld -m elf_i386 -T linker.ld -o kernel obj/*.o
