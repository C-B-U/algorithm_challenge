#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

inline int find_node(int* nodes, int node)
{
    return nodes[node] < 0 ? node : (nodes[node] = find_node(nodes, nodes[node]));
}

inline void union_node(int* nodes, int node0, int node1)
{
    nodes[node0] += nodes[node1];
    nodes[node1] = node0;
}

int table[100000];
vector<int> edges[100000];
int nodes[100000];

int main()
{
    FASTIO();

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> table[i];
    for (int i = 0; i < n - 1; ++i)
    {
        int a, b;
        cin >> a >> b;
        edges[a - 1].emplace_back(b - 1);
        edges[b - 1].emplace_back(a - 1);
    }

    vector<pair<long long, int>> seq;
    for (int i = 0; i < n; ++i)
        seq.emplace_back(-table[i], i);
    sort(seq.begin(), seq.end());
    memset(nodes, -1, sizeof(nodes));

    long long mul = 0;
    long long opc = 0;
    // iterate nodes from the highest weight to the lowest weight
    for (int i = 0; i < n; ++i)
    {
        if (i > 0)
            opc -= mul * (seq[i - 1].first - seq[i].first);
        int node_curr = seq[i].second;
        for (int node_next : edges[node_curr])
        {
            if (table[node_curr] > table[node_next])
                continue;
            int pc = find_node(nodes, node_curr);
            int pn = find_node(nodes, node_next);
            if (pc != pn)
            {
                union_node(nodes, pc, pn);
                mul--;
            }
        }
        mul++;
    }
    opc -= mul * seq[n - 1].first;
    cout << opc;
}