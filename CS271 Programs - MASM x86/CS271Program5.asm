TITLE Programming Assignment #5     (Program4.asm)

; Author: Ryan Wells Farran
; Last Modified: 05/27/2019 | Monday, May 27th 2019
; OSU email address: farranr@oregonstate.edu | Phone number: 480-734-6450
; Course number/section: CS 271 400 S2019 (COMPUTER ARCH. & ASSEM. LANGUAGE) 
; Project Number: Programming Assignment #5   Due Date: Sunday, 05/26/2019
; Description: 

INCLUDE Irvine32.inc

.data
; Set text color to green on a blue background! used in setColors function
textColor		DWORD	16 ; black
backGColor		DWORD	27 ; red

aesthetic_line	BYTE	"**********************************************", 0
name_title		BYTE	"CS271 400 S2019 Program 5 by Ryan Wells Farran", 0

instructions_1	BYTE	"This program generates random numbers in the range [100...999],", 0
instructions_2	BYTE	"displays the original list, sorts the list, and calculates the", 0
instructions_3	BYTE	"median value. Finally, it displays the list sorted in descending order.", 0

prompt_1		BYTE	"How many random numbers will you generate?", 0

MIN = 10
MAX = 200
LO = 100
HI = 999

printUnsorted	BYTE	"The unsorted random numbers: ", 0
printSorted		BYTE	"The sorted list: ", 0
medianMessage	BYTE	"The median is ", 0

number			DWORD	?	; will store how many numbers to display
count	DWORD	?		; size of array chose by user 
list	DWORD	MAX	DUP(?) ; array for holding the random numbers up to the max amount of numbers
randNum	DWORD	?		; will store the randomly generated numbers
range	DWORD	?
randArrSize	DWORD	?

count_1	BYTE	"Okay, we'll observe  "	, 0
count_2	BYTE	" random numbers."	, 0
spaces	BYTE	"     ", 0
lineCounter		DWORD	1	; counts the elements per line to follow the 10 per row rule

too_small		BYTE	"INVALID INPUT! Number less than 10!"	, 0
too_big			BYTE	"INVALID INPUT! Number greater than 200!", 0
tryagain		BYTE	"Try again!"	, 0

;begin main program...
.code
main PROC
	call	Randomize		; call this functin only once to create a seed for random numbers to be generated in EAX
	call	setColors		; sets the colors of the background and text
	call	introduction	; introduces the programmer, program, and class name
	call	instructions	; describes the purpose of the program
	
	call	getData			; gets and validates number of random numbers to generate from user

	push	OFFSET range
	push	count
	push	OFFSET list
	push	count
	call	fillArray		; gets stack ready before calling fillArray function

	push	OFFSET printUnsorted
	push	OFFSET list
	push	count
	call	displayList		; gets stack ready before calling displayList function

	push	OFFSET list
	push	count
	call	reverseBubbleSort

	push	OFFSET medianMessage
	push	OFFSET list
	push	count
	call	displayMedian

	push	OFFSET printSorted
	push	OFFSET list
	push	count
	call	displayList		; gets stack ready before calling displayList function

	exit	; exit to operating system
main ENDP

; (insert additional procedures here)

;----------------------------------------------------------
; - Function Name: setColors
; - Description: this function changes the background 
; and text colors by (bg * 16) + tc where bg and tc are values
; saved in the .data secion of the code (backGColor & textColor)
;----------------------------------------------------------
setColors PROC
	pushad ; save resgisters
	mov eax, backGColor 
	imul eax, 16
	add eax, textColor
	call setTextColor
	popad ; restore registers
	ret ; return control to main function
setColors ENDP

;----------------------------------------------------------
; - Function Name: introduction
; - Description:
;
;----------------------------------------------------------
introduction PROC
	pushad
	mov		edx, OFFSET aesthetic_line	; code for displaying asterisks
	call	WriteString
	call	CrLf
	mov		edx, OFFSET name_title		; code for displaying Title & Name
	call	WriteString
	call	CrLf
	mov		edx, OFFSET aesthetic_line	; code for displaying asterisks
	call	WriteString
	call	CrLf
	popad
	ret
introduction ENDP

;----------------------------------------------------------
; - Function Name: instructions
; - Description:
;
;----------------------------------------------------------
instructions PROC
	pushad
	mov		edx, OFFSET instructions_1	; code for displaying instructions_1
	call	WriteString
	call	CrLf
	mov		edx, OFFSET instructions_2	; code for displaying instructions_2
	call	WriteString
	call	CrLf
	mov		edx, OFFSET instructions_3	; code for displaying instructions_3
	call	WriteString
	call	CrLf
	popad
	ret
instructions ENDP

;----------------------------------------------------------
; - Function Name: getData (calls validate)
; - Description:
;
;----------------------------------------------------------
getData PROC
	pushad
	mov		edx, OFFSET aesthetic_line	; code for displaying asterisks
	call	WriteString
	call	CrLf
	mov		edx, OFFSET prompt_1 ; get the user's input and stores it in "number" variable
	call	WriteString
	call	CrLf
	call	validate
	mov		edx, OFFSET aesthetic_line	; code for displaying asterisks
	call	WriteString
	call	CrLf
	popad
	ret
