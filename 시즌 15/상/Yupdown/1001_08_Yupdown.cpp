#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;
long long table[10000];

// Parametric Search 를 이용한 빠른 목표값 접근

int main()
{
	FASTIO();

	long long n, m;
	cin >> n >> m;
	for (int i = 0; i < m; ++i)
		cin >> table[i];
	long long x = -1;
	for (long long dx = 1LL << 48; dx > 0; dx >>= 1)
	{
		long long xp = x + dx;
		long long v = 0;
		for (int i = 0; i < m; ++i)
			v += xp / table[i] + 1;
		if (v < n)
			x += dx;
	}
	long long v = 0;
	for (int i = 0; i < m; ++i)
		v += (x + table[i]) / table[i];
	for (int i = 0; i < m; ++i)
	{
		if ((x + 1) % table[i])
			continue;
		if (++v == n)
		{
			cout << i + 1;
			return 0;
		}
	}
}