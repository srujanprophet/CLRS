#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <time.h>

void Merge(int A[], int p, int q, int r);
void Merge_Sort(int A[], int p, int r);


int main() {
	int N;
	clock_t t;
	printf("\nEnter Size of Array\n");
      	scanf("%d",&N);
        int *A = malloc(sizeof(int)*N);
        printf("Enter Array Elements : \n");
        for ( int i = 0; i < N; i++ ) {
                scanf("%d",&A[i]);
        }
	t = clock();
	Merge_Sort(A,0,N-1);
	t = clock() - t;
	double time_taken = ((double)t)/CLOCKS_PER_SEC;
	printf("Time Taken : %f seconds\n",time_taken);
	for ( int i = 0; i < N; i++ ) {
              printf("%d ",A[i]);
        }
        printf("\n");
        return 0;
}

void Merge(int A[], int p, int q, int r) {
	int n1 = q-p+1;
	int n2 = r-q;
	int L[n1],R[n2];
	int i,j;
	for( i = 0; i < n1+1; i++ ) {
		L[i] = A[p+i-1];
	}
	for( j = 0; j < n2+1; j++ ) {
		R[j] = A[q+j];
	}
	L[n1+1] = INT_MAX;
	R[n2+1] = INT_MAX;
	i = 1;
	j = 1;
	for( int k = p; k <= r; k++ ) {
		if( L[i] <= R[j] ) {
			A[k] = L[i];
			i = i+1;
		}
		else {
			A[k] = R[j];
			j = j+1;
		}
	}
}

void Merge_Sort(int A[], int p, int r) {
	int q;
	if( p < r ) {
		q = (p+r)/2;
		Merge_Sort(A,p,q);
		Merge_Sort(A,q+1,r);
		Merge(A,p,q,r);
	}
}






























