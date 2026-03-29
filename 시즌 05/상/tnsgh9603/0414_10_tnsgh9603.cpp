#include <bits/stdc++.h>

#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
vector<int> men, women;
int dp[1001][1001];

int main() {
    fastio;
    int n, m, temp;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> temp;
        men.push_back(temp);
    }
    for (int j = 0; j < m; ++j) {
        cin >> temp;
        women.push_back(temp);
    }
    sort(men.begin(), men.end());
    sort(women.begin(), women.end());
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (i == j) {
                dp[i][j] = dp[i - 1][j - 1] + abs(men[i - 1] - women[j - 1]);
            }
            else if (i > j) {
                dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - 1] + abs(men[i - 1] - women[j - 1]));
            }
            else if (j > i) {
                dp[i][j] = min(dp[i][j - 1], dp[i - 1][j - 1] + abs(men[i - 1] - women[j - 1]));
            }
        }
    }
    cout << dp[n][m];
    return 0;
}
