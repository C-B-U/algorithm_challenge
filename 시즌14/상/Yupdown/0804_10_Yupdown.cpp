#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;
long long table[100000];
vector<int> edges[100000];

// 문제에서 주어지는 그래프는 항상 모든 노드가 연결되는 트리이다. (임의의 노드 사이의 경로가 하나만 존재한다는 조건에 의해)
// 그리디적인 접근 방식으로, 가장 많은 엣지가 존재하는 노드에서부터 우물을 하나씩 파면 최적해이다.
// 반대로, 엣지가 하나만 존재하는 노드에서는 가능한 한 우물을 파지 않아야 한다. 이 노드는 리프노드이다.
// 리프노드의 부모 노드는 자식의 충족 개수에 해당하는 우물을 반드시 파야 한다. 자신과 부모 노드를 제외한 다른 노드가 리프노드의 우물을 충족시키지 못하기 때문이다.
// DFS로 리프노드의 부모 노드에 우물을 파면서 남은 우물 수 갱신을 인접 노드로 전파함과 동시에 최적해를 구한다.
// 루트노드가 리프노드와 같이 엣지가 하나 존재할 수도 있는데, 이는 모든 연산을 수행하고 루트노드에 남은 필요 우물의 수를 더하면 해결할 수 있다. (자식 노드에 우물을 판 것과 동일하게 취급되기 때문에)

long long solution(int node_curr, int node_parent)
{
	long long ret = 0;
	long long maxv = 0;
	for (int node_next : edges[node_curr])
	{
		if (node_next == node_parent)
			continue;
		ret += solution(node_next, node_curr);
		maxv = max(maxv, table[node_next]);
	}
	table[node_curr] = max(table[node_curr] - maxv, 0LL);
	for (int node_next : edges[node_curr])
		table[node_next] = max(table[node_next] - maxv, 0LL);
	return ret + maxv;
}

int main()
{
	FASTIO();

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		cin >> table[i];
	for (int i = 0; i < m; ++i)
	{
		int a, b;
		cin >> a >> b;
		edges[a - 1].emplace_back(b - 1);
		edges[b - 1].emplace_back(a - 1);
	}

	cout << solution(0, -1) + table[0];
}