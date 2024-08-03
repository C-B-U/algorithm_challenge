#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

constexpr int INF = 1'000'000'000;

int solution(const pair<int, int>& ep, const vector<pair<int, int>>& v, int sp, int hp, int dp, int d, int mask)
{
	int dist_end = abs(ep.first - v[sp].first) + abs(ep.second - v[sp].second);
	if (hp + dp - dist_end >= 0)
		return dist_end;
	int ret = INF;
	for (int i = 1; i < v.size(); ++i)
	{
		if (mask >> i & 1)
			continue;
		int dist = abs(v[i].first - v[sp].first) + abs(v[i].second - v[sp].second);
		if (hp + dp - dist >= 0)
			ret = min(ret, solution(ep, v, i, hp + min(0, dp - dist + 1), d - 1, d, mask | 1 << i) + dist);
	}
	return ret;
}

int main()
{
	FASTIO();

	pair<int, int> ep;
	vector<pair<int, int>> up;

	int n, h, d;
	cin >> n >> h >> d;
	for (int i = 0; i < n * n; ++i)
	{
		int x = i / n;
		int y = i % n;
		char c;
		cin >> c;
		switch (c)
		{
		case 'E':
			ep = { x, y };
			break;
		case 'S':
			up.emplace(up.begin(), x, y);
			break;
		case 'U':
			up.emplace_back(x, y);
			break;
		}
	}

	int dist = solution(ep, up, 0, h, 0, d, 1);
	cout << (dist == INF ? -1 : dist);
}