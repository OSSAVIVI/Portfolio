TITLE Programming Assignment #1     (Program1.asm)

; Author: Ryan Wells Farran
; Last Modified: 04/14/2019 | Sunday, April 14th 2019
; OSU email address: farranr@oregonstate.edu
; Course number/section: CS_271_400_S2019 (COMPUTER ARCH. & ASSEM. LANGUAGE) 
; Project Number: Programming Assignment #1   Due Date: Sunday, 04/14/2019
; Description: This will program will ask the user for two numbers and display their sum, difference, product, 
; quotient and remainder of division. It will greet the user, ask for two numbers, calculate, then display.
; Two out of three extra credit criterias were implemented an there are output lines for each one as required.
; Program asks user if they want to run the program again at its end and requires the second number entered is less than the first.

INCLUDE Irvine32.inc

.data
aesthetic_line	BYTE	"**********************************************", 0 ; sorry if these aren't okay, I was just having fun with it
name_title		BYTE	"CS271_400_S2019 Program 1 by Ryan Wells Farran", 0
instructions_1	BYTE	"This program requests two numbers, calculates", 0
instructions_2	BYTE	"their sum, difference, product, quotient", 0
instructions_3	BYTE	"(and remainder), and then display the results.", 0
prompt_1		BYTE	"Please enter a value for Number One: ", 0
numberOne		DWORD	?				;first number to be entered by user
prompt_2		BYTE	"Please enter a value for Number Two: ", 0
numberTwo		DWORD	?				;second number to be entered by user
sumResult		DWORD	?				;variable to store the sum of numberOne and numberTwo
sumDisplay		BYTE	"The sum of ", 0
diffResult		DWORD	?				;variable to store the difference of numberOne and numberTwo
diffDisplay		BYTE	"The difference between ", 0
mulResult		DWORD	?				;variable to store the product of numberOne and numberTwo
mulDisplay		BYTE	"The product of ", 0
divResult		DWORD	?				;variable to store the quotient of numberOne and numberTwo
divDisplay		BYTE	"The quotient of ", 0
remResult		DWORD	?				;variable to store the remainder of numberOne and numberTwo
remDisplay		BYTE	", remainder ", 0
displayPeriod	BYTE	".", 0
displayAnd		BYTE	" and ", 0
displayIs		BYTE	" is ", 0
goodByeMessage	BYTE	"Thanks, have a wonderful day ... Goodbye! :-)", 0

; Code for Extra credit below...
prompt_EC1		BYTE	"Having fun? Enter 1 to continue, 0 to quit: ", 0
prompt_EC1_2	BYTE	"**EC1: Program loops until user inputs to quit", 0
EC1_input		DWORD	?		; user will store 1 or 0 to this variable to regulate loop/quit
prompt_EC2		BYTE	"**EC2: Program verifes 2nd number < 1st number", 0
warning_EC2		BYTE	"Sorry, but 2nd number must be less than 1st!", 0

prompt_EC3		BYTE	"**EC3: Extra Credit Option 3 was not attempted"

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
	mov		edx, OFFSET instructions_2	; code for display instructions_1
	call	WriteString
	call	CrLf
	mov		edx, OFFSET instructions_3	; code for display instructions_1
	call	WriteString
	call	CrLf

	; Extra credit output lines per instructions: "you must add one print statement to your
	; program output PER EXTRA CREDIT"
	mov		edx, OFFSET prompt_EC1_2	; gets first extra credit prompt ready for display
	call	WriteString
	call	CrLf
	mov		edx, OFFSET prompt_EC2		; gets second extra credit prompt ready for display
	call	WriteString
	call	CrLf
	mov		edx, OFFSET prompt_EC3		; gets third extra credit prompt ready for display
	call	WriteString
	call	CrLf

; 3. Prompt the user to enter two numbers.
start:	
	mov		edx, OFFSET aesthetic_line	; end instructions/EC with display asterisks
	call	WriteString
	call	CrLf

	mov		edx, OFFSET prompt_1		; Next four lines are for 
	call	WriteString					; entering in value for numberOne
	call	ReadInt
	mov		numberOne, eax

	mov		edx, OFFSET prompt_2		; Next four lines are for
	call	WriteString					; entering in value for numberTwo
	call	ReadInt
	mov		numberTwo, eax

	mov		eax, numberTwo
	cmp		eax, numberOne
	jge		WarningEC2
	jl		Calculations

