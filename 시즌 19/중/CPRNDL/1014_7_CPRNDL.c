#include <stdio.h>
int h[100][3];
int min(int a, int b)
{
	return a < b ? a : b;
}
int main()
{
	int n, r, g, b;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d %d", &r, &g, &b);
		if (i == 0)
		{
			h[i][0] = r;
			h[i][1] = g;
			h[i][2] = b;
		}
		else
		{
			h[i][0] = r + min(h[i - 1][1], h[i - 1][2]);
			h[i][1] = g + min(h[i - 1][0], h[i - 1][2]);
			h[i][2] = b + min(h[i - 1][1], h[i - 1][0]);
		}
	}
	printf("%d", min(h[n - 1][0], min(h[n - 1][1], h[n - 1][2])));
	return 0;
}
