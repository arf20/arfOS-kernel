# Pack kernel in ISO
grub-file --is-x86-multiboot kernel
cp kernel iso/boot/
cp grub.cfg iso/boot/grub/
grub-mkrescue -o kernel.iso iso/
