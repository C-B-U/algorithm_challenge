#include<stdio.h>
int main() {
	int N, side = 2, spot;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		side = side * 2 - 1;
	}
	printf("%d\n", side * side);
}
