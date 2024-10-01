#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

// memo[i][j][k][l] denotes respectively:
// i: delivery status
// j: x
// k: y
// l: last direction that Minsik moved toward
int memo[3][50][50][4];
char table[64][64];

int main()
{
	FASTIO();

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		cin >> table[i];

	queue<tuple<int, int, int, int>> q;

	// need to number each delivery to identify
	for (int i = 0, c = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (table[i][j] == 'C')
				table[i][j] = '1' + c++;
			if (table[i][j] == 'S')
			{
				table[i][j] = '.';
				for (int k = 0; k < 4; ++k)
				{
					q.emplace(0, i, j, k);
					memo[0][i][j][k] = 1;
				}
			}
		}
	}

	while (!q.empty())
	{
		auto [i, j, k, l] = q.front();
		q.pop();

		for (int d = 0; d < 4; ++d)
		{
			if (d == l)
				continue;
			int jp = j + "1102"[d] - '1';
			int kp = k + "0211"[d] - '1';
			if (jp < 0 || jp >= n || kp < 0 || kp >= m)
				continue;
			if (table[jp][kp] == '#')
				continue;
			int ip = i;
			if (isdigit(table[jp][kp]) && table[jp][kp] - '0' != i)
				ip += table[jp][kp] - '0';
			if (ip > 2)
			{
				cout << memo[i][j][k][l];
				return 0;
			}
			if (memo[ip][jp][kp][d] > 0)
				continue;
			memo[ip][jp][kp][d] = memo[i][j][k][l] + 1;
			q.emplace(ip, jp, kp, d);
		}
	}

	cout << -1;
}