; multiplication.asm;
; unsigned int num1 = 300,000;
; unsigned int num2 = 400,000;
; unsigned long product = 0;
; product = long(num1 * num2);

section .data
SYS_exit	equ 60
EXIT_SUCCESS	equ 0
num1		dd 300000
num2		dd 400000
product		dq 0

section .text
	global _start
_start:
	mov	eax, dword[num1]
	mov	ebx, dword[num2]
	mul	ebx
    
	mov	[product], eax
	mov	[product+4], edx

	mov	rax, SYS_exit
	mov	rdi, EXIT_SUCCESS
	syscall
