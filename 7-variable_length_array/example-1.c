#include <stdio.h>

void array (int size)
{
    char alpha[size];

    int x = 0;

    while (x< size) {
        
        alpha[x] = 'A' + x;

        printf("Alpha is %c\n" , alpha[x]);

        x++;
    }
}

int main()
{
    array(5);
    
    array(20);

    return 0;
}