#include <stdio.h>
#include <stdlib.h>

int N;
int A[10][10];
int B[10][10];
int C[10][10];

void  Square_Matrix_Multiply() {
	int n = N;
	for( int i = 0; i < n; i++ ) {
		for( int j = 0; j < n; j++ ) {
			C[i][j] = 0;
			for( int k = 0; k < n; k++ ) {
				C[i][j] = C[i][j] + (A[i][k]*B[k][j]);
			}
		}
	}
}

int main() {
	int i,j;
	printf("Enter Order of the Matrix : \n");
	scanf("%d",&N);
	printf("Enter Elements of First Matrix : \n");
	for( i = 0; i < N; i++ ) {
		for( j = 0 ; j < N; j++ ) {
			scanf("%d",&A[i][j]);
		}
	}
	printf("Enter Elements of Second Matrix : \n");
	for( i = 0; i < N; i++ ) {
		for( j = 0; j < N; j++ ) {
			scanf("%d",&B[i][j]);
		}
	}
	Square_Matrix_Multiply();
	printf("Multiplied Matrix : \n");
	for( i = 0; i < N; i++ ) {
		for( j = 0; j < N; j++ ) {
			printf("%d   ",C[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	return 0;
}












