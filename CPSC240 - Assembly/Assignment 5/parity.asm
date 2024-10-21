; unsigned short array[7] = {12, 1003, 6543, 24680, 789, 30123, 32766};
; unsigned short even[7];
; register long rsi = 0, rdi = 0;
; do {
; 	if (array[rsi] % 2 == 0) {
;		even[rdi] = array[rsi];
;		rdi++;
;	}
; 	rsi++;
; } while (rsi < 7);

section .data
SYS_exit	equ 60
EXIT_SUCCESS	equ 0
array		dw 12, 1003, 6543, 24680, 789, 30123, 32766
even		times 7 dw 0

section .text
	global _start	
_start:
	mov	rsi, 0
	mov	rdi, 0
	
.loop:
	cmp	rsi, 7
	jge	.exit
	
	mov	ax, [array + rsi*2]
	
	test	ax, 1
	jnz	.not_even
	
	mov	[even + rdi*2], ax
	inc	rdi
	
.not_even:
	inc	rsi
	jmp	.loop
	
.exit:
	mov	eax, SYS_exit
	xor	edi, edi
	syscall
