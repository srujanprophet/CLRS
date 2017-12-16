#include <stdio.h>
#include <limits.h>

struct Tuple {
	int left_i;
	int right_i;
	int sum;
};

int A[100005];

struct Tuple Find_Max_Crossing_Subarray(int low,int mid,int high) {
	int left_sum = INT_MIN;
	int sum = 0,max_left,max_right;
	for ( int i = mid; i >= low; i-- ) {
		sum = sum + A[i];
		if ( sum > left_sum ) {
			left_sum = sum;
			max_left = i;
		}
	}
	int right_sum = INT_MIN;
	sum = 0;
	for (int  j = mid+1; j <= high; j++ ) {
		sum = sum + A[j];
		if ( sum > right_sum ) {
			right_sum = sum;
			max_right = j;
		}
	}
	struct Tuple crossing = { max_left, max_right, left_sum + right_sum };
	return crossing;
}

struct Tuple Find_Max_Subarray(int low, int high) {
	int mid;
	if ( high == low ) {
		struct Tuple t = { low, high, A[low] };  // base case : only 
		return t;				 // one element
	}
	else {
		mid = (low+high)/2;
		struct Tuple left=Find_Max_Subarray(low,mid);
		struct Tuple right=Find_Max_Subarray(mid+1,high);
		struct Tuple crossing=Find_Max_Crossing_Subarray(low,mid,high);
		if ( left.sum >= right.sum && left.sum >= crossing.sum ) {
			return left;
		}
		else if ( right.sum >= left.sum && right.sum >= crossing.sum ) {			return right;
		}
		else {
			return crossing;
		}
	}
}

int main() {
	struct Tuple ans;
	int N;
	printf("\nEnter Size of Array \n");
	scanf("%d",&N);
	printf("Enter Elements : \n");
	for ( int i=0; i < N; i++ ) {
		scanf("%d",&A[i]);
	}
	ans = Find_Max_Subarray(0,N-1);
	printf("----Maximum Subarray----\n");
	printf("Left Index : %d\n",ans.left_i);
	printf("Right Index : %d\n",ans.right_i);
	printf("Sum : %d\n",ans.sum);
	printf("Max. Subarray : \n");
	for ( int i = ans.left_i; i <= ans.right_i; i++ )
		printf("%d ",A[i]);
	printf("\n");
	return 0;
}





















