; multiple.asm;
; unsigned short num = 65535;
; unsigned short mul_3 = 0, other = 0;
; if(num % 3 == 0 && num % 5 != 0) { mul_3++; } else { other++; };

section .data
SYS_exit	equ 60
EXIT_SUCCESS	equ 0
num		dw 65535
mul_3		dw 0
other		dw 0

section .text
    global _start
_start:
	mov	ax, [num]
    
	mov	bx, 3
	xor	dx, dx
	div	bx
	cmp	dx, 0
	jne	increment_other

	mov	ax, [num]
	mov	bx, 5
	xor	dx, dx
	div	bx
	cmp	dx, 0
	je	increment_other

	mov	ax, [mul_3]
	inc	ax
	mov	[mul_3], ax
	jmp	exit

increment_other:
	mov	ax, [other]
	inc	ax
	mov	[other], ax

exit:
	mov	rax, SYS_exit
	mov	rdi, EXIT_SUCCESS
	syscall
