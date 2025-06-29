#include <stdio.h>

struct owner {
    char socsecurity[12];
};

struct leasecompany {
    char name[40];
    char headoffice[40];
};

struct car_data {
    char make[15];
    int status; //? 0 = owned , 1 = leased;
    union { //? this is annanymous union
        struct owner owncar;
        struct leasecompany leasecar;
    };
};

struct {
    char *name;
    enum symbolType type;
    union {
        int   i;
        float f;
        char  c;
    } data; //? each data can be just int OR float OR char !!!
} table [entries] ;


int main()
{
    printf("Some simple examples of unions\n");
  
    return 0;
}