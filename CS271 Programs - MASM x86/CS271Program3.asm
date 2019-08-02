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
aesthetic_line	BYTE	"**********************************************", 0
name_title		BYTE	"CS271 400 S2019 Program 3 by Ryan Wells Farran", 0

instructions_1	BYTE	"Please enter numbers in [-100, -1] (inclusive).", 0 ; very similar to project 1
instructions_2	BYTE	"Enter a non-negative number when you are ", 0
instructions_3	BYTE	"finished to observe some calculations!", 0

prompt_1		BYTE	"What's your name?", 0
userName		BYTE	30 DUP(0) ; used to store and also set size of user name, could be larger
count			DWORD	1
accumulator		DWORD	0
roundedAverage	DWORD	0

greeting_1		BYTE	"Hello there, ", 0
greeting_2		BYTE	", buddy ol' pal!", 0

prompt_2		BYTE	". Enter a number: ", 0
number			DWORD	?	;will store how many numbers to display

count_1	BYTE	"You entered "	, 0
count_2	BYTE	" valid numbers."	, 0
calculations_1	BYTE	"The sum of your valid numbers is "	, 0
calculations_2	BYTE	"The rounded average is "	, 0

too_small	BYTE	"INVALID INPUT! Number less than -100!"	, 0
too_big		BYTE	"INVALID INPUT! Number greater than -1!"	, 0

UPPERLIMIT = -1
LOWERLIMIT = -100

;this message tells why the input is invalid
tooSmallError	BYTE	"The number you entered is less than -100!", 0

;same farewell from last assignment!
noValidGoodBye	BYTE	"You entered ZERO valid numberes in [-100, -1]", 0
goodByeMessage_1	BYTE	"Thanks, ", 0
goodByeMessage_2	BYTE	", have a wonderful day! :-)", 0

; Set text color to red on a yellow background!
textColor		DWORD	12
backGColor		DWORD	14

ecprompt_1		BYTE	"**EC: Numbered lines during user input.", 0

;begin main program...
.code
main PROC

 ; Set text color to red on a yellow background!
       mov eax, backGColor
       imul eax, 16
       add eax, textColor
       call setTextColor

; 1. Display your name and program title on the output screen.
	mov		edx, OFFSET aesthetic_line	; code for displaying asterisks
	call	WriteString
	call	CrLf
	mov		edx, OFFSET name_title		; code for displaying Title & Name
	call	WriteString
	call	CrLf
	mov		edx, OFFSET aesthetic_line	; code for displaying asterisks
	call	WriteString
	call	CrLf
	mov		edx, OFFSET ecprompt_1		; prepare to display ec prompt...
	call	WriteString					; display extra credit prompt...
	call	CrLf
	mov		edx, OFFSET aesthetic_line	; code for displaying asterisks
	call	WriteString
	call	CrLf

; 2. Prompt user for their name and then greet the user
	mov		edx, OFFSET aesthetic_line	; code for displaying asterisks
	call	WriteString
	call	CrLf

	mov		edx, OFFSET prompt_1	; code for displaying prompt to user to input name
	call	WriteString	
	call	CrLf

	mov		edx, OFFSET userName	; loads address/OFFSET of userName into EDX
	mov		ecx, SIZEOF userName	; uses SIZEOF to set ECX to ready ReadString PROC call
	call	ReadString

	mov		edx, OFFSET greeting_1
	call	WriteString
	mov		edx, OFFSET userName
	call	WriteString
	mov		edx, OFFSET greeting_2
	call	WriteString
	call	CrLf

; 3. Display instructions for the user.
	mov		edx, OFFSET instructions_1	; code for displaying instructions_1
	call	WriteString
	call	CrLf
	mov		edx, OFFSET instructions_2	; code for displaying instructions_2
	call	WriteString
	call	CrLf
	mov		edx, OFFSET instructions_3	; code for displaying instructions_3
	call	WriteString
	call	CrLf

; 4. Repeatedly prompt the user to enter a number. 
getNumbers:
	mov		eax, count ; for displaying numbered user line using count variable for EC
	call	WriteDec
	inc		eax			; increment eax
	mov		count, eax	; and then move to count after incrementing

	mov		edx, OFFSET prompt_2 ; get the user's input and stores it in "number" variable
	call	WriteString
	call	ReadInt
	mov		number, eax

	cmp		eax, LOWERLIMIT		; test if input is less than bounds
	jl		TooSmall

	cmp		eax, UPPERLIMIT		; test if input is greater than bounds
	jg		TooBig

	add		eax, accumulator	; add the acumulator to eax
	mov		accumulator, eax	; and then move eax to accumulator to copy over it

	loop	getNumbers			; repeat until the control is brought to the CalculateAndDisplay section of program

; 5. Calculate and Display results...
TooSmall: ; this code is displayed if number is out of lower bounds
	mov		edx, OFFSET too_small
	call	WriteString
	call	CrLf
	jmp		CalculateAndDisplay

TooBig:	; this code is displayed if number is out of upper bounds
	mov		edx, OFFSET too_big
	call	WriteString
	call	CrLf
	jmp		CalculateAndDisplay

CalculateAndDisplay:
	mov		eax, count		; at this point the first run, if no valid input, then count will equal 2
	sub		eax, 2
	jz		NoValidEndProg	; Note: if no negative numbers were entered, display a special message and skip to iv.

; i.   the number of negative numbers entered
	mov		edx, OFFSET count_1
	call	WriteString
	mov		eax, count
	sub		eax, 2
	call	WriteDec		; integer variable is "sandwhiched" between two strings
	mov		edx, OFFSET count_2
	call	WriteString
	call	CrLf

; ii.  the sum of negative numbers entered
	mov		edx, OFFSET calculations_1
	call	WriteString
	mov		eax, accumulator
	call	WriteInt
	call	Crlf

; iii. the average, rounded to the nearest integer
	mov		edx, OFFSET calculations_2
	call	WriteString
	mov		eax, 0
	mov		eax, accumulator
	cdq
	mov		ebx, count
	sub		ebx, 2
	idiv	ebx
	mov		roundedAverage, eax
	call	WriteInt
	call	Crlf
	jmp		EndProg

; iv.  a parting message (with the user’s name)

NoValidEndProg: ; "special" message incase user enters zero valid numbers
	mov		edx, OFFSET aesthetic_line
	call	WriteString
	call	CrLf
	mov		edx, OFFSET noValidGoodBye	; parting "goodByeMessage" message for special case where no valid input was entered
	call	WriteString
	call	CrLf
	mov		edx, OFFSET aesthetic_line	; code for displaying asterisks
	call	WriteString
	call	CrLf

EndProg: 
	mov		edx, OFFSET aesthetic_line
	call	WriteString
	call	CrLf
	mov		edx, OFFSET goodByeMessage_1	; parting "goodByeMessage" message 1
	call	WriteString
	mov		edx, OFFSET userName	; display user's name
	call	WriteString
	mov		edx, OFFSET goodByeMessage_2	; parting "goodByeMessage" message 2
	call	WriteString
	call	CrLf
	mov		edx, OFFSET aesthetic_line	; code for displaying asterisks
	call	WriteString
	call	CrLf

	exit	; exit to operating system
main ENDP

; (insert additional procedures here)

END main