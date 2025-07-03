//! to run this file , in terminal(on a linux machine)
//? just type : $ gcc -D DEBUG -g challenge.c -o challenge.o
//? then type : $ ./challenge.o


//! to have core-files, in teminal(on a linux machine)
//? just type   : $ ulimit -c unlimited
//? then run it : $ gcc -D DEBUG -g challenge.c -o challenge.o
//?             : $ ./challenge.o 1 2 3
//! now, it runs...
//? then type   : $ ls -lrt
//! now, you can see the core file
//? now type    : $ gdb ./challenge core
//* -finish-

#include <stdio.h>
#include <stdlib.h>

int sum(int x, int y, int z);

int main(int argc, char * argv[]){
    // printf("hello world\n");

    int i,j,k;
    int result;

    #ifdef DEBUG
        fprintf(stderr, "Number of paremeters : %d\n", argc);
    #endif

    if (argc ==1) {
        printf("Please specify 3 numbers as parameters.\n");

        exit(1);
    }

    i = atoi(argv[1]);
    #ifdef DEBUG
        fprintf(stderr, "i=%d\n", i);
    #endif
    
    j = atoi(argv[2]);
    #ifdef DEBUG
        fprintf(stderr, "j=%d\n", j);
    #endif
    
    k = atoi(argv[3]);
    #ifdef DEBUG
        fprintf(stderr, "k=%d\n", k);
    #endif
    
    result = sum(i, j, 12) + sum(j, k, 19) + sum(i,k,13);

    printf("%d\n",result);


    return 0;
}

int sum(int x, int y, int z) {
  char c = 2;
  int *a = NULL;

  #ifdef DEBUG
    fprintf(stderr, "x=%d\n", x);
    fprintf(stderr, "y=%d\n", y);
    fprintf(stderr, "z=%d\n", z);
    fprintf(stderr, "a=%ld\n", (long)a);
  #endif
  
  *a = 5;

  #ifdef DEBUG
    fprintf(stderr, "*a=%d\n", *a);
  #endif //DEBUG

  return (c + x + y + z + *a) / 3;
}