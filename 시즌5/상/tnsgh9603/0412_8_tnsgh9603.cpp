#include <bits/stdc++.h>

#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
vector<int> v[1'000'001];
int dp[1'000'001][2];
bool visited[1'000'001];

void find(int now) {
    visited[now] = 1;
    dp[now][0] = 1;
    for (int& next : v[now]) {
        if (visited[next]) {
            continue;
        }
        find(next);
        dp[now][1] += dp[next][0];
        dp[now][0] += min(dp[next][1], dp[next][0]);
    }
}

int main() {
    fastio;
    int n, a, b;
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    find(1);
    cout << min(dp[1][0], dp[1][1]);
    return 0;
}
