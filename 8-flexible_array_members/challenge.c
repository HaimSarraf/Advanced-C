#include <stdio.h>
#include <malloc.h>
#include <string.h>


struct myArray {
	int length;
	int arr[];
};

int main()
{
	struct myArray *m = NULL;
	int arraySize = 0;
	
	printf("Enter the length of array ");
	scanf("%d" , &arraySize);
	
	size_t size = sizeof(struct myArray);
	m = malloc(size + (sizeof (int) * arraySize));
	
	m->length = arraySize;
	
	for(int i = 0; i < arraySize; i++)
	{
	printf("Enter the element [%d] : " , i);
	scanf("%d", &m->arr[i]);
	
	//printf("array elements number %d is %d\n", i+1, m->arr[i]);
	}
	
	printf("Your array is : [");
	for(int i =0; i< arraySize ; i++)
	{
	  if(i < arraySize - 1){
	  printf("%d , " , m->arr[i]);
	  } else {
	  printf("%d" , m->arr[arraySize-1]);
	  }
	}
	printf("]\n");
	
	return 0;
	
	
	
}