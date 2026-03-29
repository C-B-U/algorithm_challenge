#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

int main()
{
	FASTIO();
	int n, m;
	cin >> n >> m;
	vector<vector<pair<int, long long>>> edges(n);
	for (int i = 0; i < m; ++i) {
		int u, v;
		long long w;
		cin >> u >> v >> w;
		edges[u - 1].emplace_back(v - 1, w);
	}
	// Bellman-Ford Algorithm beginning from node 0
	constexpr long long INF = 1LL << 60;
	vector<long long> dist(n, INF);
	dist[0] = 0;

	for (int i = 0; i < n - 1; ++i) {
		for (int u = 0; u < n; ++u) {
			for (const auto& [v, w] : edges[u]) {
				if (dist[u] != INF && dist[u] + w < dist[v]) {
					dist[v] = dist[u] + w;
				}
			}
		}
	}

	for (int u = 0; u < n; ++u) {
		for (const auto& [v, w] : edges[u]) {
			if (dist[u] != INF && dist[u] + w < dist[v]) {
				cout << -1;
				return 0;
			}
		}
	}

	for (int i = 1; i < n; ++i) {
		if (dist[i] == INF) {
			cout << "-1\n";
		}
		else {
			cout << dist[i] << "\n";
		}
	}
}