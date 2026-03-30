#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int dp[10001];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin >> n;
    while(n--) {
        int m;
        cin >> m;

        vector<int> v;
        for (int i = 0; i < m; i++) {
            int t;
            cin >> t;
            v.push_back(t);
        }

        int obj;
        cin >> obj;

        memset(dp, 0, sizeof(dp));
        dp[0] = 1;

        for (int i = 0; i < m; i++) {
            for (int j = v[i]; j <= obj; j++) {
                dp[j] += dp[j - v[i]];
            }
        }

        cout << dp[obj] << '\n';
    }

    return 0;
}
