#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

//? self-referental structure
struct node {
  int value;
  struct node *next;
};

struct node *createNode(int);
void insertNodeAtTheBeginning();
void insertNodeAtTheEnd();
void insertNodeAtPosition();
void deletePosition();
void search();
void updateValue();
void display();

struct node *newnode, *ptr, *prev, *temp;
struct node *head = NULL, *tail = NULL;

int main() {
  int ch = '\0';

  while (true) {
    printf("\n------------------------------------\n");
    printf("\nOperations on a linked-list\n");
    printf("\n------------------------------------\n");
    printf("\n1.Insert node at Beginning");
    printf("\n2.Insert node at End");
    printf("\n3.Insert node at a specific position");
    printf("\n4.Delete node from any position");
    printf("\n5.Update node value");
    printf("\n6.Search Element in the linked-list");
    printf("\n7.Display List");
    printf("\n8.Exit\n");
    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("\nEnter your choise : ");
    scanf("%d", &ch);

    switch (ch) {
    case 1:
      insertNodeAtTheBeginning();
      break;
    case 2:
      insertNodeAtTheEnd();
      break;
    case 3:
      insertNodeAtPosition();
      break;
    case 4:
      deletePosition();
      break;
    case 5:
      updateValue();
      break;
    case 6:
      search();
      break;
    case 7:
      display();
      break;
    case 8:
      printf("\n...Exiting...");
      return 0;
    default:
      printf("\n...Invalid Choise...\n");
      break;
    }
  }

  return 0;
}

//? creating a node
struct node *createNode(int value) {
  newnode = (struct node *)malloc(sizeof(struct node));
  if (newnode == NULL) {
    printf("\nMemory was not allocated\n");
    return 0;
  } else {
    newnode->value = value;
    newnode->next = NULL;
    return newnode;
  }
}

void insertNodeAtTheBeginning() {
  int value = 0;

  printf("\nEnter the value for the node : ");
  scanf("%d", &value);
  newnode = createNode(value);

  //? head = tail = null => list is empty
  if (head == tail && head == NULL) {

    head = tail = newnode;
    head->next = NULL;
    tail->next = NULL;

  } else {

    temp = head;
    head = newnode;
    head->next = temp;
  }

  printf("\n----INSERTED----\n");
}

void insertNodeAtPosition() {
  int pos, val, cnt = 0, i;

  printf("\nEnter the value for the Node : ");
  scanf("%d", &val);

  newnode = createNode(val);

  printf("\nEnter the position : ");
  scanf("%d", &pos);

  ptr = head;

  while (ptr != NULL) {
    ptr = ptr->next;
    cnt++;
  }

  if (pos == 1) {
    if (head == tail && head == NULL) {
      head = tail = newnode;
      head->next = NULL;
      head->next = NULL;
    } else {
      temp = head;
      head = newnode;
      head->next = temp;
    }

    printf("\nINSERTED");
  } else if (pos > 1 && pos <= cnt) {

    ptr = head;

    for (i = 1; i < pos; i++) {
      prev = ptr;
      ptr = ptr->next;
    }

    prev->next = newnode;
    newnode->next = ptr;
    printf("\n---INSERTED---\n");
  } else {
    printf("Position is out of range !\n");
  }
}

void deletePosition()
{
    int pos, cnt = 0, i;

    if(head == NULL){
        printf("List is Empty\n");
        printf("No node to delete !\n");
    } else {
        printf("\nEnter the position of value to be deleted : ");
        scanf("%d", &pos);

        ptr = head;
        if(pos == 1)
        {
            head = ptr->next;
            printf("\nElement deleted\n");

        } else {
            while (ptr != NULL) {
                ptr = ptr ->next;
                cnt = cnt + 1;
            }
            if(pos > 0 && pos <= cnt){
                ptr = head;

                for(i=1; i<pos; i++){
                    
                }
            }
        }
    }
}

void insertNodeAtTheEnd();
void search();
void updateValue();
void display();
