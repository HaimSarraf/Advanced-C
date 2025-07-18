#include <stdio.h>
#include <stdlib.h>

#define MAX 50

void enqueue();
void dequeue();
void display();

int queue_array[MAX];
int rear = -1;
int front = -1;

int main() {
  int choise;

  while (1) {
    printf("1. Insert element to queue\n");
    printf("2. Delete element from queue\n");
    printf("3. Display all elements of queue\n");
    printf("4. Quit\n");
    printf("Enter your choise: ");
    scanf("%d", &choise);

    switch (choise) {
    case 1:
      enqueue();
      break;
    case 2:
      dequeue();
      break;
    case 3:
      display();
      break;
    case 4:
      exit(1);
    default:
      printf("Wrong choise !\n");
    }
  }
}

void enqueue() {
  int add_item = 0;

  if (rear == MAX - 1)
    printf("Queue Overflow\n");
  else {
    if (front == -1) {
      front = 0;
    }
    printf("Insert the element in queue: ");
    scanf("%d", &add_item);
    rear = rear + 1;
    queue_array[rear] = add_item;
  }
}

void dequeue() {
  if (front == -1 || front > rear) {
    printf("Queue Underflow\n");
    return;
  } else {
    printf("Element deleted from queue is: %d\n", queue_array[front]);
    front = front + 1;
  }
}

void display() {
  int i;
  if (front == -1) {
    printf("The Queue is Empty \n");
  } else {
    printf("Queue is : \n");
    for (i = front; i <= rear; i++) {
      printf(" %d ", queue_array[i]);
    }
    printf("\n");
  }
}