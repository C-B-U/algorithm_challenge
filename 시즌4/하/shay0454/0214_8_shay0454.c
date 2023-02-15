#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int absolute(int, int);

struct taxi {
	int p[2];
	int distance;
};

int main() {
	int n, mini = 0;
	struct taxi a;
	struct taxi taxi[100];
	scanf("%d %d", &(a.p[0]), &(a.p[1]));
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &(taxi[i].p[0]), &(taxi[i].p[1]));
		taxi[i].distance = absolute(a.p[0], taxi[i].p[0]) + absolute(a.p[1], taxi[i].p[1]);
		if (taxi[i].distance < taxi[mini].distance) mini = i;
	}
	printf("%d %d", taxi[mini].p[0], taxi[mini].p[1]);
	return 0;
}

int absolute(int a, int b) {	
	if (a - b < 0) return b - a;
	else return a - b;
}
