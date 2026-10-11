//메인 아이디어: 체스판을 가로로 쫙 펼치고 좌표값을 2로 나눈 나머지 합이 0 또는 k면 YES

#include <stdio.h>

typedef long long ll;

int main()
{
	ll n, m, k, x, y, sum = 0;
	scanf("%lld %lld %lld", &n, &m, &k);
	for (ll i = 0; i < k; i++)
	{
		scanf("%lld %lld", &x, &y);
		if (y % 2 == 0)
		{
			sum += (((y - 1) * n) + ((n + 1) - x)) % 2;
		}
		else
		{
			sum += ((y * n) - (n - x)) % 2;
		}
	}
	if (sum == 0 || sum == k)
	{
		printf("YES");
	}
	else
	{
		printf("NO");
	}
	return 0;
}
