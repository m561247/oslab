#include <stdio.h>
#include "lib.h"
int main()
{
	int arr[] = {15, 22, 41, 8, 35};
	int size = sizeof(arr) / sizeof(int);
	printf("before :");
	for (int i = 0; i < size; i++) {
		printf(" %d", arr[i]);
	}
	
	selection_sort(arr, size);

	printf("\nafter :");

	for (int i = 0; i < size; i++) {
		printf(" %d", arr[i]);
	}
	printf("\n");
	return 0;
}