WarningEC2:
	mov		edx, OFFSET aesthetic_line	; asterisks on top of warning message
	call	WriteString
	call	CrLf

	mov		edx, OFFSET warning_EC2
	call	WriteString
	call	CrLf
	jmp		LoopOption

; 4. Calculate the sum, difference, product, (integer) quotient and remainder of the numbers. 
Calculations:
	mov		edx, OFFSET aesthetic_line	; code for displaying asterisks to seperate next section
	call	WriteString
	call	CrLf

	;sum
	mov		edx, OFFSET sumDisplay		; the following code displays text and numberOne and numberTwo
	call	WriteString
	mov		eax, numberOne
	call	WriteDec
	mov		edx, OFFSET displayAnd
	call	WriteString
	mov		eax, numberTwo
	call	WriteDec
	mov		edx, OFFSET displayIs
	call	WriteString
	mov		eax, numberOne				; calculates sum and stores result in eax
	add		eax, numberTwo
	mov		sumResult, eax				; moves result to a variable to store before printing
	call	WriteDec					; prints value of eax (sum from previous calculation)
	mov		edx, OFFSET displayPeriod	; ends with period (notice CrFl was not called so period stayed on same line)
	call	WriteString
	call	CrLf						; jumps to next line

	;difference
	mov		edx, OFFSET diffDisplay		; the following code displays text and numberOne and numberTwo
	call	WriteString
	mov		eax, numberOne
	call	WriteDec
	mov		edx, OFFSET displayAnd
	call	WriteString
	mov		eax, numberTwo
	call	WriteDec
	mov		edx, OFFSET displayIs
	call	WriteString
	mov		eax, numberOne				; calculates difference and stores result in eax
	sub		eax, numberTwo
	call	WriteDec					; prints value of eax (sum from previous calculation)
	mov		edx, OFFSET displayPeriod	; ends with period (notice CrFl was not called so period stayed on same line)
	call	WriteString
	call	CrLf						; jumps to next line

	;product
	mov		edx, OFFSET mulDisplay		; the following code displays text and numberOne and numberTwo
	call	WriteString
	mov		eax, numberOne
	call	WriteDec
	mov		edx, OFFSET displayAnd
	call	WriteString
	mov		eax, numberTwo
	call	WriteDec
	mov		edx, OFFSET displayIs
	call	WriteString
	mov		eax, numberOne				; calculates difference and stores result in eax
	mul		numberTwo
	call	WriteDec					; prints value of eax (sum from previous calculation)
	mov		edx, OFFSET displayPeriod	; ends with period (notice CrFl was not called so period stayed on same line)
	call	WriteString
	call	CrLf						; jumps to next line

	;division
	mov		edx, OFFSET divDisplay		; the following code displays text and numberOne and numberTwo
	call	WriteString
	mov		eax, numberOne
	call	WriteDec
	mov		edx, OFFSET displayAnd
	call	WriteString
	mov		eax, numberTwo
	call	WriteDec
	mov		edx, OFFSET displayIs
	call	WriteString
	mov		edx, 0
	mov		eax, numberOne				
	mov		ebx, numberTwo
	cdq
	div		ebx							; calculates division and stores quotient in eax and remainder in edx
	mov		divResult, eax 
	mov		remResult, edx
	call	WriteDec					; prints value of eax (quotient from previous calculation)
	mov		edx, OFFSET remDisplay
	call	WriteString
	mov		eax, remResult
	call	WriteDec
	mov		edx, OFFSET displayPeriod	; ends with period (notice CrFl was not called so period stayed on same line)
	call	WriteString
	call	CrLf						; jumps to next line

; EC1 code implemented below
LoopOption:
	mov		edx, OFFSET aesthetic_line
	call	WriteString
	call	CrLf
	mov		edx, OFFSET prompt_EC1
	call	WriteString
	call	ReadInt
	mov		EC1_input, eax
	cmp		eax, 1
	je		start
	jne		Goodbye
	call	CrLf

; 5. Display a terminating message. 
Goodbye: 
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
