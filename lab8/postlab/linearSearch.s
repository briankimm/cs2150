	;; Brian Kim, byk6q, linearSearch.s, 11/5/21

	global linearSearch
	section .text
	;;first param (array) rdi
	;; second param (size) rsi
	;; third param (target) rdx
linearSearch:
	mov 	rax, -1		; set return register to -1
	xor 	r10, r10	; r10 is i, setting it to 0

start:
	cmp 	rsi, r10	;checks to see if i == size
	je 	end		;goes to the end
	
	cmp 	edx, [rdi+(4*r10)]	; compare third param (target) to a[i]
	je 	equal			; if not equal, increment i

	inc 	r10		;increment i
	jmp 	start		;jumps back to the beginning of the loop

equal:
	mov 	rax, r10	; moves i into return value
	jmp 	end		; jumps to end 	


end:
	ret			;returns i
	
