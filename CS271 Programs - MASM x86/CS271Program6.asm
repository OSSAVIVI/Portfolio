TITLE Programming Assignment #6b     (Program4.asm)

; Author: Ryan Wells Farran
; Last Modified: 06/07/2019 | Friday, June 7th 2019
; OSU email address: farranr@oregonstate.edu | Phone number: 480-734-6450
; Course number/section: CS 271 400 S2019 (COMPUTER ARCH. & ASSEM. LANGUAGE) 
; Project Number: Programming Assignment #6b   Due Date: Sunday, 06/09/2019
; Description: 

INCLUDE Irvine32.inc

; code for MACRO
displayString	MACRO	stringToDisplay
push	edx
mov		edx, OFFSET stringToDisplay
call	WriteString
pop		edx
ENDM

.data
textColor		DWORD	15 ; white text
backGColor		DWORD	29 ; purple background

aesthetic_line	BYTE	"***************************************************", 0
name_title		BYTE	"* CS271 400 S2019 Program 6b by Ryan Wells Farran *", 0
name_title_2	BYTE	"**************Combinations Calculator**************", 0
name_title_3	BYTE	"******EC: Problems numbered and score is kept******", 0
name_title_4	BYTE	"**EC: DESCRIPTION", 0


instructions_1	BYTE	"I’ll give you a combinations problem.", 0
instructions_2	BYTE	"You enter your answer, and I’ll let", 0
instructions_3	BYTE	"you know if you’re right!", 0

question_1		BYTE	"Problem #", 0
question_2		BYTE	"Number of elements in the set: ", 0
question_3		BYTE	"Number of elements to choose from the set: ", 0

prompt_1		BYTE	"How many ways can you choose? "
prompt_2_error	BYTE	"Enter ONLY integers!"

answer_1		BYTE	"There are ", 0
answer_2		BYTE	" combinations of ", 0
answer_3		BYTE	" items from a set of ", 0
answer_4		BYTE	".", 0
answer_5		BYTE	"Your answer was: ", 0
answer_6		BYTE	"Total correct answers: ", 0
answer_7		BYTE	"Total incorrect answers: ", 0

answer_good		BYTE	"You are correct! ", 0
answer_bad		BYTE	"Not quite..looks like you need more practice! ", 0

RMIN = 1
MAXINPUT = 10
NMIN = 3
NMAX = 12

farewell		BYTE	"Thanks for playing! Have a great day! :)", 0

restart_1		BYTE	"Another problem? (y/n): ", 0
restart_2_error	BYTE	"INVALID INPUT! Enter ONLY 'y' or 'n'!"

probNum			DWORD	1
totalCorrect	DWORD	0
totalIncorrect	DWORD	0
rVariable		DWORD	?
nVariable		DWORD	?

userInput		BYTE	10 DUP(0)
userAnswer		DWORD	?
result			DWORD	?

;begin main program...
.code
main PROC
	call	Randomize		; call this functin only once to create a seed for random numbers to be generated in EAX
	call	setColors		; sets the colors of the background and text
	call	introduction	; introduces the programmer, program, and class name
	call	instructions	; describes the purpose of the program

nextGame:
	push	OFFSET	probNum
	push	OFFSET	rVariable
	push	OFFSET	nVariable
	call	showProblem

	push	OFFSET	userAnswer
	push	OFFSET	userInput
	call	getData

	push	rVariable
	push	nVariable
	push	OFFSET	result
	call	combinations

	push	OFFSET	totalCorrect
	push	OFFSET	totalIncorrect
	push	rVariable
	push	nVariable
	push	result
	push	userAnswer
	call	displayResult

	jmp		skipError

errorMessage:
	displayString restart_2_error

skipError:
	inc		probNum
	call	CrLf

	displayString restart_1

	mov		ecx, SIZEOF userInput
	mov		edx, OFFSET userInput

	call	readString
	cmp		eax, 1
	jg		errorMessage
	mov		ecx, eax
	mov		esi, OFFSET userInput

	cld
	call	CrLf

	lodsb
	cmp		al, 78
	je		stopProgram
	cmp		al, 110
	je		stopProgram

	cmp		al, 89
	je		nextGame
	cmp		al, 121
	je		nextGame

	jmp		errorMessage

stopProgram:
	displayString answer_6
	mov		eax, totalCorrect
	call	WriteDec
	call	CrLf

	displayString answer_7
	mov		eax, totalIncorrect
	call	WriteDec
	call	CrLf

	displayString farewell
	call	CrLf

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
; - Description: Displays the program and author name
;
;----------------------------------------------------------
introduction PROC
	pushad
	displayString aesthetic_line
	call	CrLf
	displayString name_title
	call	CrLf
	displayString name_title_2
	call	CrLf
	displayString name_title_3
	call	CrLf
	displayString aesthetic_line
	call	CrLf
	call	CrLf
	popad
	ret
introduction ENDP

