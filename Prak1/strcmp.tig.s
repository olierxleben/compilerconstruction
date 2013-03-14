
	.globl	t_main
	.ent	t_main
	t_main_framesize=44
	.frame	$sp,t_main_framesize,$31
t_main:	   
	addiu	$sp,$sp,-44
L23:
	sw	$2,0+t_main_framesize($sp)
	or	$25,$0,$31
	sw	$25,-8+t_main_framesize($sp)
	or	$16,$0,$16
	or	$17,$0,$17
	or	$18,$0,$18
	or	$19,$0,$19
	or	$20,$0,$20
	or	$21,$0,$21
	or	$22,$0,$22
	or	$23,$0,$23
	or	$30,$0,$30
	sw	$30,-12+t_main_framesize($sp)
	sw	$0,-4+t_main_framesize($sp)
	lw	$30,0+t_main_framesize($sp)
	or	$30,$0,$30
	addiu	$25,$sp,0+t_main_framesize
	or	$2,$0,$25
	la	$25,L21
	or	$4,$0,$25
	jal	getString
	or	$25,$0,$2
	or	$2,$0,$30
	or	$4,$0,$25
	jal	print
	addiu	$30,$sp,0+t_main_framesize
	or	$30,$0,$30
	addiu	$25,$sp,0+t_main_framesize
	or	$2,$0,$25
	jal	getStringArray
	or	$25,$0,$2
	or	$2,$0,$30
	or	$4,$0,$25
	jal	printStringArray
	or	$2,$0,$2
	lw	$30,-8+t_main_framesize($sp)
	or	$30,$0,$30
	or	$31,$0,$30
	or	$16,$0,$16
	or	$17,$0,$17
	or	$18,$0,$18
	or	$19,$0,$19
	or	$20,$0,$20
	or	$21,$0,$21
	or	$22,$0,$22
	or	$23,$0,$23
	lw	$30,-12+t_main_framesize($sp)
	or	$30,$0,$30
	or	$30,$0,$30
	b	L22
L22:

	addiu	$sp,$sp,t_main_framesize
	j	$31
	.end	t_main
	.data
L21:	.word	21
	.ascii	"Bitte Text eingeben:\n"
	.align	2
	.text


	.globl	printStringArray
	.ent	printStringArray
	printStringArray_framesize=52
	.frame	$sp,printStringArray_framesize,$31
printStringArray:	   
	addiu	$sp,$sp,-52
L25:
	sw	$2,0+printStringArray_framesize($sp)
	or	$25,$0,$4
	sw	$25,-16+printStringArray_framesize($sp)
	or	$25,$0,$31
	sw	$25,-20+printStringArray_framesize($sp)
	or	$16,$0,$16
	or	$17,$0,$17
	or	$18,$0,$18
	or	$19,$0,$19
	or	$20,$0,$20
	or	$21,$0,$21
	or	$22,$0,$22
	or	$23,$0,$23
	or	$30,$0,$30
	sw	$0,-4+printStringArray_framesize($sp)
	sw	$0,-8+printStringArray_framesize($sp)
	lw	$25,0+printStringArray_framesize($sp)
	lw	$25,-4($25)
	addi	$25,$25,-1
	sw	$25,-12+printStringArray_framesize($sp)
L17:
	lw	$24,-12+printStringArray_framesize($sp)
	lw	$25,-8+printStringArray_framesize($sp)
	slt	$25,$24,$25
	beq	$25,$0,L18
L19:
L20:
L15:
	or	$2,$0,$0
	lw	$25,-20+printStringArray_framesize($sp)
	or	$25,$0,$25
	or	$31,$0,$25
	or	$16,$0,$16
	or	$17,$0,$17
	or	$18,$0,$18
	or	$19,$0,$19
	or	$20,$0,$20
	or	$21,$0,$21
	or	$22,$0,$22
	or	$23,$0,$23
	or	$30,$0,$30
	b	L24
L16:
	lw	$25,0+printStringArray_framesize($sp)
	lw	$25,0($25)
	or	$2,$0,$25
	addi	$24,$0,4
	lw	$25,-8+printStringArray_framesize($sp)
	mult	$25,$24
	mflo	$24
	lw	$25,-16+printStringArray_framesize($sp)
	or	$25,$0,$25
	add	$25,$25,$24
	lw	$25,0($25)
	or	$4,$0,$25
	jal	print
	lw	$25,-8+printStringArray_framesize($sp)
	addi	$25,$25,1
	sw	$25,-8+printStringArray_framesize($sp)
	b	L17
L18:
	b	L16
L26:
	b	L20
L24:

	addiu	$sp,$sp,printStringArray_framesize
	j	$31
	.end	printStringArray

	.globl	getStringArray
	.ent	getStringArray
	getStringArray_framesize=44
	.frame	$sp,getStringArray_framesize,$31
getStringArray:	   
	addiu	$sp,$sp,-44