getData ENDP

;----------------------------------------------------------
; - Function Name: validate (is called by getData)
; - Description:
;
;----------------------------------------------------------
validate PROC
	pushad
getNumber:
	call	ReadInt
	mov		number, eax
	cmp		eax, MIN		; test if input is less than bounds
	jl		TooSmall
	cmp		eax, MAX		; test if input is greater than bounds
	jg		TooBig
	mov		count, eax	; stores variable in count to be used in loop per instructions
	jmp		endGetUserData
TooSmall: ; this code is displayed if number is out of lower bounds
	mov		edx, OFFSET too_small
	call	WriteString
	call	CrLf
	mov		edx, OFFSET tryagain
	call	WriteString
	call	CrLf
	jmp		getNumber
TooBig:	; this code is displayed if number is out of upper bounds
	mov		edx, OFFSET too_big
	call	WriteString
	call	CrLf
	mov		edx, OFFSET tryagain
	call	WriteString
	call	CrLf
	jmp		getNumber
endGetUserData:
	mov		edx, OFFSET count_1
	call	WriteString
	mov		eax, count
	call	WriteDec		; integer variable is "sandwhiched" between two strings
	mov		edx, OFFSET count_2
	call	WriteString
	call	CrLf
	popad
	ret
validate ENDP

;----------------------------------------------------------
; - Function Name: fillArray
; - Description:
;
;----------------------------------------------------------
fillArray PROC
	push	ebp			; save the old EBP
	mov		ebp, esp	; move ESP to EBP

	; calculate the range
	mov		eax, HI
	sub		eax, LO
	inc		eax
	mov		ebx, [ebp+20] ; range is on the stack at [ebp+20]
	mov		[ebx], eax	; stores range by dereferencing ebx, which points to range

	; Continuously generate random numbers and save them in the elements of the array
	mov		ecx, [ebp+16]	; set loop counter
	mov		esi, [ebp+12]	; element 0 of the array list (1st element)

RandomCreation:
	mov		ebx, [ebp+20]	
	mov		eax, [ebx]
	call	RandomRange
	add		eax, LO

	mov		[esi], eax
	add		esi, 4		; 4 because array is of type DWORD

	; increment by 1
	mov		ebx, [ebp+8]
	mov		eax, 1
	;add		[ebx], eax

	loop	RandomCreation

	pop		ebp
	ret		16 ; returns control to main procedure and clears 16 extra bytes 
fillArray ENDP

;----------------------------------------------------------
; - Function Name: displayList (is called by showComposites)
; - Description:
;
;----------------------------------------------------------
displayList PROC
	push	ebp
	mov		ebp, esp

	;display the title
	mov		edx, [ebp+16]
	call	WriteString
	call	CrLf

	;display the array's contents
	mov		ecx, [ebp+8]		; counter
	mov		esi, [ebp+12]		; array

Print:
	mov		eax, [esi]
	call	WriteDec

	mov		edx, OFFSET spaces
	call	WriteString
	mov		eax, lineCounter
	mov		ebx, 10
	mov		edx, 0
	div		ebx
	cmp		edx, 0
	jne		CurrentLine
	call	CrLf
CurrentLine:
	add		esi, 4
	inc		lineCounter
	loop	Print

	call	Crlf
	pop ebp
	ret
displayList ENDP

;----------------------------------------------------------
; - Function Name: reverseBubbleSort
; - Description:
;
;----------------------------------------------------------
reverseBubbleSort PROC
	push	ebp
	mov		ebp, esp
	mov		ecx, [ebp+8]
L1:
	mov		esi, [ebp+12]
	mov		edx, ecx
L2:
	mov		eax, [esi]
	mov		ebx, [esi+4]
	cmp		ebx, eax
	jle		L3
	mov		[esi], ebx
	mov		[esi+4], eax
L3:
	add		esi, 4
	loop	L2
	mov		ecx, edx
	loop	L1

	pop		ebp
	ret		8
reverseBubbleSort ENDP

;----------------------------------------------------------
; - Function Name: displayMedian
; - Description:
;
;----------------------------------------------------------
displayMedian PROC
	push	ebp
	mov		ebp, esp

	; odd or even
	mov		eax, [ebp+8]
	mov		edx, 0
	mov		ebx, 2
	div		ebx
	cmp		edx, 0
	je		IsEven

	;array is odd
	inc		eax
	jmp		DisplayToConsole

IsEven:
	mov		ebx, eax
	inc		ebx
	add		eax, ebx
	mov		ebx, 2
	div		ebx
	jmp		DisplayToConsole

DisplayToConsole:
	mov		edx, OFFSET medianMessage
	call	WriteString
	call	WriteDec
	call	CrLf

	pop		ebp
	ret		12
displayMedian ENDP

END main