#include<stdio.h>
int main() {
	int N, total = 2;//1<N<5
	scanf("%d", &N);
	for (int i = 1; i < N; i++) {
		total = total * 2;
	}
	printf("%d", total);
		

}
