to execute a core-file in a directory,
do the steps below :

(on a ubuntu machine) run this codes in terminal :

1- $ gcc -g file.c
2- $ ./a.out
{ 
    after line 2, you will see this output in your terminal :
    Segmentation fault (core dumped)
 }
3- $ ls

{
    now, you can see "core" in the directory.
}

to run it,

4- $ gdb ./a.out core


