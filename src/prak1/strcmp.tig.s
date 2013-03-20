
	.globl	t_main
	.ent	t_main
	t_main_framesize=44
	.frame	$sp,t_main_framesize,$31
t_main:	   
	addiu	$sp,$sp,-44
L70:
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
	addiu	$30,$sp,0+t_main_framesize
	or	$30,$0,$30
	addiu	$25,$sp,0+t_main_framesize
	or	$2,$0,$25
	jal	getStringArray
	or	$25,$0,$2
	or	$2,$0,$30
	or	$4,$0,$25
	jal	sortStringArray
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
	b	L69
L69:

	addiu	$sp,$sp,t_main_framesize
	j	$31
	.end	t_main

	.globl	sortStringArray
	.ent	sortStringArray
	sortStringArray_framesize=64
	.frame	$sp,sortStringArray_framesize,$31
sortStringArray:	   
	addiu	$sp,$sp,-64
L72:
	sw	$2,0+sortStringArray_framesize($sp)
	or	$25,$0,$4
	sw	$25,-28+sortStringArray_framesize($sp)
	or	$25,$0,$31
	sw	$25,-32+sortStringArray_framesize($sp)
	or	$16,$0,$16
	or	$17,$0,$17
	or	$18,$0,$18
	or	$19,$0,$19
	or	$20,$0,$20
	or	$21,$0,$21
	or	$22,$0,$22
	or	$23,$0,$23
	or	$30,$0,$30
	sw	$0,-4+sortStringArray_framesize($sp)
	lw	$25,0+sortStringArray_framesize($sp)
	lw	$25,-4($25)
	sw	$25,-8+sortStringArray_framesize($sp)
	la	$25,L51
	sw	$25,-12+sortStringArray_framesize($sp)
	sw	$0,-16+sortStringArray_framesize($sp)
	lw	$25,0+sortStringArray_framesize($sp)
	lw	$25,0($25)
	or	$2,$0,$25
	la	$25,L52
	or	$4,$0,$25
	jal	print
	lw	$25,0+sortStringArray_framesize($sp)
	or	$2,$0,$25
	lw	$25,-28+sortStringArray_framesize($sp)
	or	$25,$0,$25
	or	$4,$0,$25
	jal	printStringArray
L64:
	lw	$25,-16+sortStringArray_framesize($sp)
	beq	$25,$0,L65
L66:
L67:
L53:
	lw	$25,0+sortStringArray_framesize($sp)
	lw	$25,0($25)
	or	$2,$0,$25
	la	$25,L68
	or	$4,$0,$25
	jal	print
	lw	$25,0+sortStringArray_framesize($sp)
	or	$2,$0,$25
	lw	$25,-28+sortStringArray_framesize($sp)
	or	$25,$0,$25
	or	$4,$0,$25
	jal	printStringArray
	or	$2,$0,$2
	lw	$25,-32+sortStringArray_framesize($sp)
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
	b	L71
L63:
	addi	$25,$0,1
	sw	$25,-16+sortStringArray_framesize($sp)
	sw	$0,-20+sortStringArray_framesize($sp)
	lw	$25,-8+sortStringArray_framesize($sp)
	addi	$25,$25,-2
	sw	$25,-24+sortStringArray_framesize($sp)
L59:
	lw	$24,-24+sortStringArray_framesize($sp)
	lw	$25,-20+sortStringArray_framesize($sp)
	slt	$25,$24,$25
	beq	$25,$0,L60
L61:
L62:
L54:
	lw	$25,-8+sortStringArray_framesize($sp)
	addi	$25,$25,-1
	sw	$25,-8+sortStringArray_framesize($sp)
	b	L64
L58:
	lw	$25,0+sortStringArray_framesize($sp)
	or	$2,$0,$25
	addi	$24,$0,4
	lw	$25,-20+sortStringArray_framesize($sp)
	mult	$25,$24
	mflo	$24
	lw	$25,-28+sortStringArray_framesize($sp)
	or	$25,$0,$25
	add	$25,$25,$24
	lw	$25,0($25)
	or	$4,$0,$25
	addi	$24,$0,4
	lw	$25,-20+sortStringArray_framesize($sp)
	addi	$25,$25,1
	mult	$25,$24
	mflo	$24
	lw	$25,-28+sortStringArray_framesize($sp)
	or	$25,$0,$25
	add	$25,$25,$24
	lw	$25,0($25)
	or	$5,$0,$25
	jal	strcmp
	or	$25,$0,$2
	addi	$24,$0,1
	beq	$25,$24,L55
