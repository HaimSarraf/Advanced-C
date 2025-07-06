#include <stdio.h>
#include <stdlib.h>

//? self-referental structure
typedef struct node{
    char data;
    struct node * nextPtr;
} node_t ;

typedef node_t *ListNodePtr;

void insert(ListNodePtr *head, char value);
void insertAtEnd(ListNodePtr *head, char value);
void insertAtBeginning(ListNodePtr *head, char value);
char delete (ListNodePtr *head, char value);
void deleteAtBeginning(ListNodePtr *head);
int isEmpty(ListNodePtr head);
void printList(ListNodePtr currentPtr);

int main(void)
{
    ListNodePtr head = NULL;
    int choise = 0;
    char item = '\0';

    printf("Enter Your choise : \n"
    "1 to insert an Element into the list in alphabetical order.\n"
    "2 to insert an Element at the end of the list.\n"
    "3 to insert an Element an the beginning of the list.\n"
    "4 to delete an Element from the list.\n"
    "5 to delete an Element from the beginning of the list.\n"
    "6 to end.\n"
    );

    printf(":: ");
    scanf("%d", &choise);

    while(choise != 6){
        switch (choise) {
            case 1:
                printf("Enter a character : ");
                scanf("\n%c", &item);
                insert(&head, item);
                printList(head);
                break;
            case 2:
                printf("Enter a character : ");
                scanf("\n%c", &item);
                insertAtEnd(&head, item);
                printList(head);
                break;
            case 3:
                printf("Enter a character : ");
                scanf("\n%c", &item);
                insertAtBeginning(&head, item);
                printList(head);
                break;
            case 4:
                if (!isEmpty(head)) {
                    printf("Enter character to be deleted :");
                    scanf("\n%c", &item);
                    if (delete(&head, item)) {
                        printf("%c deleted.\n", item);
                        printList(head);
                    } else {
                        printf("%c not found.\n\n" , item);
                    }
                } else {
                    printf("List is Empty.\n\n");
                }
                break;
            case 5:
                if (!isEmpty(head)) {
                    deleteAtBeginning(&head);
                    printf("%c deleted.\n" , item);
                    printList(head);
                } else {
                    printf("List is Empty.\n\n");
                }
                break;
            default:
                printf("Invalid Choise.\n\n");
                printf("Enter your Choise:\n"
                    "1 to insert an Element into the list.\n"
                    "2 to delete an Element from the list.\n"
                    "3 to end.\n"
                );
                break;
        }

        printf("? ");
        scanf("%d", &choise);
    }

    printf("End of run.\n");

    return 0;
}

void insertAtBeginning(ListNodePtr *head, char value)
{
    ListNodePtr new_node = malloc(sizeof(node_t));

    new_node -> data = value;
    new_node -> nextPtr = *head;

    *head = new_node;
}

void insertAtEnd(ListNodePtr *head, char value)
{
    ListNodePtr current = *head;
    
    if(current != NULL){
        while (current->nextPtr != NULL){
            current = current->nextPtr;
        }
        current->nextPtr = malloc(sizeof(node_t));
        current->nextPtr->data = value;
        current->nextPtr->nextPtr = NULL;
    } else {
        current = malloc(sizeof(node_t));
        current->data = value;
        current->nextPtr = NULL;
        *head = current;
    }
}

void insert(ListNodePtr *head, char value)
{
    ListNodePtr newPtr;
    ListNodePtr previousPtr;
    ListNodePtr currentPtr;

    newPtr = malloc(sizeof(node_t));

    if (newPtr != NULL) {
        newPtr->data = value;
        newPtr->nextPtr = NULL;

        previousPtr = NULL;
        currentPtr = *head;

        while(currentPtr != NULL && value > currentPtr->data){
            previousPtr = currentPtr;
            currentPtr = currentPtr->nextPtr;
        }

        if(previousPtr == NULL){
            newPtr->nextPtr = *head;
            *head = newPtr;
        } else {
            previousPtr->nextPtr = newPtr;
            newPtr->nextPtr = currentPtr;
        }
    } else {
        printf("%c not inserted.No memory available.\n" , value);
    }
}

char delete (ListNodePtr *head, char value);
void deleteAtBeginning(ListNodePtr *head);
int isEmpty(ListNodePtr head);
void printList(ListNodePtr currentPtr);
