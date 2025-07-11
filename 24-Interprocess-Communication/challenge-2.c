#include <stdio.h>
#include <unistd.h>

int main() {
  int n1 = fork();

  int n2 = fork();

  if (n1 > 0 && n2 > 0) {
    printf("parent\n");
    printf("%d %d \n", n1, n2);
    printf("    my id is %d \n", getpid());
    printf("    my parent-id is %d \n", getppid());
  } else if (n1 == 0 && n2 > 0) {
    printf("\nFirst Child\n");
    printf("%d %d \n", n1, n2);
    printf("    my id is %d \n", getpid());
    printf("    my parent-id is %d \n", getppid());
  } else if (n1 > 0 && n2 == 0) {
    printf("\nSecond Child\n");
    printf("%d %d \n", n1, n2);
    printf("    my id is %d \n", getpid());
    printf("    my parent-id is %d \n", getppid());
  } else {
    printf("\nThird Child\n");
    printf("%d %d \n", n1, n2);
    printf("    my id is %d \n", getpid());
    printf("    my parent-id is %d \n", getppid());
  }

  return 0;
} 