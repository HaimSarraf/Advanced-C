#include <errno.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

int score = 0;

void end_game();
int catch_signal(int sig, void (*handler)(int));
void times_up();
void error(char *msg);

int main() {
  srand(time(0));

  catch_signal(SIGALRM, times_up);
  catch_signal(SIGINT, end_game);

  while (1) {
    int a = rand() % 11;
    int b = rand() % 11;

    char text[4];

    alarm(5);
    
    printf("\nWhat is %d times %d? ", a, b);
    fgets(text, 4, stdin);

    int answer = atoi(text);

    if (answer == a * b) {
      score++;
    } else {
      printf("\nWrong ! Score : %d\n", score);
    }
  }
}

void end_game() {
  printf("\nFinal score : %d\n", score);
  exit(0);
}

int catch_signal(int sig, void (*handler)(int)) {
  struct sigaction action;
  action.sa_handler = handler;
  sigemptyset(&action.sa_mask);
  action.sa_flags = 0;

  return sigaction(sig, &action, NULL);
}

void times_up() {
  puts("\nTIME'S UP!");
  raise(SIGINT);
}

void error(char *msg) {
  fprintf(stderr, "%s : %s\n", msg, strerror(errno));
  exit(1);
}
