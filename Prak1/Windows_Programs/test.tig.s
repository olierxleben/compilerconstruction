
	.globl	t_main
	.ent	t_main
	t_main_framesize=40
	.frame	$sp,t_main_framesize,$31
t_main:	   
	addiu	$sp,$sp,-40
L3:
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
	la	$25,L0
	sw	$25,-4+t_main_framesize($sp)
	lw	$25,0+t_main_framesize($sp)
	or	$2,$0,$25
	lw	$25,-4+t_main_framesize($sp)
	or	$4,$0,$25
	jal	print
	lw	$25,0+t_main_framesize($sp)
	or	$2,$0,$25
	la	$25,L1
	or	$4,$0,$25
	jal	print
	or	$2,$0,$2
	lw	$25,-8+t_main_framesize($sp)
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
	b	L2
L2:

	addiu	$sp,$sp,t_main_framesize
	j	$31
	.end	t_main
	.data
L1:	.word	1
	.ascii	"\n"
	.align	2
	.text

	.data
L0:	.word	2
	.ascii	"OK"
	.align	2
	.text

