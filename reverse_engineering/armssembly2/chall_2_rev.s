	.arch armv8-a
	.file	"chall_2_rev.c"
	.text
	.align	2
	.global	func1
	.type	func1, %function
func1:
.LFB6:
	.cfi_startproc
	sub	sp, sp, #32
	.cfi_def_cfa_offset 32
	str	x0, [sp, 8]
	str	xzr, [sp, 16]
	str	xzr, [sp, 24]
	b	.L2
.L3:
	ldr	x0, [sp, 16]
	add	x0, x0, 3
	str	x0, [sp, 16]
	ldr	x0, [sp, 24]
	add	x0, x0, 1
	str	x0, [sp, 24]
.L2:
	ldr	x1, [sp, 24]
	ldr	x0, [sp, 8]
	cmp	x1, x0
	blt	.L3
	ldr	x0, [sp, 16]
	add	sp, sp, 32
	.cfi_def_cfa_offset 0
	ret
	.cfi_endproc
.LFE6:
	.size	func1, .-func1
	.section	.rodata
	.align	3
.LC0:
	.string	"Result: %ld\n"
	.text
	.align	2
	.global	main
	.type	main, %function
main:
.LFB7:
	.cfi_startproc
	stp	x29, x30, [sp, -48]!
	.cfi_def_cfa_offset 48
	.cfi_offset 29, -48
	.cfi_offset 30, -40
	mov	x29, sp
	str	w0, [sp, 28]
	str	x1, [sp, 16]
	ldr	x0, [sp, 16]
	add	x0, x0, 8
	ldr	x0, [x0]
	bl	atol
	str	x0, [sp, 32]
	ldr	x0, [sp, 32]
	bl	func1
	sxtw	x0, w0
	str	x0, [sp, 40]
	ldr	x1, [sp, 40]
	adrp	x0, .LC0
	add	x0, x0, :lo12:.LC0
	bl	printf
	mov	w0, 0
	ldp	x29, x30, [sp], 48
	.cfi_restore 30
	.cfi_restore 29
	.cfi_def_cfa_offset 0
	ret
	.cfi_endproc
.LFE7:
	.size	main, .-main
	.ident	"GCC: (GNU) 11.2.0"
	.section	.note.GNU-stack,"",@progbits
