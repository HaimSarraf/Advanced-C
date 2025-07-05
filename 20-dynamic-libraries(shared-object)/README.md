the steps below helps you to make a dynamic-library in a C-project (this codes are compatible with an Ubuntu-machine)

in main folder of project,

1. $ gcc -fPIC -c myDynamicLib/Sources/myDynamicLib.c -o myDLib.o

2. $ gcc -shared -o libmylib.so myDLib.o

3. $ gcc Testing/Sources/main.c -L. -lmylib -o main

4. $ LD_LIBRARY_PATH=. ./main

after this your main.c-file will be executed

{
5. $ export LD_LIBRARY_PATH=.:$LD_LIBRARY_PATH

6. $ main
}