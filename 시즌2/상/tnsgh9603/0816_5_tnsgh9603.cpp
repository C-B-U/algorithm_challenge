#include <bits/stdc++.h>

#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
char board[51][51];
int dp[51][51], n, m;
bool visited[51][51];

int dfs(int cy, int cx) {
    if (cy < 0 || cx < 0 || cx >= m || cy >= n || board[cy][cx] == 'H') {
        return 0;
    }
    if (visited[cy][cx]) {
        cout << -1;
        exit(0);
    }
    int &cache = dp[cy][cx];
    if (cache != -1) {
        return cache;
    }
    visited[cy][cx] = 1;
    cache = 0;
    for (int dir = 0; dir < 4; ++dir) {
        int nx = cx + ("2011"[dir] - '1') * (board[cy][cx] - '0'), ny =
                cy + ("1120"[dir] - '1') * (board[cy][cx] - '0');
        cache = max(cache, dfs(ny, nx) + 1);
    }
    visited[cy][cx] = 0;
    return cache;
}

int main() {
    cin >> n >> m;
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> board[i][j];
        }
    }
    cout << dfs(0, 0);
    return 0;
}
