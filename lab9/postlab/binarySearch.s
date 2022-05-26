	;; Brian Kim, byk6q, binarySearch.s, 11/19/21
	global binarySearch
	section .text
	;; first parameter is a pointer to an int array(edi)
	;; second parameter is an integer representing the beginning of the array(esi)
	;; third parameter is an integer representing the end of the array(edx)
	;; fourth parameter is an integer representing the target element(ecx)

binarySearch:
	mov	eax, -1		;sets return register equal to -1
	xor	r10d, r10d	;r10d is mid, setting it to 0
start:
	cmp	esi, edx	;while(low<=high)
	jg	end		;if low > high, jump to end: didn't find element

	mov	r10d, esi	;r10d is mid: moves low into mid
	add	r10d, edx	;adds high
	shr	r10d, 1		;divides by 2

	cmp	ecx, DWORD [rdi+(4*r10)] ;compares target element to a[i]
	jl	less		    ;if less, jumps to less than
	jg	greater	    ;if greater, jumps to greater than
	je	equal		    ;if equal, jumps to equal
less:
	mov	edx, r10d	;moves mid to high
	dec	edx		;subtracts one from high
	jmp 	start		;jumps back to the start of the loop
greater:
	mov	esi, r10d	;moves mid to low
	inc	esi		;adds one to low
	jmp	start		;jumps back to the start of the loop
equal:
	mov 	eax, r10d	;moves value of mid into return register
	ret
end:
	ret
	
