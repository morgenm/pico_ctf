Two binaries given.
Checking for diff of strings of each did not help.

Did: objdump -d for both binarys
Then diffed the two outputs.

Found:
2c2
< breadth.v1:     file format elf64-x86-64
---
> breadth.v2:     file format elf64-x86-64
164220,164225c164220,164225
<    95049:	48 8b 54 24 f0       	mov    -0x10(%rsp),%rdx
<    9504e:	b8 3a 80 37 d0       	mov    $0xd037803a,%eax
<    95053:	48 39 c2             	cmp    %rax,%rdx
<    95056:	74 08                	je     95060 <fcnkKTQpF+0x20>
<    95058:	c3                   	ret
<    95059:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)
---
>    95049:	48 8b 44 24 f0       	mov    -0x10(%rsp),%rax
>    9504e:	48 3d 3e c7 1b 04    	cmp    $0x41bc73e,%rax
>    95054:	74 0a                	je     95060 <fcnkKTQpF+0x20>
>    95056:	c3                   	ret
>    95057:	66 0f 1f 84 00 00 00 	nopw   0x0(%rax,%rax,1)
>    9505e:	00 00

So opened binary breadth.v2 in ghidra and searched for fcnkKTQpF.
Found it to be a function which puts the flag.
Found flag: picoCTF{VnDB2LUf1VFJkdfDJtdYtFlMexPxXS6X}