;----------------------------------------------------------
; - Function Name: instructions
; - Description: Displays the instructions to the user, which
; just explains the program's purpose and how to proceed.
;----------------------------------------------------------
instructions PROC
	pushad
	displayString instructions_1
	call	CrLf
	displayString instructions_2
	call	CrLf
	displayString instructions_3
	call	CrLf
	call	CrLf
	displayString aesthetic_line
	call	CrLf
	call	CrLf
	popad
	ret
instructions ENDP

;----------------------------------------------------------
; - Function Name: showProblem
; - Description: generates random numbers and displays the 
; specific sample problem 
;----------------------------------------------------------
showProblem PROC
	push	ebp
	mov		ebp, esp
	mov		edx, [ebp + 16]
	mov		ecx, [ebp + 12]
	mov		ebx, [ebp + 8]

; generate n
	mov		eax, NMAX
	sub		eax, NMIN
	inc		eax
	call	RandomRange
	add		eax, NMIN
	mov		[ebx], eax

; generate r
	mov		eax, [ebx]
	sub		eax, RMIN
	inc		eax
	call	RandomRange
	add		eax, RMIN
	mov		[ecx], eax

; begin code to display numbers and probelm to user
	displayString question_1
	mov		eax, [edx]
	call	WriteDec
	call	CrLf

	displayString question_2
	mov		eax, [ebx]
	call	WriteDec
	call	CrLf

	displayString question_3
	mov		eax, [ecx]
	call	WriteDec
	call	CrLf
	call	CrLf

	pop		ebp
	ret
showProblem ENDP

;----------------------------------------------------------
; - Function Name: getData
; - Description:
;
;----------------------------------------------------------
getData PROC
	push	ebp
	mov		ebp, esp
	jmp		getInput

invalid:
	displayString prompt_2_error
	call	CrLf

getInput:
	displayString prompt_1
	mov		edx, [ebp + 8]
	mov		ecx, MAXINPUT
	call	ReadString

	mov		ecx, eax
	mov		esi, [ebp + 8]
	cld

	mov		edx, 0

check:
	lodsb
	cmp		al, 57
	ja		invalid
	cmp		al, 48
	jb		invalid
	movzx	eax, al
	push	ecx
	mov		ecx, eax
	mov		ebx, 10
	mov		eax, edx
	mul		ebx
	mov		edx, eax
	sub		ecx, 48
	add		edx, ecx
	pop		ecx
	loop	check

	mov		ebx, [ebp + 12]
	mov		[ebx], edx

	pop		ebp
	ret		8
getData ENDP

;----------------------------------------------------------
; - Function Name: combinations
; - Description:
;
;----------------------------------------------------------
combinations PROC
	push	ebp
	mov		ebp, esp
	mov		ebx, [ebp + 16]
	mov		eax, [ebp + 12]

	cmp		eax, ebx

	je		equivelant

; calculate r!
	mov		ebx, [ebp + 16]
	push	ebx
	call	factorial

	mov		ecx, eax

; calculate (n - r)!
	mov		eax, [ebp + 12]
	sub		eax, [ebp + 16]
	mov		ebx, eax

	push	ebx
	call	factorial

	mul		ecx
	mov		ecx, eax

	mov		ebx, [ebp + 12]
	push	ebx
	call	factorial

	mov		edx, 0
	div		ecx

	mov		ecx, [ebp + 8]
	mov		[ecx], eax

	jmp		completed

equivelant:
	mov		ecx, [ebp + 8]
	mov		ebx, 1
	mov		[ecx], ebx

completed:
	pop		ebp
	ret		12

combinations ENDP

;----------------------------------------------------------
; - Function Name: factorial
; - Description:
;
;----------------------------------------------------------
factorial PROC
	push	ebp
	mov		ebp, esp
	mov		eax, [ebp + 8]
	cmp		eax, 1
	jle		completed

; recursive part of function
	dec		eax
	push	eax
	call	factorial

	mov		esi, [ebp + 8]
	mul		esi

completed:
	pop		ebp
	ret		4
factorial ENDP

;----------------------------------------------------------
; - Function Name: displayResult
; - Description:
;
;----------------------------------------------------------
displayResult PROC
	push	ebp
	mov		ebp, esp

	mov		ebx, [ebp + 20]
	mov		ecx, [ebp + 16]
	mov		esi, [ebp + 12]
	mov		edx, [ebp + 8]

	call	CrLf

	displayString answer_1
	mov		eax, esi
	call	WriteDec

	displayString answer_2
	mov		eax, ebx
	call	WriteDec

	displayString answer_3
	mov		eax, ecx
	call	WriteDec

	displayString answer_4
	call	CrLf

	displayString answer_5
	mov		eax, edx
	call	WriteDec
	call	CrLf

	cmp		edx, esi
	je		correctAnswer

	displayString answer_bad
	call	CrLf

	mov		ebx, [ebp + 24]
	mov		eax, [ebx]
	inc		eax

	mov		[ebx], eax

	jmp		completed

correctAnswer:
	displayString answer_good
	call	CrLf

	mov		ebx, [ebp + 28]
	mov		eax, [ebx]
	inc		eax
	mov		[ebx], eax

completed:
	pop		ebp
	ret		24
displayResult ENDP

END main