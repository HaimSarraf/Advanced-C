#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <malloc.h>

struct thread_data {
    int   thread_id;
    int   sum;
    char  *message;
};

void *print_hello(void *threadarg);

int main(int argc, char *argv[])
{
    pthread_t my_thread;
    struct thread_data my_thread_data;

    my_thread_data.message = malloc(sizeof(char) * 255);

    my_thread_data.thread_id = 10;
    my_thread_data.sum = 35;
    my_thread_data.message = "Hello World";

    pthread_t my_id = pthread_create(&my_thread, NULL, print_hello, (void *) &my_thread_data);
    pthread_join(my_thread, NULL);
    pthread_exit(NULL);

    return 0;
}

void *print_hello(void *thread_arg)
{
    struct thread_data *my_data;

    int taskId = 0, sum = 0;
    char hello_msg[255];

    my_data = (struct thread_data *) thread_arg;

    taskId = my_data->thread_id;

    sum = my_data -> sum;

    strcpy(hello_msg, my_data->message);

    printf("Task-Id = %d, Sum = %d, Message = %s\n", taskId, sum, hello_msg);
}


