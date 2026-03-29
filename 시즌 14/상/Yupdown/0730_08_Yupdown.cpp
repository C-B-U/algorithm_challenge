#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

int memo[1000][1000];
int ret[1000][1000];

int main()
{
	FASTIO();

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n - 1; ++j)
		{
			char c;
			cin >> c;
			memo[i][j + (c == '>')]++;
		}
	}
	for (int i = 0; i < n - 1; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			char c;
			cin >> c;
			memo[i + (c == '>')][j]++;
		}
	}

	queue<pair<int, int>> q;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (memo[i][j] == 0)
				q.emplace(i, j);
		}
	}
	int v = n * n;
	while (!q.empty())
	{
		auto [i, j] = q.front();
		q.pop();

		ret[i][j] = v--;
		for (int d = 0; d < 4; ++d)
		{
			int ip = i + "1120"[d] - '1';
			int jp = j + "2011"[d] - '1';
			if (ip < 0 || ip >= n || jp < 0 || jp >= n)
				continue;
			if (--memo[ip][jp] == 0)
				q.emplace(ip, jp);
		}
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
			cout << ret[i][j] << ' ';
		cout << '\n';
	}
}