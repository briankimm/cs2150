	;; Brian Kim, byk6q, threexplusone.s, 11/16/21
	global threexplusone
	section .text
	;; first param (input) rdi
threexplusone:
	xor 	rax, rax	;zero out return register
start:
	cmp	rdi, 1		;base case
	je	end		;if the input is equal to 1, go to end
	test	rdi, 1		;test to see if input in rdi if it is even
	jg	three		;if greater than 0, it's odd
	shr	rdi, 1 		;even: bit shifts to right by 1 byte
	inc	rax		;increments by one
	jmp 	start 		;jumps back to start
three:
	lea	rdi, [rdi*2+rdi+1];multiplies contents of rdi by 3 + 1 (optimization)
	inc	rax		  ;increments by one
	jmp	start		;goes back to the start
end:
	ret
