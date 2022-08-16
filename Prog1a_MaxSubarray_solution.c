// USN: 1DS20CS145
// Name: Aum S. Patil
// ADA lab internal

#include <stdio.h>

int crossSubSum(int a[10], int low, int mid, int high) {
	int sum = 0;
	int leftSum = 0;
	for (int i=mid; i>=low; i--) {
		sum = sum + a[i];
		if (sum > leftSum) leftSum = sum;
	}
	sum = 0;
	int rightSum = 0;
	for (int i=mid+1; i<=high; i++) {
		sum = sum + a[i];
		if (sum > rightSum) rightSum = sum;
	}
	return (leftSum + rightSum);
}

int maxSubSum(int a[10], int low, int high) {
	if (low==high) return a[low];
	int mid = (low+high)/2;
	int leftSum = maxSubSum(a, low, mid);
	int rightSum = maxSubSum(a, mid+1, high);
	int crossSum = crossSubSum(a, low, mid, high);
	if (leftSum >= rightSum && leftSum >= crossSum) return leftSum;
	else if (rightSum >= leftSum && rightSum >= crossSum) return rightSum;
	else return crossSum;
}

int main() {
	printf("No. of elements in array: ");
	int n; scanf("%d", &n);
	printf("Enter array :");
	int a[10];
	for (int i=0; i<n; i++) scanf("%d", &a[i]);
	int low = 0, high = n-1;
	int maxSum = maxSubSum(a, low, high);
	printf("Maximum sum = %d\n", maxSum);
	return 0;
}

/*
13 -3 -25 20 -3 16
*/