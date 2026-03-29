#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<time.h>
int main() {
	int m, a, x = 0;
	long long re,l;
	scanf("%d %lld", &m, &l);
	for (l; l <= 100; l++) {
		a = m / l - (l - 1) / 2;
		if (a < 0) break;
		for (a; 1;a++) {
			re = (l * (2 * a + l - 1) / 2);
			if (m == re) {
				x=1;
				break;
			}
			else if (re> m) {
				break;
			}
			
		}
		if (x == 1) {
			break;
		}
	}
	if (x == 1) {
		for (int i = 0; i < l; i++) {
			if (i == l - 1) {
				printf("%d", a + i);
				break;
			}
			else {
				printf("%d ", a + i);
			}
		}
	}
	else if (x == 0) {
		printf("-1");
	}
	return 0;
}
