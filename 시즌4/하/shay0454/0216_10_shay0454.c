#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int main() {
	int a, b,n,xi,xj,xx,xy;
	scanf("%d %d", &a, &b);
	int **p = (int**)calloc(a, sizeof(int*));
	for (int i = 0; i < a; i++) {
		*(p+i) = (int*)calloc(b, sizeof(int));
	}
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) {
			scanf("%d", (*(p + i) + j));
		}
	}
	scanf("%d", &n);
	int* answer = (int*)calloc(n, sizeof(int));
	for (int u = 0; u < n; u++) {
		scanf("%d %d %d %d", &xi, &xj, &xx, &xy);
		for (int i = xi-1; i < xx; i++) {
			for (int j = xj-1; j < xy; j++) {
				answer[u]+= *(*(p + i) + j);
			}
		}
	}
	for (int i = 0; i < n; i++) {
		printf("%d\n", answer[i]);
	}
	for (int i = 0; i < a; i++) {
		free(p[i]);
	}
	free(answer);
	return 0;
}
