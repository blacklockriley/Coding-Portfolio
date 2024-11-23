; input.asm;
; char msg1[] = "Input a number (1~9): ";
; char msg2[] = " is a Multiple of 3.";
; char buffer[2];
; char num;
; char ascii[10];
; register int r10 = 0;
; do {
; 	cout << msg1;
; 	cin >> buffer;
; 	ascii[r10] = buffer;
; 	r10++;
; } while(r10 < 9);
; r10 = 0;
; do {
; 	num = atoi(ascii[r10]);
; 	if(num%3 == 0) {
; 		cout << ascii[r10] << msg2;
; 	}
; 	r10++;
; } while(r10 < 9);

section .data
msg1 		db "Input a number (1~9): ", 0
msg2		db " is a Multiple of 3.", 0
newline		db 10, 0

section .bss
buffer		resb 2
ascii		resb 10

section .text
	global _start

_start:
	; Initialize r10 to 0
	xor	r10, r10

input_loop:
	; Print msg1
	mov	rax, 1		; sys_write
	mov	rdi, 1		; file descriptor (stdout)
	mov	rsi, msg1	; message to write
	mov	rdx, 23		; message length
	syscall			; call kernel
	
	; Read input into buffer
	mov	rax, 0		; sys_read
	mov	rdi, 0		; file descriptor (stdin)
	mov	rsi, buffer	; buffer to store input
	mov	rdx, 2		; number of bytes to read
	syscall			; call kernel
	
	; Store input in ascii array
	mov	al, [buffer]
	mov	[ascii + r10], al
	
	; Increment r10
	inc	r10
	
	; Check if r10 < 9
	cmp	r10, 9
	jl	input_loop
	
	; Reset r10 to 0
	xor	r10, r10
	
check_loop:
	; Load ASCII character from ascii array
	movzx	rax, byte [ascii + r10]
	
	; Convert ASCII to integer by subtracting '0'
	sub	rax, '0'
	
	; Check if the number is a multiple of 3
	xor	rdx, rdx
	mov	rbx, 3
	div	rbx
	cmp	rdx, 0
	jne	not_multiple
	
	; Print the number
	mov	rax, 1		; sys_write
	mov	rdi, 1		; file descriptor (stdout)
	lea	rsi, [ascii + r10]
	mov	rdx, 1		; number of bytes to write
	syscall			; call kernal
	
	; Print msg2
	mov	rax, 1		; sys_write
	mov	rdi, 1		; file descriptor (stdout)
	mov	rsi, msg2	; message to write
	mov	rdx, 21		; message length
	syscall			; call kernel
	
	; Print newline
	mov	rax, 1		; sys_write
	mov	rdi, 1		; file descriptor (stdout)
	mov	rsi, newline	; newline character
	mov	rdx, 1		; number of bytes to write
	syscall			; call kernel
	
not_multiple:
	; Increment r10
	inc	r10
	
	; Check if r10 < 9
	cmp	r10, 9
	jl	check_loop
	
	; Exit program
	mov	rax, 60		; sys_exit
	xor	rdi, rdi	; exit code 0
	syscall			; call kernel
