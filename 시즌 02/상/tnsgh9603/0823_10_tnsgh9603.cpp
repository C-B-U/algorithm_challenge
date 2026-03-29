#include <bits/stdc++.h>

#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
char board[1001][1001];
bool visited[1001][1001][11][2];
int n, m, k;

bool OOB(int x, int y) {
    return 1 <= x and x <= n and 1 <= y and y <= m;
}

int main() {
    fastio;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> board[i][j];
        }
    }
    queue<tuple<int, int, int, int, bool>> q;
    q.push({1, 1, 0, 1, 0});
    visited[1][1][0][0] = 1;
    while (!q.empty()) {
        auto[x, y, cnt, time, is_night] = q.front();
        if (x == n and y == m) {
            cout << time;
            return 0;
        }
        q.pop();
        for (int i = 0; i < 5; ++i) {
            int nx = x + "01211"[i] - '1';
            int ny = y + "12101"[i] - '1';
            if (OOB(nx, ny)) {
                // 부술 수 있을 때
                if (!is_night and board[nx][ny] == '1' and cnt + 1 <= k and !visited[nx][ny][cnt + 1][1]) {
                    visited[nx][ny][cnt + 1][1] = 1;
                    q.push({nx, ny, cnt + 1, time + 1, 1});
                }
                    // 벽이 아닐 때
                else if ((board[nx][ny] == '0' || (nx == x and ny == y)) and !visited[nx][ny][cnt][!is_night]) {
                    visited[nx][ny][cnt][!is_night] = 1;
                    q.push({nx, ny, cnt, time + 1, !is_night});
                }
            }
        }
    }
    cout << -1;
    return 0;
}
