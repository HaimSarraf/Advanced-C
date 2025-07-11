#include <stdio.h>
#include <unistd.h>
// #include <signal.h>

int main(void)
{
    alarm(5);

    //? need to catch SIGALRM or procecc terminates
    //? signal(SIGALRM, alarmHandler);

    for (int i = 1; i<10; i++) {
        printf("i = %d\n", i);
        sleep(1);
    }

    return 0;
}