#include <stdio.h>
#include <string.h>
int main()
{
	char buf[51];
	int ab[26] = { 0 }, is_odd = 0, odd;
	scanf("%s", buf);
	for (int i = 0; i < strlen(buf); i++)
	{
		ab[(int)(buf[i]) - 65]++;
	}
	for (int i = 0; i < 26; i++)
	{
		if (ab[i] % 2 == 1)
		{
			is_odd++;
			odd = i;
		}
	}
	if (is_odd > 1)
	{
		printf("ERROR");
		return 0;
	}
	else
	{
		for (int i = 0; i < 26; i++)
		{
			int half = ab[i] / 2;
			for (int j = 0; j < half; j++)
			{
				printf("%c", i + 65);
				ab[i]--;
			}
		}
		if (is_odd)
		{
			printf("%c", odd + 65);
			ab[odd]--;
		}
		for (int i = 25; i >= 0; i--)
		{
			while (ab[i] > 0)
			{
				printf("%c", i + 65);
				ab[i]--;
			}
		}
	}
	return 0;
}
