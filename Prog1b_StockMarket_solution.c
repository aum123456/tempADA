// USN: 1DS20CS145
// Name: Aum S. Patil
// ADA lab internal

#include <stdio.h>

struct stock {
	int left; //starting index of max subarray, basically starting day
	int right; //ending index of max subarray, basically ending day
	int sum; //max sum of the max subarray
};

struct stock crossSubSum(int *a, int low, int mid, int high) {
	
	int maxleft, maxright;
	maxleft = maxright = 0;
	struct stock result;
	
	int sum = 0;
	int leftSum = 0;
	for (int i=mid; i>=low; i--) {
		sum = sum + a[i];
		if (sum > leftSum) {
			leftSum = sum;
			maxleft = i;
		}
	}
	sum = 0;
	int rightSum = 0;
	for (int i=mid+1; i<=high; i++) {
		sum = sum + a[i];
		if (sum > rightSum) {
			rightSum = sum;
			maxright = i;
		}
	}
	
	result.left = maxleft;
	result.right = maxright;
	result.sum = (leftSum+rightSum);
	return result;
}

struct stock maxSubSum(int *a, int low, int high) {
	
	struct stock result;
	
	if (low==high) {
		result.left = low;
		result.right = high;
		result.sum = a[low];
		return result;
	}
	int mid = (low+high)/2;
	struct stock leftSum = maxSubSum(a, low, mid);
	struct stock rightSum = maxSubSum(a, mid+1, high);
	struct stock crossSum = crossSubSum(a, low, mid, high);
	if (leftSum.sum >= rightSum.sum && leftSum.sum >= crossSum.sum) return leftSum;
	else if (rightSum.sum >= leftSum.sum && rightSum.sum >= crossSum.sum) return rightSum;
	else return crossSum;
}

int main() {
	printf("No. of days in market: ");
	int n; scanf("%d", &n);
	printf("Profit/loss everyday: ");
	int a[10];
	for (int i=0; i<n; i++) scanf("%d", &a[i]);
	int low = 0;
	int high = n-1;
	struct stock maxSum = maxSubSum(a, low, high);
	printf("Max profit obtained from Day %d to Day %d.\n", (maxSum.left)+1, (maxSum.right)+1);
	printf("Max profit = %d\n", maxSum.sum);
	return 0;
}
/*
13 -3 -25 20 -3 16
*/