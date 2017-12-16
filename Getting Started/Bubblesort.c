#include <stdio.h>
#include <stdlib.h>

int N;

void Bubblesort(int A[]) {
	int i,j,temp;
	for( i = 0; i < N-1; i++ ) {
		for( j = N-1; j > i; j-- ) {
			if( A[j] < A[j-1]) {
				temp = A[j];
				A[j] = A[j-1];
				A[j-1] = temp;
			}
		}
	}
}

int main() {
        printf("\nEnter Size of Array\n");
        scanf("%d",&N);
        int *A = malloc(sizeof(int)*N);
        printf("Enter Array Elements : \n");
        for ( int i = 0; i < N; i++ ) {
                scanf("%d",&A[i]);
	}
	Bubblesort(A);
        for ( int i = 0; i < N; i++ ) {
                printf("%d ",A[i]);
        }
        printf("\n");
        return 0;
}