L56:
L57:
	lw	$25,-20+sortStringArray_framesize($sp)
	addi	$25,$25,1
	sw	$25,-20+sortStringArray_framesize($sp)
	b	L59
L55:
	addi	$24,$0,4
	lw	$25,-20+sortStringArray_framesize($sp)
	mult	$25,$24
	mflo	$24
	lw	$25,-28+sortStringArray_framesize($sp)
	or	$25,$0,$25
	add	$25,$25,$24
	lw	$25,0($25)
	sw	$25,-12+sortStringArray_framesize($sp)
	addi	$24,$0,4
	lw	$25,-20+sortStringArray_framesize($sp)
	addi	$25,$25,1
	mult	$25,$24
	mflo	$24
	lw	$25,-28+sortStringArray_framesize($sp)
	or	$25,$0,$25
	add	$25,$25,$24
	lw	$24,0($25)
	addi	$15,$0,4
	lw	$25,-20+sortStringArray_framesize($sp)
	mult	$25,$15
	mflo	$15
	lw	$25,-28+sortStringArray_framesize($sp)
	or	$25,$0,$25
	add	$25,$25,$15
	sw	$24,0($25)
	lw	$24,-12+sortStringArray_framesize($sp)
	addi	$15,$0,4
	lw	$25,-20+sortStringArray_framesize($sp)
	addi	$25,$25,1
	mult	$25,$15
	mflo	$15
	lw	$25,-28+sortStringArray_framesize($sp)
	or	$25,$0,$25
	add	$25,$25,$15
	sw	$24,0($25)
	sw	$0,-16+sortStringArray_framesize($sp)
	b	L57
L60:
	b	L58
L73:
	b	L62
L65:
	b	L63
L74:
	b	L67
L71:

	addiu	$sp,$sp,sortStringArray_framesize
	j	$31
	.end	sortStringArray
	.data
L68:	.word	11
	.ascii	"\nsortiert:\n"
	.align	2
	.text

	.data
L52:	.word	13
	.ascii	"unsoertiert:\n"
	.align	2
	.text

	.data
L51:	.word	0
	.ascii	""
	.align	2
	.text


	.globl	strcmp
	.ent	strcmp
	strcmp_framesize=76
	.frame	$sp,strcmp_framesize,$31
strcmp:	   
	addiu	$sp,$sp,-76
L76:
	sw	$2,0+strcmp_framesize($sp)
	or	$25,$0,$4
	sw	$25,-36+strcmp_framesize($sp)
	or	$25,$0,$5
	sw	$25,-32+strcmp_framesize($sp)
	or	$25,$0,$31
	sw	$25,-40+strcmp_framesize($sp)
	or	$16,$0,$16
	or	$17,$0,$17
	or	$18,$0,$18
	or	$19,$0,$19
	or	$20,$0,$20
	or	$21,$0,$21
	or	$22,$0,$22
	or	$23,$0,$23
	or	$30,$0,$30
	sw	$30,-44+strcmp_framesize($sp)
	sw	$0,-4+strcmp_framesize($sp)
	sw	$0,-8+strcmp_framesize($sp)
	sw	$0,-12+strcmp_framesize($sp)
	la	$30,L22
	sw	$30,-16+strcmp_framesize($sp)
	la	$30,L23
	sw	$30,-20+strcmp_framesize($sp)
	lw	$30,0+strcmp_framesize($sp)
	lw	$30,0($30)
	or	$2,$0,$30
	lw	$30,-36+strcmp_framesize($sp)
	or	$30,$0,$30
	or	$4,$0,$30
	jal	size
	or	$30,$0,$2
	or	$30,$0,$30
	lw	$25,0+strcmp_framesize($sp)
	lw	$25,0($25)
	or	$2,$0,$25
	lw	$25,-32+strcmp_framesize($sp)
	or	$25,$0,$25
	or	$4,$0,$25
	jal	size
	or	$25,$0,$2
	slt	$30,$30,$25
	bne	$30,$0,L24
L25:
	addiu	$30,$sp,0+strcmp_framesize
	addi	$30,$30,-8
	or	$30,$0,$30
	lw	$25,0+strcmp_framesize($sp)
	lw	$25,0($25)
	or	$2,$0,$25
	lw	$25,-32+strcmp_framesize($sp)
	or	$25,$0,$25
	or	$4,$0,$25
	jal	size
	or	$25,$0,$2
	sw	$25,0($30)
