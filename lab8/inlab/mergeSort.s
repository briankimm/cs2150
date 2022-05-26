; University of Virginia
; CS 2150 In-Lab 8
; Spring 2018
; mergeSort.s	
	;; Brian Kim, byk6q, mergeSort.s, 11/2/21
	global mergeSort
	global merge

	section .text


; Parameter 1 is a pointer to the int array  rdi
; Parameter 2 is the left index in the array rsi
; Parameter 3 is the right index in the array rdx
; Return type is void 
mergeSort:
	cmp 	rsi, rdx	;compares left and right
	jge	endMerge	;if right < left, it's done

	;; left side of the array
	mov	r11, rsi	;stores r11(start(for now)) 
	add	r11, rdx	;r11 becomes left + right
	shr	r11, 1		;r11 = mid
	mov	r12, rdx	;r12 = last
	mov	r10, rsi	;r10 = start
	mov 	rdx, r11	;moves mid into rdx


	push 	r10
	push 	r11
	push 	r12
		

	call	mergeSort	;recursive call
	;; right side of the array
	pop	r12
	pop	r11
	pop	r10


	inc	r11		;mid++
	mov	rsi, r11	;moves mid into rsi
	mov	rdx, r12	;moves last into rdx


	push 	r10
	push 	r11
	push	r12


	call 	mergeSort	;recursive call
	;; merges the two halves together
	
	pop	r12
	pop	r11
	pop	r10


	mov 	rsi, r10	;moves start into rsi
	dec	r11		;mid--
	mov	rdx, r11	;moves mid into rdx
	mov	rcx, r12	;moves last into rcx

	call 	merge
endMerge:

	
; Parameter 1 is a pointer to the int array 
; Parameter 2 is the left index in the array
; Parameter 3 is the middle index in the array 
; Parameter 4 is the right index in the array
; Return type is void 
merge:
	; Save callee-save registers
	; Store local variables 
	push rbx			; int i
	push r12			; int j
	push r13			; int k
	push r14			; int n1
	push r15			; int n2
	
	mov r14, rdx			; n1 = mid - left + 1
	sub r14, rsi
	inc r14

	mov r15, rcx			; n2 = right - mid 
	sub r15, rdx

	lea r11, [r14+r15]		; r11 = rsp offset = 4(n1 + n2)
	lea r11, [4*r11]		
	sub rsp, r11			; allocate space for temp arrays

	mov rbx, 0			; i = 0
	mov r12, 0			; j = 0
	
; Copy elements of arr[] into L[]	
copyLloop:
	cmp rbx, r14			; is i >= n1?
	jge copyRloop
					; L[i] = arr[left + i]
	lea r10, [rsi+rbx]		
	mov r10d, DWORD [rdi+4*r10]	; r10 = arr[left + i]
	mov DWORD [rsp+4*rbx], r10d	; L[i] = r10
	inc rbx				; i++
	jmp copyLloop

; Copy elements of arr[] into R[]
copyRloop:
	cmp r12, r15			; is j >= n2?
	jge endcopyR
 					; R[j] = arr[mid + 1 + j]
	lea r10, [rdx+r12+1]	
	mov r10d, DWORD [rdi+4*r10]	; r10 = arr[mid + 1 + j]
	lea rax, [r12+r14]		
	mov DWORD [rsp+4*rax], r10d	; R[j] = r10
	inc r12				; j++
	jmp copyRloop

endcopyR:	
	mov rbx, 0			; i = 0
	mov r12, 0			; j = 0
	mov r13, rsi			; k = left

; Merge L[] and R[] into arr[]
mergeLoop:
	cmp rbx, r14			; is i >= n1 or j >= n2?
	jge loopL
	cmp r12, r15
	jge loopL
	lea r10, [r12+r14]
	mov r10d, DWORD [rsp+4*r10] 	; r10d = R[j]
	cmp DWORD [rsp+4*rbx], r10d	; is L[i] <= R[j]?
	jle if
	mov DWORD [rdi+4*r13], r10d	; arr[k] = R[j]
	inc r12				; j++
	jmp endif 
if:
	mov r10d, DWORD [rsp+4*rbx] 
	mov DWORD [rdi+4*r13], r10d	; arr[k] = L[i] 
	inc rbx				; i++
endif:	
	inc r13				; k++	
	jmp mergeLoop
	
; Copy elements of L[] into arr[]
loopL:				
	cmp rbx, r14			; is i >= n1?
	jge loopR
	mov r10d, DWORD [rsp+4*rbx] 
	mov DWORD [rdi+4*r13], r10d	; arr[k] = L[i]
	inc rbx				; i++
	inc r13				; k++
	jmp loopL

; Copy elements of R[] into arr[]
loopR:	
	cmp r12, r15			; is j >= n2?
	jge endR
	lea r10, [r12+r14]
	mov r10d, DWORD [rsp+4*r10] 	
	mov DWORD [rdi+4*r13], r10d	; arr[k] = R[j]

	inc r12				; j++
	inc r13				; k++
	jmp loopR
	
endR:
	; deallocate temp arrays
	; restore callee-save registers
	add rsp, r11	
	pop r15			
	pop r14
	pop r13
	pop r12
	pop rbx
	ret
