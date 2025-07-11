#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

int pthread_join(pthread_t thread, void **retval);

void * hello_return(void *arg)
{
    char * hello = strdup("hello_return\n");
    return (void *) hello;
}

int main(int argc, char *argv[])
{
    char * str;
    pthread_t thread;

    //? create a new thread that runs hello_return without arguments .
    pthread_create(&thread, NULL, hello_return, NULL);

    //? wait until the thread completes, assign return value to str .
    pthread_join(thread, (void **) &str);
    
    //? Uncomment the exit() and there is no output anymore .
    // pthread_exit(NULL);
    
    printf("%s", str);


    return 0;
}