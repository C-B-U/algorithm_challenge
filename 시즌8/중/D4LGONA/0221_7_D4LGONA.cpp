#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int>> v;

int find(int node) 
{
    if (v[node].second == node) return node;
    return v[node].second = find(v[node].second);
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m, a, b;
    cin >> n >> m;

    v.assign(n + 1, { 0, 0 });
    for (int i = 1; i <= n; ++i)
        v[i] = { i, i };

    for (int i = 0; i < m; ++i) 
    {
        cin >> n >> a >> b;

        if (n == 0) 
        {
            int rootA = find(a);
            int rootB = find(b);
            if (rootA != rootB) v[rootB].second = rootA;
        }
        else {
            if (find(a) == find(b)) cout << "YES\n";
            else cout << "NO\n";
        }
    }
}