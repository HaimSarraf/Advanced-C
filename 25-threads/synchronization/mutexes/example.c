//! this is a classic example of deadlock !

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

pthread_mutex_t lock1, lock2;

void *resource1();
void *resource2();

int main()
{
    pthread_mutex_init(&lock1,NULL);
    pthread_mutex_init(&lock2,NULL);

    pthread_t t1,t2;

    pthread_create(&t1,NULL,resource1,NULL);
    pthread_create(&t1,NULL,resource2,NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    return 0;
}

void *resource1()
{
    pthread_mutex_lock(&lock1);

    printf("Job started in resource-1 ... \n");
    sleep(2);

    printf("Trying to get resource-2\n");

    /*
        //? to break the deadlock

        while(pthread_mutex_trylock(&lock2)){
            pthread_mutex_unlock(&lock1);
            sleep(2);
            pthread_mutex_lock(&lock1);
        }
    */


    pthread_mutex_lock(&lock2);
    printf("Acquired resource-2\n");
    
    /*
        //? two lines above should be swapped :
    
        printf("Acquired resource-2\n");
        pthread_mutex_lock(&lock2);
  
        
        //? then : do critical stuff
        sleep(2);
    
    */

    pthread_mutex_unlock(&lock2);

    /*
        //? the above line 'lock2' should be replaced with 'lock1'

    */

    printf("Job finished in resource-1\n");


    pthread_mutex_unlock(&lock1);
    
    /*
        the line above should remove
    */

    pthread_exit(NULL);
}

void *resource2()
{
    pthread_mutex_lock(&lock2);

    printf("Job started in resource-2 ... \n");
    sleep(2);

    printf("Trying to get resource-1\n");
    pthread_mutex_lock(&lock1);
    printf("Acquired resource-1\n");
    pthread_mutex_unlock(&lock1);

    printf("Job finished in resource-2\n");

    pthread_mutex_unlock(&lock2);

    pthread_exit(NULL);
}