L26:
	sw	$0,-24+strcmp_framesize($sp)
	lw	$30,-8+strcmp_framesize($sp)
	addi	$30,$30,-1
	sw	$30,-28+strcmp_framesize($sp)
L35:
	lw	$25,-28+strcmp_framesize($sp)
	lw	$30,-24+strcmp_framesize($sp)
	slt	$30,$25,$30
	beq	$30,$0,L36
L37:
L38:
L27:
	lw	$30,-4+strcmp_framesize($sp)
	beq	$30,$0,L39
L40:
L49:
	lw	$30,-4+strcmp_framesize($sp)
	beq	$30,$0,L42
L43:
L46:
L47:
L50:
	lw	$30,-4+strcmp_framesize($sp)
	or	$2,$0,$30
	lw	$30,-40+strcmp_framesize($sp)
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
	lw	$30,-44+strcmp_framesize($sp)
	or	$30,$0,$30
	or	$30,$0,$30
	b	L75
L24:
	addiu	$30,$sp,0+strcmp_framesize
	addi	$30,$30,-8
	or	$30,$0,$30
	lw	$25,0+strcmp_framesize($sp)
	lw	$25,0($25)
	or	$2,$0,$25
	lw	$25,-36+strcmp_framesize($sp)
	or	$25,$0,$25
	or	$4,$0,$25
	jal	size
	or	$25,$0,$2
	sw	$25,0($30)
	b	L26
L34:
	addiu	$30,$sp,0+strcmp_framesize
	addi	$30,$30,-16
	or	$30,$0,$30
	lw	$25,0+strcmp_framesize($sp)
	lw	$25,0($25)
	or	$2,$0,$25
	lw	$25,-36+strcmp_framesize($sp)
	or	$25,$0,$25
	or	$4,$0,$25
	lw	$25,-24+strcmp_framesize($sp)
	or	$5,$0,$25
	addi	$25,$0,1
	or	$6,$0,$25
	jal	substring
	or	$25,$0,$2
	sw	$25,0($30)
	addiu	$30,$sp,0+strcmp_framesize
	addi	$30,$30,-20
	or	$30,$0,$30
	lw	$25,0+strcmp_framesize($sp)
	lw	$25,0($25)
	or	$2,$0,$25
	lw	$25,-32+strcmp_framesize($sp)
	or	$25,$0,$25
	or	$4,$0,$25
	lw	$25,-24+strcmp_framesize($sp)
	or	$5,$0,$25
	addi	$25,$0,1
	or	$6,$0,$25
	jal	substring
	or	$25,$0,$2
	sw	$25,0($30)
	lw	$30,0+strcmp_framesize($sp)
	lw	$30,0($30)
	or	$2,$0,$30
	lw	$30,-16+strcmp_framesize($sp)
	or	$4,$0,$30
	jal	ord
	or	$30,$0,$2
	or	$30,$0,$30
	lw	$25,0+strcmp_framesize($sp)
	lw	$25,0($25)
	or	$2,$0,$25
	lw	$25,-20+strcmp_framesize($sp)
	or	$4,$0,$25
	jal	ord
	or	$25,$0,$2
	slt	$30,$25,$30
	bne	$30,$0,L31
L32:
	lw	$30,0+strcmp_framesize($sp)
	lw	$30,0($30)
	or	$2,$0,$30
	lw	$30,-16+strcmp_framesize($sp)
	or	$4,$0,$30
	jal	ord
	or	$30,$0,$2
	or	$30,$0,$30
	lw	$25,0+strcmp_framesize($sp)
	lw	$25,0($25)
	or	$2,$0,$25
	lw	$25,-20+strcmp_framesize($sp)
	or	$4,$0,$25
	jal	ord
	or	$25,$0,$2
	slt	$30,$30,$25
	bne	$30,$0,L28
L29:
L30:
L33:
	lw	$30,-24+strcmp_framesize($sp)
	addi	$30,$30,1
	sw	$30,-24+strcmp_framesize($sp)
	b	L35
L31:
	addi	$30,$0,1
	sw	$30,-4+strcmp_framesize($sp)
	b	L27
L77:
	b	L33
L28:
	addi	$30,$0,-1
	sw	$30,-4+strcmp_framesize($sp)
	b	L27
L78:
	b	L30
L36:
	b	L34
