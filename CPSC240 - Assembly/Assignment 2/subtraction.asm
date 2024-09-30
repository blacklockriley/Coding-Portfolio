; subtraction.asm;
; signed short num1 = 0x1234;
; signed short num2 = 0xFEDC;
; signed int dif = 0;
; dif = int(num1 - num2);

section .data
SYS_exit	equ	60
EXIT_SUCCESS	equ	0
num1		dw	0x1234
num2		dw	0xFEDC
dif		dd	0

section .text
	global _start
_start:
	mov	eax, dword[num1]
	sub	eax, dword[num2]
	sbb	edx, 0
	
	mov	[dif], eax
	mov	[dif+2], edx
	
	mov	rax, SYS_exit
	mov	rdi, EXIT_SUCCESS
	syscall
