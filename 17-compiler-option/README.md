to debug preprocessor-debugging-example.c ,
you have 3 options :

(on a debian-linux machine like ubuntu)in terminal run the codes below:

$ gcc -D DEBUGON preprocessor-debugging-example.c -o x.c

then you can choose the debug level :

1- $ ./x.c 1 [int i] [int j]
2- $ ./x.c 2 [int i] [int j]
3- $ ./x.c 3 [int i] [int j]

for example :
{

$ ./x.c 3 5 10

then the output is:
    processed 3 arguments
    arg1 = 5, arg2 = 10
    procedd(5,10)
    return 50
    50
}