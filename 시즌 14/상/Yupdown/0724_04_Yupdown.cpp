#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

// 1e+18 초과를 -1로 간주해야 하는데, long long 을 사용함에도 오버플로우가 날 수 있음을 유의하라.
constexpr __int128 INF = 1000000000000000001;

// 어떻게 학자 이름이 D[i][j][k] = str[a]?
__int128 dijkstra(const vector<vector<pair<int, long long>>>& edges, int start, int end)
{
	vector<__int128> dist(edges.size(), INF);
	priority_queue<pair<__int128, int>> pq;
	dist[start] = 0;
	pq.emplace(0, start);

	while (!pq.empty())
	{
		auto [d, node_curr] = pq.top();
		pq.pop();
		d = -d;
		if (dist[node_curr] < d)
			continue;
		for (const auto& [node_next, w] : edges[node_curr])
		{
			__int128 dp = d + w;
			if (dp >= dist[node_next])
				continue;
			dist[node_next] = dp;
			pq.emplace(-dp, node_next);
		}
	}

	return dist[end] >= INF ? -1 : dist[end];
}

int main()
{
	FASTIO();

	int t;
	cin >> t;

	// t번 활자 그래프의 1번부터 2번까지의 거리, 2번부터 1번까지의 거리를 담은 매핑 테이블
	// 그래프 활자를 끼우는 데 2번부터 1번까지에 대한 거리를 이용해서 최적해가 나오는 경우도 있어 조심해야 한다.
	vector<pair<long long, long long>> memo;
	for (int i = 0; i < t; ++i)
	{
		int n, q;
		cin >> n >> q;
		vector<vector<pair<int, long long>>> edges(n);
		for (int i = 0; i < q; ++i)
		{
			long long v, w, x;
			cin >> v >> w >> x;
			if (x < 0)
			{
				auto [xl, xr] = memo[-1 - x];
				if (xl >= 0)
					edges[v - 1].emplace_back(w - 1, xl);
				if (xr >= 0)
					edges[w - 1].emplace_back(v - 1, xr);
			}
			else
				edges[v - 1].emplace_back(w - 1, x);
		}
		memo.emplace_back(dijkstra(edges, 0, 1), dijkstra(edges, 1, 0));
	}
	cout << memo[t - 1].first;
}