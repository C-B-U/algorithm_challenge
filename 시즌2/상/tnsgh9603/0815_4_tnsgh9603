#include <bits/stdc++.h>

#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
bool visited[100'001];
vector<pair<int, int>> g[100'001];
int mx = 0, k;

void dfs(int s, int x) {
    visited[s] = 1;
    if (mx < x) {
        mx = x;
        k = s;
    }
    for (auto[e, w]: g[s]) {
        if (!visited[e]) {
            dfs(e, x + w);
        }
    }
    visited[s] = 0;
}

int main() {
    fastio;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int s, e, w;
        cin >> s;
        while (cin >> e && ~e) {
            cin >> w;
            g[s].push_back({e, w});
        }
    }
    dfs(1, 0);
    dfs(k, 0);
    cout << mx;
    return 0;
}
