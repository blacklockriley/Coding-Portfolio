; print.asm;
; Calculates 1 + 2 + 3 + ... + 99 and displays the result;
; char string[1] = "1+2+3+...+99=";
; short sum = 0;
; char ascii[5] = "0000\n";
; register short cx = 1;
; for(cx = 1; cx <= 99; cx++)
;	sum += cx;
; ascii = itoa(sum);
; cout << str1 << ascii;

section .data
string		db "1+2+3+...+99=", 0
ascii		db "0000", 10, 0

section .bss
sum		resd 1

section .text
	global _start
	
_start:
	mov 	dword[sum], 0
	mov 	ecx, 1
	
calculate_sum:
	add	dword[sum], ecx
	inc	ecx
	
	cmp	ecx, 100
	jl	calculate_sum
	
	mov	eax, [sum]
	call	itoa
	
	mov	eax, 4
	mov	ebx, 1
	mov	ecx, string
	mov	edx, 14
	int	0x80
	
	mov	eax, 4
	mov	ebx, 1
	mov	ecx, ascii
	mov	edx, 5
	int	0x80
	
	mov	eax, 1
	xor	ebx, ebx
	int	0x80

itoa:
	mov	edi, ascii + 3
	mov	ecx, 10

itoa_loop:
	xor edx, edx
	div ecx
	add dl, '0'
	mov [edi], dl
	dec edi
	test eax, eax
	jnz itoa_loop
	
	ret
