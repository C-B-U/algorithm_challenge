//이진수
#include <stdio.h>
int main()
{
	int n, a = 1, g = 2, c = 4, u = 8;
	char ans[4] = "lmao";
	scanf("%d", &n);
	if (a & n)
	{
		ans[0] = 'A';
		ans[1] = 'A';
		ans[2] = 'A';
		ans[3] = 'A';
	}
	if (g & n)
	{
		ans[1] = 'G';
		ans[2] = 'G';
		ans[3] = 'G';
		if (ans[0] != 'A')
		{
			ans[0] = 'G';
		}
	}
	if (c & n)
	{
		ans[2] = 'C';
		ans[3] = 'C';
		if (ans[0] != 'A' && ans[0] != 'G')
		{
			ans[0] = 'C';
			ans[1] = 'C';
		}
	}
	if (u & n)
	{
		ans[3] = 'U';
		if (ans[0] != 'A' && ans[0] != 'G' && ans[0] != 'C')
		{
			ans[0] = 'U';
			ans[1] = 'U';
			ans[2] = 'U';
		}
	}
	//printf("%s", ans);
	printf("%c%c%c%c", ans[0], ans[1], ans[2], ans[3]);
	return 0;
}
