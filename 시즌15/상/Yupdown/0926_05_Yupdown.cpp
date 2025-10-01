#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;
vector<pair<int, long long>> edges[100000];
long long memo[100000];

// 위상 정렬 기반 다이나믹 프로그래밍

int main()
{
	FASTIO();

	int n, m, k, s, t;
	cin >> n >> m >> k >> s >> t;
	for (int i = 0; i < m; ++i)
	{
		int a, b, t;
		cin >> a >> b >> t;
		edges[b - 1].emplace_back(a - 1, t);
	}
	memset(memo, -1, sizeof(memo));
	memo[s - 1] = 0;
	for (int i = 0; i <= k; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			for (const auto& [a, v] : edges[j])
			{
				if (memo[a] >= 0)
					memo[j] = max(memo[j], memo[a] + v);
			}
		}
		if (i < k)
		{
			for (int j = 0; j < n; ++j)
			{
				if (memo[j] < 0)
					continue;
				for (const auto& [a, v] : edges[j])
					memo[a] = max(memo[a], memo[j]);
			}
		}
	}
	cout << memo[t - 1];
}