#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

void handler_divideByZero(int signum);

int main() {
  int result;
  int v1 = 0, v2 = 0;

  void (*signalHandlerReturn)(int);

  signalHandlerReturn = signal(SIGFPE, handler_divideByZero);

  if (signalHandlerReturn == SIG_ERR) {
    perror("Signal Error : ");
    return 1;
  }

  v1 = 121;
  v2 = 0;
  result = v1 / v2;

  //? it will crash, and send a core-dump message
  printf("Result of Divide-by-Zero is %d\n", result);

  return 0;
}

void handler_divideByZero(int signum) {
  if (signum == SIGFPE) {
    printf("Received SIGFPE, Divide-by-Zero Expectation\n");
    exit(0);
  } else {
    printf("Received %d Signal.\n", signum);
    return;
  }
}
