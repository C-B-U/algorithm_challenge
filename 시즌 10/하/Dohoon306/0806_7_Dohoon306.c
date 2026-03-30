#include<stdio.h>
int main() {
	int N, M;
	scanf("%d %d", &N, &M);
	if (M == 1 || M == 2) {
		printf("NEWBIE!");
	}
	else if (M != 1 && M != 2 && M <= N) {
		printf("OLDBIE!");
	}
	else {
		printf("TLE!");
	}
}
