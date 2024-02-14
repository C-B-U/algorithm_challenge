#include <stdio.h>

int main() {
	int aray[41][2];
	aray[0][0] = 1;
	aray[0][1] = 0;
	aray[1][0] = 0;
	aray[1][1] = 1;
	for (int i = 2; i < 41; i++) {
		aray[i][0] = aray[i - 1][0] + aray[i - 2][0];
		aray[i][1] = aray[i - 1][1] + aray[i - 2][1];
	}
	int n, a;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a);
		printf("%d %d\n", aray[a][0], aray[a][1]);
	}
}