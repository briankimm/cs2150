	;; Brian Kim, byk6q, mathlib.s, 11/1/21

	global product
	global power
	section .text

product:
	xor	rax, rax	;zero out the return register
	xor	r10, r10	;zero out i
multiply:
	cmp	r10, rsi	; if i equals cou
	je 	multiplyDone	;exits out because its done 
	add	rax, rdi	;else adds x to rax
	dec	rsi		;decrements counter
	jmp	multiply	;jumps back to the beginning of loop
multiplyDone:
	ret			;returns rax
power:
	mov	rax, 1		;base case
	cmp	rsi, 0 		;checks to see if the exponent is 0
	je	end		;if so, jump to end of program	
	dec	rsi		;decrements counter
	call 	power		;calls power recursively
	mov	rsi, rax	;moves what is in rax to rsi
	call	product		;calls product and returns rsi
end:	
	ret			;returns value
	