L28:
	sw	$2,0+getStringArray_framesize($sp)
	or	$25,$0,$31
	sw	$25,-4+getStringArray_framesize($sp)
	or	$16,$0,$16
	or	$17,$0,$17
	or	$18,$0,$18
	or	$19,$0,$19
	or	$20,$0,$20
	or	$21,$0,$21
	or	$22,$0,$22
	or	$23,$0,$23
	sw	$23,-12+getStringArray_framesize($sp)
	or	$30,$0,$30
	sw	$30,-8+getStringArray_framesize($sp)
	lw	$30,0+getStringArray_framesize($sp)
	addi	$30,$30,-4
	or	$23,$0,$30
	lw	$30,0+getStringArray_framesize($sp)
	lw	$30,0($30)
	or	$30,$0,$30
	lw	$25,0+getStringArray_framesize($sp)
	or	$2,$0,$25
	la	$25,L14
	or	$4,$0,$25
	jal	getString
	or	$25,$0,$2
	or	$2,$0,$30
	or	$4,$0,$25
	jal	ord
	or	$30,$0,$2
	or	$30,$0,$30
	lw	$25,0+getStringArray_framesize($sp)
	lw	$25,0($25)
	or	$2,$0,$25
	la	$25,L13
	or	$4,$0,$25
	jal	ord
	or	$25,$0,$2
	sub	$30,$30,$25
	sw	$30,0($23)
	lw	$30,0+getStringArray_framesize($sp)
	or	$2,$0,$30
	jal	getStrings
	or	$2,$0,$2
	lw	$30,-4+getStringArray_framesize($sp)
	or	$30,$0,$30
	or	$31,$0,$30
	or	$16,$0,$16
	or	$17,$0,$17
	or	$18,$0,$18
	or	$19,$0,$19
	or	$20,$0,$20
	or	$21,$0,$21
	or	$22,$0,$22
	lw	$30,-12+getStringArray_framesize($sp)
	or	$30,$0,$30
	or	$23,$0,$30
	lw	$30,-8+getStringArray_framesize($sp)
	or	$30,$0,$30
	or	$30,$0,$30
	b	L27
L27:

	addiu	$sp,$sp,getStringArray_framesize
	j	$31
	.end	getStringArray
	.data
L14:	.word	35
	.ascii	"Bitte Anzahl der Strings eingeben:\n"
	.align	2
	.text

	.data
L13:	.word	1
	.ascii	"0"
	.align	2
	.text


	.globl	getStrings
	.ent	getStrings
	getStrings_framesize=56
	.frame	$sp,getStrings_framesize,$31
getStrings:	   
	addiu	$sp,$sp,-56
L30:
	sw	$2,0+getStrings_framesize($sp)
	or	$25,$0,$31
	sw	$25,-20+getStrings_framesize($sp)
	or	$16,$0,$16
	or	$17,$0,$17
	or	$18,$0,$18
	or	$19,$0,$19
	or	$20,$0,$20
	or	$21,$0,$21
	or	$22,$0,$22
	or	$23,$0,$23
	or	$30,$0,$30
	sw	$30,-24+getStrings_framesize($sp)
	addiu	$30,$sp,0+getStrings_framesize
	addi	$30,$30,-4
	or	$30,$0,$30
	or	$2,$0,$0
	lw	$25,0+getStrings_framesize($sp)
	lw	$25,-4($25)
	or	$4,$0,$25
	la	$25,L5
	or	$5,$0,$25
	jal	initArray
	or	$25,$0,$2
	sw	$25,0($30)
	sw	$0,-8+getStrings_framesize($sp)
	sw	$0,-12+getStrings_framesize($sp)
	lw	$30,0+getStrings_framesize($sp)
	lw	$30,-4($30)
	addi	$30,$30,-1
	sw	$30,-16+getStrings_framesize($sp)
L9:
	lw	$25,-16+getStrings_framesize($sp)
	lw	$30,-12+getStrings_framesize($sp)
	slt	$30,$25,$30
	beq	$30,$0,L10
L11:
L12:
L6:
	lw	$30,-4+getStrings_framesize($sp)
	or	$2,$0,$30
	lw	$30,-20+getStrings_framesize($sp)
	or	$30,$0,$30
	or	$31,$0,$30
	or	$16,$0,$16
	or	$17,$0,$17
	or	$18,$0,$18
	or	$19,$0,$19
	or	$20,$0,$20
	or	$21,$0,$21
	or	$22,$0,$22
	or	$23,$0,$23
	lw	$30,-24+getStrings_framesize($sp)
	or	$30,$0,$30
	or	$30,$0,$30
	b	L29
