TITLE Programming Assignment #1     (Program1.asm)

; Author: Ryan Wells Farran
; Last Modified: 04/20/2019 | Saturday, April 20th 2019
; OSU email address: farranr@oregonstate.edu
; Course number/section: CS 271 400 S2019 (COMPUTER ARCH. & ASSEM. LANGUAGE) 
; Project Number: Programming Assignment #2   Due Date: Sunday, 04/21/2019
; Description: This program displays Fibonacci Numbers. It displays the program title and programmer’s name, 
; then get the user’s name, and greets the user. Ot then prompts the user to enter the number of Fibonacci 
; terms to be displayed and advisse the user to enter an integer in the range [1 .. 46].
; Gets and validatse the user input (n)
; The program then calculates and displasy all of the Fibonacci numbers up to and including the nth term. 
; The results should be displayed 5 terms per line with at least 5 spaces between terms.
; Finally, the program will display a parting message that includes the user’s name, and terminate the program.

INCLUDE Irvine32.inc

.data
aesthetic_line	BYTE	"**********************************************", 0 ; sorry if these aren't okay, I was just having fun with it
name_title		BYTE	"CS271 400 S2019 Program 2 by Ryan Wells Farran", 0

instructions_1	BYTE	"This program will display the number of", 0 ; very similar to project 1
instructions_2	BYTE	"Fibonacci Numbers that you request!", 0


prompt_1		BYTE	"What's your name?", 0
userName		BYTE	25 DUP(0) ; used to store and also set size of user name, could be larger
count			DWORD	?

greeting		BYTE	"Hello, ", 0

prompt_2		BYTE	"How many Fibonacci Numbers will you observe?", 0
prompt_2_2		BYTE	"Enter an integer between 1 & 46: ", 0 ;warns user about input validation
numberFib		DWORD	?	;will store how many numbers to display

;below contains many temp.prev numbers used to store past numbers of fib sequence
prevNum1		DWORD	?
prevNum2		DWORD	?
aestheticSpace	BYTE	"   ", 0
firstNum		BYTE	"1", 0
firstTwo		BYTE	"1   1", 0
tempVar			DWORD	?
modulusFive		DWORD	5

upLimit = 46 ;originally used just regular numbers in cmp segment, but assignment specifically asks to assigna  constant
lowLimit = 1

;these messages tell why the input was wrong
tooBigError		BYTE	"The number you entered is too big! (must be less than or equal to 46)", 0
tooSmallError	BYTE	"The number you entered is too small! (must be greater than zero[0])", 0

;same farewell from last assignment!
goodByeMessage	BYTE	"Thanks, have a wonderful day ... Goodbye! :-)", 0


;begin main program...
.code
main PROC

; 1. Display your name and program title on the output screen.
	mov		edx, OFFSET aesthetic_line	; code for display asterisks
	call	WriteString
	call	CrLf
	mov		edx, OFFSET name_title		; code for display Title & Name
	call	WriteString
	call	CrLf
	mov		edx, OFFSET aesthetic_line	; code for display asterisks
	call	WriteString
	call	CrLf

; 2. Display instructions for the user.
	mov		edx, OFFSET instructions_1	; code for display instructions_1
	call	WriteString
	call	CrLf
	mov		edx, OFFSET instructions_2	; code for display instructions_2
	call	WriteString
	call	CrLf

; 3. Prompt user for their name and then greet the user
	mov		edx, OFFSET aesthetic_line	
	call	WriteString
	call	CrLf

	mov		edx, OFFSET prompt_1	
	call	WriteString	
	call	CrLf

	mov		edx, OFFSET userName
	mov		ecx, SIZEOF userName
	call	ReadString
	mov		count, eax

	mov		edx, OFFSET greeting
	call	WriteString
	mov		edx, OFFSET userName
	call	WriteString
	call	CrLf

TopLoop:
	call	CrLf

; 4. Prompt the user to enter how many Fibonacci Numbers we'll display.
	mov		edx, OFFSET aesthetic_line
	call	WriteString
	call	CrLf

	mov		edx, OFFSET prompt_2	
	call	WriteString	
	call	CrLf

	mov		edx, OFFSET prompt_2_2	
	call	WriteString	
	call	CrLf

	call	ReadInt
	mov		numberFib, eax
	call	CrLf

; 5. Validation segment with loop targets...

	cmp		numberFib, upLimit
	jg		TooBig
	cmp		numberFib, lowLimit
	jl		TooSmall
	je		First1
	cmp		numberFib, 2
	je		First2

; 6. Display fibonacci numbers...
	mov		ecx, numberFib
	sub		ecx, 3	;this accounts for the first two numbers being known (1 & 1 again)

	; Don't be overwhelmed by this code, and remebere, a lot of the lines are just for outputtiing "aestheticSpace"
	; Just read the code line by line and you will see that we are simply storing the past numbers, summing the past two numbers and looping this process

	mov		eax, 1
	call	WriteDec
	mov		edx, OFFSET aestheticSpace
	call	WriteString
	call	WriteDec
	mov		edx, OFFSET aestheticSpace
	call	WriteString ;code above displays the first two values...

	mov		prevNum2, eax
	mov		eax, 2
	call	WriteDec
	mov		edx, OFFSET aestheticSpace
	call	WriteString
	mov		prevNum1, eax

	;again, even though this code might look confusing, there is simply add, mov, and call lines, plus the conditionla loop
	; please see chapters 6 & 7 if unclear
	FibonacciLoop:
		add		eax, prevNum2
		call	WriteDec
		mov		edx, OFFSET aestheticSpace
		call	WriteString

		mov		tempVar, eax
		mov		eax, prevNum1
		mov		prevNum2, eax
		mov		eax, tempVar
		mov		prevNum1, eax

		;conditional handles first time using modulus 3
		mov		edx, ecx
		cdq
		div		modulusFive
		cmp		dx, 0
		jne		Pass
		call	CrLf

Pass:
		mov		eax, tempVar
		loop	FibonacciLoop
		jmp		EndProg


;Loop Targets below

TooBig:
	mov		edx, OFFSET aesthetic_line
	call	WriteString
	call	CrLf

	mov		edx, OFFSET tooBigError
	call	WriteString
	jmp		TopLoop

TooSmall:
	mov		edx, OFFSET aesthetic_line
	call	WriteString
	call	CrLf

	mov		edx, OFFSET tooSmallError
	call	WriteString
	jmp		TopLoop

First1:
	mov		edx, OFFSET firstNum
	call	WriteString
	call	CrLf
	jmp		EndProg

First2:	
	mov		edx, OFFSET firstTwo
	call	WriteString
	call	CrLf
	jmp		EndProg


; 5. Display a terminating message. 
EndProg: 
	mov		edx, OFFSET aesthetic_line
	call	WriteString
	call	CrLf
	mov		edx, OFFSET goodByeMessage	; terminating "goodByeMessage" message
	call	WriteString
	call	CrLf
	mov		edx, OFFSET aesthetic_line	; code for displaying asterisks
	call	WriteString
	call	CrLf

	exit	; exit to operating system
main ENDP

; (insert additional procedures here)

END main
