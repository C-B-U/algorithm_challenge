#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

// 각 종류마다 무한한 개수를 가지는 동전에 관한 냅색 경우의 수 문제

// memo[i] -> i원을 만들 수 있는 경우의 수
// memo[0] = 1
// memo[i] = memo[i - p] + memo[i] (for each p in table where i - p >= 0)

// 그러나, A원 동전 + B원 동전과 B원 동전 + A원 동전은 하나의 경우로 취급해야 하므로
// 각각의 동전 종류에 대해 별개로 다이나믹 프로그래밍을 수행해야 한다.
// 단, 이전 동전의 정보를 활용하여 경우의 수를 누적시켜준다.

using namespace std;
int memo[1 << 14];

int main()
{
	FASTIO();

	int t;
	cin >> t;
	while (t--)
	{
		int n, m;
		cin >> n;
		vector<int> table;
		for (int i = 0; i < n; ++i)
			cin >> table.emplace_back();
		cin >> m;
		memset(memo, 0, sizeof(memo));
		memo[0] = 1;
		for (const int& p : table)
		{
			for (int i = p; i <= m; ++i)
				memo[i] += memo[i - p];
		}
		cout << memo[m] << "\n";
	}
}