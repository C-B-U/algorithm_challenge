#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

int table[1000][1000];
int span[1000][1000];

int count(int n, int m, int value)
{
	int ret = 0;
	for (int i = 0; i < n * m; ++i)
		ret += table[i / m][i % m] == value;
	return ret;
}

int main()
{
	FASTIO();

	int n, m;
	cin >> n >> m;

	queue<pair<int, int>> q;
	for (int i = 0; i < n * m; ++i)
	{
		int v;
		cin >> v;
		table[i / m][i % m] = v;
		if (v > 0)
			q.emplace(i / m, i % m);
	}

	while (!q.empty())
	{
		auto [x, y] = q.front();
		q.pop();
		if (table[x][y] > 2)
			continue;
		for (int d = 0; d < 4; ++d)
		{
			int xp = x + "1102"[d] - '1';
			int yp = y + "0211"[d] - '1';

			if (xp < 0 || xp >= n || yp < 0 || yp >= m)
				continue;
			if (span[xp][yp] == span[x][y] + 1)
				table[xp][yp] |= table[x][y];
			if (table[xp][yp] != 0)
				continue;
			table[xp][yp] = table[x][y];
			span[xp][yp] = span[x][y] + 1;
			q.emplace(xp, yp);
		}
	}

	for (int i = 0; i < 3; ++i)
		cout << count(n, m, i + 1) << ' ';
}