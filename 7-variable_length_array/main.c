#include <stdio.h>
#include <stddef.h>


int main()
{
    size_t rows = 0 ;

    size_t columns = 0;

    printf("Enter the number of Rows you want to store: ");
    scanf("%zd" , &rows);

    printf("Enter the number of Columns in each Row : ");
    scanf("%zd", &columns);

    printf("You made a [%zd][%zd] array\n", rows , columns);
    
    float array[rows][columns];
    
    return 0;
}