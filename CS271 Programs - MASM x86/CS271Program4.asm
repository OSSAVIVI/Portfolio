TITLE Programming Assignment #4     (Program4.asm)

; Author: Ryan Wells Farran
; Last Modified: 05/12/2019 | Sunday, May 12th 2019
; OSU email address: farranr@oregonstate.edu | Phone number: 480-734-6450
; Course number/section: CS 271 400 S2019 (COMPUTER ARCH. & ASSEM. LANGUAGE) 
; Project Number: Programming Assignment #4   Due Date: Sunday, 05/12/2019
; Description: 

INCLUDE Irvine32.inc

.data
aesthetic_line	BYTE	"**********************************************", 0
name_title		BYTE	"CS271 400 S2019 Program 4 by Ryan Wells Farran", 0

instructions_1	BYTE	"Please enter a number from [1, 400] (inclusive)", 0
instructions_2	BYTE	"to see the composite numbers from 1 to that number!", 0
instructions_3	BYTE	"~~~~~~~~~Aright, let's get started!!~~~~~~~~~~", 0

prompt_1		BYTE	"What's your name?", 0
userName		BYTE	30 DUP(0) ; used to store and also set size of user name, could be larger
count			DWORD	0


greeting_1		BYTE	"Hello there, ", 0
greeting_2		BYTE	", I thank you for your time!", 0

prompt_2		BYTE	". Enter a number: ", 0


count_1	BYTE	"Okay, we'll observe  "	, 0
count_2	BYTE	" composite numbers numbers."	, 0
spaces	BYTE	"   ", 0

too_small		BYTE	"INVALID INPUT! Number less than 1!"	, 0
too_big			BYTE	"INVALID INPUT! Number greater than 400!", 0
tryagain		BYTE	"Try again!"	, 0

UPPERLIMIT = 400
LOWERLIMIT = 1

;this message tells why the input is invalid
tooSmallError	BYTE	"The number you entered is less than -100!", 0

number			DWORD	?	;will store how many numbers to display
compositeNumber	DWORD 4
compBool		DWORD ?
totalComposites	DWORD 0
tempDivisor		DWORD ?

;same farewell from last assignment!
goodByeMessage_1	BYTE	"Thanks, ", 0
goodByeMessage_2	BYTE	", have a wonderful day! :-)", 0

; Set text color to green on a blue background! used in setColors function
textColor		DWORD	10 ; green
backGColor		DWORD	25 ; blue

;begin main program...
.code
main PROC

	call setColors
	call introduction
	call getUserName
	call instructions
	call getUserData
	call showComposites
	call farewell

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
	popad
	ret
introduction ENDP

;----------------------------------------------------------
; - Function Name: getUserName
; - Description:
;
;----------------------------------------------------------
getUserName PROC
	pushad
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
	popad
	ret
getUserName ENDP

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
; - Function Name: getUserData (calls validate)
; - Description:
;
;----------------------------------------------------------
getUserData PROC
	pushad
	mov		edx, OFFSET instructions_1 ; get the user's input and stores it in "number" variable
	call	WriteString
	call	CrLf
	call	validate
	mov		edx, OFFSET aesthetic_line	; code for displaying asterisks
	call	WriteString
	call	CrLf
	popad
	ret
getUserData ENDP

;----------------------------------------------------------
; - Function Name: validate (is called by getUserData)
; - Description:
;
;----------------------------------------------------------
validate PROC
	pushad
getNumber:
	call	ReadInt
	mov		number, eax
	cmp		eax, LOWERLIMIT		; test if input is less than bounds
	jl		TooSmall
	cmp		eax, UPPERLIMIT		; test if input is greater than bounds
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
; - Function Name: showComposites (calls isComposite)
; - Description:
;
;----------------------------------------------------------
showComposites PROC
	pushad
	mov	ecx, count	; initializes the loop counter with the number entered and validated by the user
printLoop:
	mov		compBool, 0		; assumes false at first
	call	isComposite		; determine if the first number is composite or prime
	cmp		compBool, 1	; see if the composite number flag was set
	je		printComposite
	inc		compositeNumber
printComposite:
	inc		totalComposites ; keeps track of how many printed so far
	mov		eax, 0	; clear EAX before moving first composite into it
	mov		eax, compositeNumber
	call	WriteDec ; prints composite
	mov		edx, 00000000h
	mov		edx, OFFSET spaces
	call	WriteString		; prints the three spaces in between each compsoite number
	inc		compositeNumber
	mov		tempDivisor, ebx
	mov		edx, 00000000h
	mov		eax, totalComposites
	mov		ebx, 10
	div		ebx			; divides the total number by 10 to see if we have to start a new line or keep printing on same one
	mov		ebx, tempDivisor		; restores divisor
	cmp		edx, 0
	jne		keepCurrentLine
	call	CrLf		; print a new line if edx is equal to 0
keepCurrentLine:
	loop	printLoop   ; decrements ecx loop counter
	popad ; restores registers pushed to stack at start of procedure
	ret ; returns control to main procedure
showComposites ENDP

;----------------------------------------------------------
; - Function Name: isComposite (is called by showComposites)
; - Description:
;
;----------------------------------------------------------
isComposite PROC
	mov		edx, 00000000h		; clear EDX reg
	mov		eax, compositeNumber
	mov		ebx, 2				; sets divisor to 2 at first
	div		ebx					; divide and remainder is sent to edx
	cmp		edx, 0				; if edx (remiander) is equa to zero than it is a composite number (not prime)
	je		setCompositeIsTrue
	inc		ebx					; ebx now equals 3 arter incrementing
divIncLoop:
	mov		edx, 00000000h
	mov		eax, 00000000h
	cmp		ebx, compositeNumber
	je		setCompositeIsFalse
	mov		eax, compositeNumber
	div		ebx
	cmp		edx, 0
	je		setCompositeIsTrue
	add		ebx, 2
	jmp		divIncLoop
setCompositeIsTrue:
	mov		compBool, 1			; sets equal to true using 1
	jmp		endIsComp
setCompositeIsFalse:
	mov		compBool, 0			; sets equal to false using 0
endIsComp:
	ret
isComposite ENDP

;----------------------------------------------------------
; - Function Name: farewell
; - Description:
;
;----------------------------------------------------------
farewell PROC
	pushad
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
	popad
	ret
farewell ENDP

END main