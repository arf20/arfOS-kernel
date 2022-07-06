; idtisr.asm: IDTLoad and ISR routines

global IDTLoad

; Load IDT on memory & activate interrupts
IDTLoad:
	mov edx, [esp + 4]				; Load IDT address in edx
	lidt [edx]						; Load IDT
	sti 							; Turn on interrupts
	ret