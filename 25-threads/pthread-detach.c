#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void * threadFn( void * arg);


int main(int argc, char *argv[])
{
    pthread_t tid;
    int ret = pthread_create(&tid,NULL,threadFn,NULL);

    if (ret  != 0) {
        perror("Thread Creation Error\n");
        exit(1);
    }   

    printf("After thread created in main()\n");

    pthread_exit(NULL);
}



void * threadFn( void * arg)
{
    pthread_detach(pthread_self());

    sleep(1);

    printf("Thread Fn\n");

    pthread_exit(NULL);
}