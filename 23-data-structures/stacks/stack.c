#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *link;
};

struct Node *top = NULL;

void push(int data);
int isEmpty();
void pop();
void display();

int main() {
  push(1);
  push(2);
  push(3);
  push(4);

  display();

  pop();
  pop();

  display();

  return 0;
}

void push(int data) {
  struct Node *temp = malloc(sizeof(data));

  if (temp != NULL) {
    temp->data = data;
    temp->link = top;
    top = temp;
  }
}

int isEmpty() { return top == NULL; }

void pop() {
  struct Node *temp;

  if (top != NULL) {
    temp = top;
    top = top->link;
    temp->link = NULL;
    free(temp);
  }
}

void display() {
  struct Node *temp;

  if (top != NULL) {
    temp = top;
    while (temp != NULL) {
      printf("- %d -\n", temp->data);
      temp = temp->link;
    }
  }
}