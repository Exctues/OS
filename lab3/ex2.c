#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b){
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void bubble_sort(int * a, int n){
	for(int i = 0; i < n-1; i++){
		for(int j = n-1; j > i; j--){
			if(a[j] < a[j-1]){
				swap(&a[j], &a[j - 1]); // use utility function to swap			
			}
		}
	}
}

void main(){
	// input procedure
	printf("Size of array?\n");
	int n;
	scanf("%d",&n);
	printf("Print the elements\n");
	int * a = malloc(n*sizeof(int)); // creating array for n elements
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	bubble_sort(a, n); // in-place sorting
	// output
	printf("Sorted array:\n");
	for(int i = 0; i < n; i++){
		printf("%d ", a[i]);
	}
}	
