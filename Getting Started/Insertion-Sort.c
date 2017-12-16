#include <stdio.h>
#include <stdlib.h>

void Insertion_Sort(int A[]);
int N;

int main() {
	printf("\nEnter Size of Array\n");
	scanf("%d",&N);
	int *A = malloc(sizeof(int)*N);
	printf("Enter Array Elements : \n");
	for ( int i = 0; i < N; i++ ) {
		scanf("%d",&A[i]);
	}
	Insertion_Sort(A);
	for ( int i = 0; i < N; i++ ) {
		printf("%d ",A[i]);
	}
	printf("\n");
	return 0;
}

void Insertion_Sort(int A[]) {
	int i,j,key;
	for ( j = 1; j < N; j++ ) {
		key = A[j];
		//Insert A[j] into sorted sequence A[0..j-1]
		i = j-1;
		while ( i >= 0 && A[i] > key ) {
			A[i+1] = A[i];
			i = i-1;
		}
		A[i+1] = key;
	}
}













