// USN: 1DS20CS145
// Name: Aum S. Patil
// ADA lab internal

#include <stdio.h>

int a[100]; //set entered by user
int d; // sum entered by user
int x[100]; // visited elements

void SOS(int wsf, int k, int rwt) {
	// wsf = weight so far
	// rwt = remaining weight
	x[k] = 1;
	if (wsf + a[k] == d) {
		printf("Subset ==>> {");
		for (int i=1; i<=k; i++) {
			if (x[i]==1) {
				printf("%d,", a[i]);
			}
		}
		printf("}\n");
	}
	else if (wsf + a[k] + a[k+1] <= d) {
		SOS(wsf+a[k], k+1, rwt-a[k]);
	}
	if ((wsf+rwt-a[k]>=d) && (wsf+a[k+1]<=d)) {
		x[k] = 0;
		SOS(wsf, k+1, rwt-a[k]);
	}
}

int main() {
	int sum = 0;
	printf("No. of elements: ");
	int n; scanf("%d", &n);
	printf("Elements: ");
	for (int i=1; i<=n; i++) {
		scanf("%d", &a[i]);
		sum = sum + a[i];
	}
	printf("Sum required: ");
	scanf("%d", &d);
	if (d > sum) {
		printf("Solution is not possible.\n"); //since d cannot exceed the sum of all elements of the set
	}
	else {
		SOS(0,1,sum);
	}
	return 0;
}

/*
1 2 5 6 8
*/