#include <stdio.h>

#define MAXSIZE 5

struct stack {
  int stk[MAXSIZE];
  int top;
};

typedef struct stack STACK;

STACK s;

void push(void);
int pop(void);
void display(void);

int main() {
  int choise;
  int option = 1;
  s.top = -1;

  while (option) {
    printf("\n-------------------------------\n");
    printf("     1   -->  PUSH               \n");
    printf("     2   -->  POP                \n");
    printf("     3   -->  DISPLAY            \n");
    printf("     4   -->  EXIT               \n");
    printf("\n-------------------------------\n");

    printf("Enter your choise : \n");
    scanf("%d", &choise);

    switch (choise) {
    case 1:
      push();
      break;

    case 2:
      pop();
      break;

    case 3:
      display();
      break;

    case 4:
      return 0;
    }

    fflush(stdin);
    printf("Do you want to Continue?(Type 0 or 1)\n");

    scanf("%d", &option);
  }

  return 0;
}

void push(){
    int num = 0;
    if(s.top == (MAXSIZE - 1)){
        printf("\nStack is Full\n");
        return;
    } else {
        printf("\nEnter the element to be pushed\n");
        scanf("%d", &num);
        s.top = s.top + 1;
        s.stk[s.top] = num;
    }
    return;
}

int pop(){

    int num = 0;

    if(s.top == -1){
        printf("\nStack is Empty\n");
        return(s.top);
    } else {
        printf("\nPoped element is = %d\n", s.stk[s.top]);
        s.top = s.top - 1;
    }
    return(num);
}

void display(){
    
    int i = 0;

    if (s.top == -1) {
        printf("Stack is Empty\n");
        return;
    } else {
        printf("\n The status of the stack is \n");

        for(i = s.top; i>=0; i--){
            printf("%d\n", s.stk[i]);
        }
    }

    printf("\n");
}