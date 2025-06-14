#include <stdio.h>


int main(){

    //! integar is 32bits on most systems
    
    
    int w1 = 3; //? 0000 0000 0000 0000 0000 0000 0000 0011
    int w2 = 138; //? 0000 0000 0000 0000 0000 0000 1000 1010
    unsigned int w3 = 4151832098; //? 1111 0111 0111 0111 1110 1110 0010 0010
    int w4 = 5; //? 101
    signed int w5 = 138; //? 1000 1010

    int result1 = 0;
    int result2 = 0;
    int result3 = 0;
    int result4 = 0;
    int result5 = 0;
    int result6 = 0;

    result1 = w1 << 1; //? 0000 0000 0000 0000 0000 0000 0000 0110
    result2 = w2 << 2; //? 0000 0000 0000 0000 0000 0010 0010 1000
    result3 = w3 >> 1; //? 0111 1011 1011 1011 1111 0111 0001 0001 = 2075916049
    result4 = w4 >> 2; //? 001 = 1
    result5 = w5 >> 2; //? 0010 0010 = 34
    result6 = w2 >> 2; //? 0010 0010 = 34

    printf("%d\n", result1);
    printf("%d\n", result2);
    printf("%d\n", result3);
    printf("%d\n", result4);
    printf("%d\n", result5);
    printf("%d\n", result6);

    return 0;
}