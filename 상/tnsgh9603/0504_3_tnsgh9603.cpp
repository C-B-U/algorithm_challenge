#include <bits/stdc++.h>

#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int n, del;
vector<int> v[51];

int dfs(int now) {
    int sum = 0;
    for (int i = 0; i < v[now].size(); ++i) {
        if (v[now][i] != del) {
            sum += dfs(v[now][i]);
        }
    }
    return sum ? sum : 1;
}

int main() {
    fastio;
    cin >> n;
    int m, root;
    for (int i = 0; i < n; ++i) {
        cin >> m;
        if (m != -1) {
            v[m].push_back(i);
        } else {
            root = i;
        }
    }
    cin >> del;
    cout << (del != root ? dfs(root) : 0);
    return 0;
}
