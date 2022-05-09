
chall_rev.o:     file format elf64-littleaarch64


Disassembly of section .text:

0000000000000000 <func1>:
   0:	d10043ff 	sub	sp, sp, #0x10
   4:	b9000fe0 	str	w0, [sp, #12]
   8:	b9000be1 	str	w1, [sp, #8]
   c:	b9400fe1 	ldr	w1, [sp, #12]
  10:	b9400be0 	ldr	w0, [sp, #8]
  14:	6b00003f 	cmp	w1, w0
  18:	5400006c 	b.gt	24 <func1+0x24>
  1c:	b9400be0 	ldr	w0, [sp, #8]
  20:	14000002 	b	28 <func1+0x28>
  24:	b9400fe0 	ldr	w0, [sp, #12]
  28:	910043ff 	add	sp, sp, #0x10
  2c:	d65f03c0 	ret

0000000000000030 <main>:
  30:	a9bd7bfd 	stp	x29, x30, [sp, #-48]!
  34:	910003fd 	mov	x29, sp
  38:	b9001fe0 	str	w0, [sp, #28]
  3c:	f9000be1 	str	x1, [sp, #16]
  40:	f9400be0 	ldr	x0, [sp, #16]
  44:	91002000 	add	x0, x0, #0x8
  48:	f9400000 	ldr	x0, [x0]
  4c:	94000000 	bl	0 <atoi>
  50:	b90027e0 	str	w0, [sp, #36]
  54:	f9400be0 	ldr	x0, [sp, #16]
  58:	91004000 	add	x0, x0, #0x10
  5c:	f9400000 	ldr	x0, [x0]
  60:	94000000 	bl	0 <atoi>
  64:	b9002be0 	str	w0, [sp, #40]
  68:	b9402be1 	ldr	w1, [sp, #40]
  6c:	b94027e0 	ldr	w0, [sp, #36]
  70:	94000000 	bl	0 <func1>
  74:	b9002fe0 	str	w0, [sp, #44]
  78:	b9402fe1 	ldr	w1, [sp, #44]
  7c:	90000000 	adrp	x0, 0 <func1>
  80:	91000000 	add	x0, x0, #0x0
  84:	94000000 	bl	0 <printf>
  88:	52800000 	mov	w0, #0x0                   	// #0
  8c:	a8c37bfd 	ldp	x29, x30, [sp], #48
  90:	d65f03c0 	ret
