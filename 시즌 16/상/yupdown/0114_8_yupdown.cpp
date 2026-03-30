#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;
int nodes[200000];
int table[200000];
vector<int> edges[200000];
bool ret[200000];
bool memo[200000];

inline int find_node(int* nodes, int node)
{
    return nodes[node] < 0 ? node : (nodes[node] = find_node(nodes, nodes[node]));
}

inline void union_node(int* nodes, int node0, int node1)
{
    nodes[node0] += nodes[node1];
    nodes[node1] = node0;
}

int main()
{
    FASTIO();
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        edges[u - 1].push_back(v - 1);
        edges[v - 1].push_back(u - 1);
    }
    for (int i = 0; i < n; ++i)
        cin >> table[i];
    memset(nodes, -1, sizeof(nodes));
    int cnt = 0;
    for (int i = n - 1; i >= 0; --i) {
        int node = table[i] - 1;
        cnt++;
        for (int v : edges[node]) {
            if (!memo[v])
                continue;
            int root_u = find_node(nodes, node);
            int root_v = find_node(nodes, v);
            if (root_u != root_v) {
                union_node(nodes, root_u, root_v);
                cnt--;
            }
        }
        ret[i] = cnt == 1;
        memo[node] = true;
    }
    for (int i = 0; i < n; ++i)
        cout << (ret[i] ? "CONNECT\n" : "DISCONNECT\n");
    cout << "DISCONNECT\n";
}