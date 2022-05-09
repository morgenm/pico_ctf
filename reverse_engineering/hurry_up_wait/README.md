# Hurry up! Wait
The file provided in the challenge, svchost.exe, is not actually a Windows PE, it is an ELF file.
I opened and analyzed it in Ghidra. Looks like it was written in Ada, due to calls to ada_text_io.
