#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main(){
	int q, temp;
	long long int sum,multi,n, c;
	sum = 0;
	multi = 1;
	scanf("%d", &q);
	n = 1;
	for (int i = 0; i < q; i++) {
		scanf("%lld", &c);
		switch (c) {
		case 0:
			scanf(" %d", &temp);
			sum += temp;
			break;

		case 1:
			scanf("%d", &temp);
			sum *= temp;
			multi *= temp;
			break;

		case 2:
			scanf(" %d", &temp);
			n += temp;
			break;

		case 3:
			printf("%lld\n", n * multi + sum);
			break;

		}
	}
}
