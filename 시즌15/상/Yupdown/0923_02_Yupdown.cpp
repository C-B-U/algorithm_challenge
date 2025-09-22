#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

vector<int> up_edge[512];
vector<int> down_edge[512];

bool solution(int i)
{
	bool memo[512];
	memset(memo, 0, sizeof(memo));
	memo[i] = true;
	stack<pair<int, bool>> st;
	stack<int> cand;
	st.emplace(i, true);
	st.emplace(i, false);
	while (!st.empty())
	{
		auto [node, mode] = st.top();
		st.pop();
		for (auto node_next : (mode ? up_edge[node] : down_edge[node]))
		{
			if (memo[node_next])
				continue;
			memo[node_next] = true;
			st.emplace(node_next, mode);
		}
		for (auto node_next : (mode ? down_edge[node] : up_edge[node]))
		{
			if (memo[node_next])
				continue;
			cand.emplace(node_next);
		}
	}
	while (!cand.empty())
	{
		auto node = cand.top();
		cand.pop();
		if (!memo[node])
			return false;
	}
	return true;
}

int main()
{
	FASTIO();

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; ++i)
	{
		int a, b;
		cin >> a >> b;
		up_edge[b].emplace_back(a);
		down_edge[a].emplace_back(b);
	}
	bool memo[512];
	memset(memo, 0, sizeof(memo));
	stack<int> dfs;
	dfs.emplace(1);
	while (!dfs.empty())
	{
		auto node = dfs.top();
		dfs.pop();
		for (auto node_next : up_edge[node])
		{
			if (memo[node_next])
				continue;
			memo[node_next] = true;
			dfs.emplace(node_next);
		}
		for (auto node_next : down_edge[node])
		{
			if (memo[node_next])
				continue;
			memo[node_next] = true;
			dfs.emplace(node_next);
		}
	}
	int ret = 0;
	if (accumulate(memo + 1, memo + n + 1, 0) == n)
	{
		for (int i = 0; i < n; ++i)
			ret += solution(i + 1);
	}
	cout << ret;
}