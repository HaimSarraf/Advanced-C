#include <pthread.h>
#include <stdio.h>

void *my_function(void *ptr);

int main() {
  pthread_t thread;

  pthread_create(&thread, NULL, my_function, NULL);

  pthread_join(thread, NULL);

  return 0;
}

void *my_function(void *ptr) {
  printf("Hello World\n");
  pthread_cancel(pthread_self());

  return NULL;
}