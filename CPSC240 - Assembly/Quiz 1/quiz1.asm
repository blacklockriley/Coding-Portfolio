; quiz1.asm;
; signed short num1 = +30000;
; signed short num2 = +20000;
; signed short num3 = -3333;
; signed int sum = 0;
; signed short quo = 0;
; signed short rmd = 0;
; sum = int(num1 + num2);
; quo = sum / num3;
; rmd = sum % num3;

section .data
SYS_exit	equ 60
EXIT_SUCCESS	equ 0
num1		dw 30000
num2		dw 20000
num3		dw -3333
sum		dd 0
quo		dw 0
rmd		dw 0

section .text
	global _start
_start:
	mov	ax, word[num1]
	add	ax, word[num2]
	adc	dx, 0
	
	mov	[sum], ax
	mov	[sum+2], dx
	
	mov	ax, [sum]
	mov	dx, [sum+2]
	mov	bx, word[num3]
	idiv	bx
	
	mov	word[quo], ax
	mov	word[rmd], dx
	
	mov	rax, SYS_exit
	mov	rdi, EXIT_SUCCESS
	syscall
