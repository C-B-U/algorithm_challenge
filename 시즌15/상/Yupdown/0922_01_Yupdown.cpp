#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

int table[3000000];
int memo[3001];

// Two Pointers & Accumulation Table

int main()
{
	FASTIO();

	int n, d, k, c;
	cin >> n >> d >> k >> c;
	for (int i = 0; i < n; ++i)
		cin >> table[i];
	int v = 0;
	for (int i = 0; i < k; ++i)
	{
		if (memo[table[i]]++ == 0)
			v++;
	}
	int vmax = v + (memo[c] == 0);
	for (int i = 0; i < n; ++i)
	{
		if (memo[table[(i + k) % n]]++ == 0)
			v++;
		if (--memo[table[i]] == 0)
			v--;
		vmax = max(vmax, v + (memo[c] == 0));
	}
	cout << vmax;
}