L8:
	addi	$25,$0,4
	lw	$30,-12+getStrings_framesize($sp)
	mult	$30,$25
	mflo	$25
	lw	$30,-4+getStrings_framesize($sp)
	add	$30,$30,$25
	or	$30,$0,$30
	lw	$25,0+getStrings_framesize($sp)
	or	$2,$0,$25
	la	$25,L7
	or	$4,$0,$25
	jal	getString
	or	$25,$0,$2
	sw	$25,0($30)
	lw	$30,-12+getStrings_framesize($sp)
	addi	$30,$30,1
	sw	$30,-12+getStrings_framesize($sp)
	b	L9
L10:
	b	L8
L31:
	b	L12
L29:

	addiu	$sp,$sp,getStrings_framesize
	j	$31
	.end	getStrings
	.data
L7:	.word	17
	.ascii	"String eingeben: "
	.align	2
	.text

	.data
L5:	.word	0
	.ascii	""
	.align	2
	.text


	.globl	getString
	.ent	getString
	getString_framesize=36
	.frame	$sp,getString_framesize,$31
getString:	   
	addiu	$sp,$sp,-36
L33:
	sw	$2,0+getString_framesize($sp)
	or	$25,$0,$4
	or	$24,$0,$31
	sw	$24,-4+getString_framesize($sp)
	or	$16,$0,$16
	or	$17,$0,$17
	or	$18,$0,$18
	or	$19,$0,$19
	or	$20,$0,$20
	or	$21,$0,$21
	or	$22,$0,$22
	or	$23,$0,$23
	or	$30,$0,$30
	lw	$24,0+getString_framesize($sp)
	lw	$24,0($24)
	or	$2,$0,$24
	or	$4,$0,$25
	jal	print
	lw	$25,0+getString_framesize($sp)
	or	$2,$0,$25
	jal	getString2
	or	$2,$0,$2
	lw	$25,-4+getString_framesize($sp)
	or	$25,$0,$25
	or	$31,$0,$25
	or	$16,$0,$16
	or	$17,$0,$17
	or	$18,$0,$18
	or	$19,$0,$19
	or	$20,$0,$20
	or	$21,$0,$21
	or	$22,$0,$22
	or	$23,$0,$23
	or	$30,$0,$30
	b	L32
L32:

	addiu	$sp,$sp,getString_framesize
	j	$31
	.end	getString

	.globl	getString2
	.ent	getString2
	getString2_framesize=48
	.frame	$sp,getString2_framesize,$31
getString2:	   
	addiu	$sp,$sp,-48
L35:
	sw	$2,0+getString2_framesize($sp)
	or	$25,$0,$31
	sw	$25,-8+getString2_framesize($sp)
	or	$16,$0,$16
	or	$17,$0,$17
	or	$18,$0,$18
	or	$19,$0,$19
	or	$20,$0,$20
	or	$21,$0,$21
	or	$22,$0,$22
	or	$23,$0,$23
	sw	$23,-16+getString2_framesize($sp)
	or	$30,$0,$30
	sw	$30,-12+getString2_framesize($sp)
	addiu	$30,$sp,0+getString2_framesize
	addi	$30,$30,-4
	or	$23,$0,$30
	lw	$30,0+getString2_framesize($sp)
	lw	$30,0($30)
	or	$2,$0,$30
	jal	getchar
	or	$30,$0,$2
	sw	$30,0($23)
	or	$2,$0,$0
	lw	$30,-4+getString2_framesize($sp)
	or	$4,$0,$30
	la	$30,L0
	or	$5,$0,$30
	jal	stringEqual
	or	$30,$0,$2
	bne	$30,$0,L2
L3:
	lw	$30,0+getString2_framesize($sp)
	lw	$30,0($30)
	or	$30,$0,$30
	lw	$23,-4+getString2_framesize($sp)
	or	$23,$0,$23
	lw	$25,0+getString2_framesize($sp)
	or	$2,$0,$25
	jal	getString2
	or	$25,$0,$2
	or	$2,$0,$30
	or	$4,$0,$23
	or	$5,$0,$25
	jal	concat
	or	$30,$0,$2
L4:
	or	$2,$0,$30
	lw	$30,-8+getString2_framesize($sp)
	or	$30,$0,$30
	or	$31,$0,$30
	or	$16,$0,$16
	or	$17,$0,$17
	or	$18,$0,$18
	or	$19,$0,$19
	or	$20,$0,$20
	or	$21,$0,$21
	or	$22,$0,$22
	lw	$30,-16+getString2_framesize($sp)
	or	$30,$0,$30
	or	$23,$0,$30
	lw	$30,-12+getString2_framesize($sp)
	or	$30,$0,$30
	or	$30,$0,$30
	b	L34
L2:
	la	$30,L1
	or	$30,$0,$30
	b	L4
L34:

	addiu	$sp,$sp,getString2_framesize
	j	$31
	.end	getString2
	.data
L1:	.word	0
	.ascii	""
	.align	2
	.text

	.data
L0:	.word	1
	.ascii	"\n"
	.align	2
	.text

