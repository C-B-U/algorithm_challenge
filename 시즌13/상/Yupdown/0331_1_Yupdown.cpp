#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;
int itov[200];
map<int, int> vtoi;
vector<int> edges[200];
int memo[200][2];

// 문제 이해가 어렵다. 사이클이 존재할 수도 있는 무향 그래프에서 서로 인접하지 않게 노드를 선택했을 때 나오는 최댓값을 구하는 것인 줄 알았다.
// 제시된 조건을 잘, 아주 잘 읽다보면 해당 자료구조는 사이클이 없는 무향 그래프, 즉 트리라는 것을 알 수 있다.
// 그러면 루트 노드를 임의로 하나 잡고, 그 노드를 포함하거나 포함하지 않는 경우로 나누어 서브트리에 대한 최적해를 구할 수 있다.
// 노드가 포함된다는 "상태" 때문에 경우의 수가 기하급수적으로 늘어나므로, 꼭 메모이제이션을 사용하여 TLE를 피해야 한다.

int solution(int node_parent, int node, bool flag)
{
	if (memo[node][flag] >= 0)
		return memo[node][flag];
	int ret = 0;
	for (int node_next : edges[node])
	{
		if (node_next != node_parent)
			ret += solution(node, node_next, !flag);
	}
	return memo[node][flag] = flag ? max(ret + itov[node], solution(node_parent, node, false)) : ret;
}

int main()
{
	FASTIO();

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
	{
		int v;
		cin >> v;
		itov[i] = v;
		vtoi[v] = i;
	}
	vector<int> delta;
	for (int i = 0; i < m; ++i)
		cin >> delta.emplace_back();
	for (const auto& [v, i] : vtoi)
	{
		for (int d : delta)
		{
			if (vtoi.find(v + d) != vtoi.end())
				edges[i].push_back(vtoi[v + d]);
			if (vtoi.find(v - d) != vtoi.end())
				edges[i].push_back(vtoi[v - d]);
		}
	}

	memset(memo, -1, sizeof(memo));
	cout << solution(-1, 0, true);
}