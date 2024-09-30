; division.asm;
; unsigned long num1 = 50,000,000,000;
; unsigned int num2 = 3,333,333;
; unsigned int quotient = 0, remainder = 0;
; quotient = num1 / num2;
; remainder = num1 % num 2;

section .data
SYS_exit	equ 60
EXIT_SUCCESS	equ 0
num1		dq 50000000000
num2		dd 3333333
quotient	dd 0
remainder	dd 0

section .text
	global _start
_start:
	mov	eax, dword[num1]
	mov	edx, dword[num1+4]
	mov	ebx, dword[num2]
	div	ebx
	
	mov	[quotient], eax
	mov	[remainder], edx
	
	mov	rax, SYS_exit
	mov	rdi, EXIT_SUCCESS
	syscall
