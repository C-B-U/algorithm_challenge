#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

int main()
{
	FASTIO();

	int t;
	cin >> t;

	while (t--)
	{
		int n, m;
		cin >> n >> m;

		vector<int> si(m);
		for (int i = 0; i < m; ++i)
			cin >> si[i];
		vector<vector<bool>> memo(n + 1);
		for (auto& elem : memo)
			elem.resize(n + 1);
		memo[0][0] = 1;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (!memo[i][j])
					continue;
				for (int s : si)
				{
					if (i + j + s > n)
						continue;
					memo[i + j + s][j + s] = true;
				}
			}
		}

		int ret = -1;
		for (int i = 0; i < n + 1; ++i)
		{
			if (memo[n][i])
				ret = max(ret, i);
		}
		cout << ret << '\n';
	}
}
