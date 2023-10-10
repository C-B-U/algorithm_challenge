#include <stdio.h>
#include <math.h>

int main() {
	int t;
	scanf("%d", &t);

	while (t-- > 0) {
		int x1, y1, r1, x2, y2, r2;
		scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);

		if (x1 == x2 && y1 == y2) {
			if (r1 == r2)
				printf("-1\n");
			else
				printf("0\n");
			continue;
		}

		double d = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
		int mxr = fmax(r1, r2), mnr = fmin(r1, r2);

		if (mxr - mnr < d && d < r1 + r2)
			printf("2\n");
		else if (r1 + r2 == d || mxr - mnr == d)
			printf("1\n");
		else
			printf("0\n");
	}
}
