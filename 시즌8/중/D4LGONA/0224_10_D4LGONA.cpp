#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct edges
{
    int n1;
    int n2;
    int w;
};

vector<int> parent;

int find(int u) 
{
    if (parent[u] == u)
        return u;
    return parent[u] = find(parent[u]);
}

void merge(int u, int v) 
{
    parent[find(u)] = find(v);
}

int main()
{
    int V, E;
    cin >> V >> E;
    int a, b, w;
    vector<edges> v(E);

    for (int i = 0; i < E; ++i)
        cin >> v[i].n1 >> v[i].n2 >> v[i].w;

    sort(v.begin(), v.end(), [](const edges& a, const edges& b) {return a.w < b.w; });

    parent.resize(V);
    for (int i = 0; i < V; ++i)
        parent[i] = i;

    int result = 0;

    for (int i = 0; i < E; ++i) 
    {
        int n1 = v[i].n1 - 1;
        int n2 = v[i].n2 - 1;
        int weight = v[i].w;

        if (find(n1) != find(n2)) 
        {
            merge(n1, n2);
            result += weight;
        }
    }

    cout << result << endl;
}
