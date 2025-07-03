#include <malloc.h>
#include <stdio.h>
#include <string.h>

int array_1[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
int array_2[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

int add(int a, int b) { return a + b; };
int sub(int a, int b) { return a - b; };
int mult(int a, int b) { return a * b; };
int div(int a, int b) { return a / b; };

//? Array of pointers to function
int (*fpArr[])(int, int) = {&add, &sub, &mult, &div};

int *performOperation(int *a, int *b, int size, int (*f)(int, int));
void display(int *x, int size);

int main() {
  int choise = 0;
  unsigned int size = 0; //? size of the array
  int *result = NULL;

  size = sizeof(array_1); //? set size to minimum size of the 2 arrays

  if (sizeof(array_2) < size) {
    size = sizeof(array_2);
  }

  size = size / sizeof(int);

  while (choise != 5) {
    printf("\n\nWhich Operation do you want to Perform ? \n");
    printf("1.Additon \n");
    printf("2.Subtraction \n");
    printf("3.Multiplication \n");
    printf("4.Division \n");
    printf("5.None ... \n");
    printf("Please Enter your choise :  \n");
    scanf("%d", &choise);

    if (choise == 5) {
      break;
    }
    if (choise < 1 || choise > 5) {
      continue;
    }

    int j = choise - 1;

    result = performOperation(array_1, array_2, size, fpArr[j]);

    printf("\n\nThe Results Are : \n\n");
    display(result, size);

    if (result != NULL) {
      free(result);
    }
  }

  return 0;
}

int *performOperation(int *a, int *b, int size, int (*f)(int, int)) {

  //? we're going to allocate a local array inside the function
  //? and then return that array
  //! int  : type of array's elements
  //! size : the size of each element
  int *c = malloc(sizeof(int) * size);

  for (int i = 0; i < size; i++) {
    // c[i] = (*f)(a[i], b[i]); 
    // //? the convention is not to put * here before f in the parantheses
    c[i] = (f)(a[i], b[i]);
  }

  return c;
}

void display(int *x, int size) {
    if (x== NULL) {
     return;
    }

    for (int i=0; i<size;i++){
        printf("%d   ", x[i]);
    }

    printf("\n\n");
}