Given ELF binary and flag.txt

Analyzed in Ghidra. Outputted as a C program, and cut out all of the unnecessary bits.

Couldn't successfully get key from just reversing. Using gdb (pwndbg) with python.

exported PYTHONPATH to be $PYTHONPATH:$PWD so that gdb could load the python script with "python import python_debug"

wrote python script to brute force key

Ran the following command to get gdb to output the full string for use in the script:
gdb: set print repeats 200

Then simply set some breakpoints, found the address of the resulting transformed user input, and passed it to the python script. After a minute of running...

Success! The script crashes at the end, but we get the key outputted to key.txt!

Key is: 68c91cd2ff85e90efbe041faf4b572413470a5eb5f47ff9f13dec686b091e46829c55eff9d23ccdb53c0ea76b277b74ea836

The program tells us to xor it with the given flag, so xoring it online at 

Got the key!: picoCTF{cust0m_jumbl3s_4r3nt_4_g0Od_1d3A_33ead16f}. I was the 461st person to solve and got a good 300 points for this challenge.
