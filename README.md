If IDE is VSCODE to compile the main.c file correctly, all the files in Sources-Folder should be in the command-line of compilation.

for example in the first-step to compile the main.c file included other.h header,

the compilation command-line is like :

gcc other.c main.c -o main

(other.h first defines in other.c)