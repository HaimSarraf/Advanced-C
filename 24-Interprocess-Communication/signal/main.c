#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

int main()
{
    printf("Testing Signal : SIGNTOP\n");

    raise(SIGSTOP);

    //! in a ubuntu machine, in terminal :
    //! $ ps
    //! then you have the processes details
    //! now you can terminate the SIGNCONT [xxxx] :
    //! $ kill -s SIGNCONT [xxxx]
    //! now the line below will run :)

    printf("I am back\n\n");

    return 0;
}