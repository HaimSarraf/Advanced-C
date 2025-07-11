#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void signalHandler(int signalValue);

int main() {
  int i; //? counter use to loop 100 times
  int x; //? variable to hold random numbers between 1-50

  signal(SIGINT, signalHandler); //? register signal handler
  srand(clock());

  for (i = 1; i <= 100; i++) {
    x = 1 + rand() % 50;

    if (x == 25) {
      raise(SIGINT);
    }

    printf("%4d", i);

    if (i % 10 == 0) {
      printf("\n");
    }
  }

  return 0;
}

void signalHandler(int signalValue) {
  int response; //? user's response to signal (1 or 2)

  printf("%s%d%s\n%s", "\nInterrupt signal ( ", signalValue, " ) received.",
         "Do you wish to continue (1 = yes, 2 = no) ?  \n");

  while (response != 1 && response != 2) {
    printf("( 1 = yes , 2 = no ) ?  ");
    scanf("%d", &response);
  }

  if (response == 1) {
    signal(SIGINT, signalHandler);
  } else {
    exit(EXIT_SUCCESS);
  }
}