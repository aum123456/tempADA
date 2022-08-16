#include <stdio.h>

struct faculty {
	char name[20];
	int exp;
};

struct faculty a[7] = {
	{"999",999},
	{"John", 1},
	{"Jacob", 2},
	{"Dave", 4},
	{"Emily", 6},
	{"Ava", 7},
	{"Jessica", 8}
};

int d;
int x[100];

void SOS(int wsf, int k, int rwt) {
	x[k] = 1;
	if (wsf+a[k].exp == d) {
		printf("Team of {\n");
		for (int i=1; i<=k; i++) {
			if (x[i]==1) {
				printf("%s with %d years of exp\n", a[i].name, a[i].exp);
			}
		}
		printf("}\n");
	}
	else if (wsf+a[k].exp+a[k+1].exp <= d) {
		SOS(wsf+a[k].exp, k+1, rwt-a[k].exp);
	}
	if ((wsf+rwt-a[k].exp >= d)&&(wsf+a[k+1].exp <= d)) {
		x[k] = 0;
		SOS(wsf, k+1, rwt-a[k].exp);
	}
}

int main() {
	int sum = 0;
	for (int i=1; i<=6; i++) {
		sum = sum + a[i].exp;
	}
	printf("Enter total experience required: ");
	scanf("%d", &d);
	if (d > sum) {
		printf("Solution does not exist.");
	}
	else {
		printf("LIST OF TEACHERS AVAILABLE:\n\n");
		printf("NAME \t EXPERIENCE \n");
		for (int i=1; i<=6; i++) {
			printf("%s \t %d yrs \n", a[i].name, a[i].exp);
		}
		printf("------------------------\n");
		SOS(0, 1, sum);
	}
	return 0;
}
/*

Total experience = 9 yrs, then expected output as follows:

NAME     EXPERIENCE
John     1 yrs
Jacob    2 yrs
Dave     4 yrs
Emily    6 yrs
Ava      7 yrs
Jessica          8 yrs
------------------------
Team of {
John with 1 years of exp
Jacob with 2 years of exp
Emily with 6 years of exp
}
Team of {
John with 1 years of exp
Jessica with 8 years of exp
}
Team of {
Jacob with 2 years of exp
Ava with 7 years of exp
}

*/