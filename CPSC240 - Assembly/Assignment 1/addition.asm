; addition.asm;
; unsigned short num1 = 0xFEDC;
; unsigned short num2 = 0x1234;
; unsigned int sum = 0;
; sum = int(num1 + num2);

section .data
SYS_exit	equ	60
EXIT_SUCCESS	equ	0
num1		dw	0xFEDC
num2		dw	0x1234
sum		dd	0

section .text
	global _start
_start:
	mov	ax, word[num1]
	add	ax, word[num2]
	adc	dx, 0
	
	mov	[sum], ax
	mov	[sum+2], dx
	
	mov	rax, SYS_exit
	mov	rdi, EXIT_SUCCESS
	syscall