L79:
	b	L38
L39:
	lw	$30,0+strcmp_framesize($sp)
	lw	$30,0($30)
	or	$2,$0,$30
	lw	$30,-36+strcmp_framesize($sp)
	or	$30,$0,$30
	or	$4,$0,$30
	jal	size
	or	$30,$0,$2
	or	$30,$0,$30
	lw	$25,0+strcmp_framesize($sp)
	lw	$25,0($25)
	or	$2,$0,$25
	lw	$25,-32+strcmp_framesize($sp)
	or	$25,$0,$25
	or	$4,$0,$25
	jal	size
	or	$25,$0,$2
	slt	$30,$30,$25
	beq	$30,$0,L49
L48:
	addi	$30,$0,-1
	sw	$30,-4+strcmp_framesize($sp)
	b	L50
L80:
L41:
	b	L48
L42:
	lw	$30,0+strcmp_framesize($sp)
	lw	$30,0($30)
	or	$2,$0,$30
	lw	$30,-36+strcmp_framesize($sp)
	or	$30,$0,$30
	or	$4,$0,$30
	jal	size
	or	$30,$0,$2
	or	$30,$0,$30
	lw	$25,0+strcmp_framesize($sp)
	lw	$25,0($25)
	or	$2,$0,$25
	lw	$25,-32+strcmp_framesize($sp)
	or	$25,$0,$25
	or	$4,$0,$25
	jal	size
	or	$25,$0,$2
	slt	$30,$25,$30
	beq	$30,$0,L46
L45:
	addi	$30,$0,1
	sw	$30,-4+strcmp_framesize($sp)
	b	L47
L81:
L44:
	b	L45
L75:

	addiu	$sp,$sp,strcmp_framesize
	j	$31
	.end	strcmp
	.data
L23:	.word	0
	.ascii	""
	.align	2
	.text

	.data
L22:	.word	0
	.ascii	""
	.align	2
	.text


	.globl	printStringArray
	.ent	printStringArray
	printStringArray_framesize=56
	.frame	$sp,printStringArray_framesize,$31
printStringArray:	   
	addiu	$sp,$sp,-56
L83:
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
	sw	$30,-24+printStringArray_framesize($sp)
	sw	$0,-4+printStringArray_framesize($sp)
	sw	$0,-8+printStringArray_framesize($sp)
	lw	$30,0+printStringArray_framesize($sp)
	lw	$30,-4($30)
	addi	$30,$30,-1
	sw	$30,-12+printStringArray_framesize($sp)
L18:
	lw	$25,-12+printStringArray_framesize($sp)
	lw	$30,-8+printStringArray_framesize($sp)
	slt	$30,$25,$30
	beq	$30,$0,L19
L20:
L21:
L15:
	or	$2,$0,$0
	lw	$30,-20+printStringArray_framesize($sp)
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
	lw	$30,-24+printStringArray_framesize($sp)
	or	$30,$0,$30
	or	$30,$0,$30
	b	L82
L17:
	lw	$30,0+printStringArray_framesize($sp)
	lw	$30,0($30)
	or	$30,$0,$30
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
	la	$25,L16
	or	$5,$0,$25
	jal	concat
	or	$25,$0,$2
	or	$2,$0,$30
	or	$4,$0,$25
	jal	print
	lw	$30,-8+printStringArray_framesize($sp)
	addi	$30,$30,1
	sw	$30,-8+printStringArray_framesize($sp)
	b	L18
L19:
	b	L17
L84:
	b	L21
L82:

	addiu	$sp,$sp,printStringArray_framesize
	j	$31
	.end	printStringArray
	.data
L16:	.word	1
	.ascii	"\n"
	.align	2
	.text


	.globl	getStringArray
	.ent	getStringArray
	getStringArray_framesize=44
	.frame	$sp,getStringArray_framesize,$31
getStringArray:	   
	addiu	$sp,$sp,-44
L86:
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
	b	L85
L85:

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
L88:
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
	b	L87
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
L89:
	b	L12
L87:

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
L91:
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
	b	L90
L90:

	addiu	$sp,$sp,getString_framesize
	j	$31
	.end	getString

	.globl	getString2
	.ent	getString2
	getString2_framesize=48
	.frame	$sp,getString2_framesize,$31
getString2:	   
	addiu	$sp,$sp,-48
L93:
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
	b	L92
L2:
	la	$30,L1
	or	$30,$0,$30
	b	L4
L92:

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

