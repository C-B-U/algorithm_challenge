#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct state { int teams; long sum; };

int main()
{
    int i, j, N;
    cin >> N;

    vector<pair<int, int>> a(N);
    
    for (i = 0; i < N; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }

    sort(a.begin(), a.end());

    vector<state> dp(N+1);
    vector<bool> skip(N+1, true);

    for (i = 4; i <= N; i++)
    {
        dp[i] = dp[i-1];

        state cand = { dp[i-4].teams + 1, dp[i-4].sum + (a[i-1].first - a[i-4].first) };
        if (cand.teams > dp[i].teams || (cand.teams == dp[i].teams && cand.sum < dp[i].sum)) {
            dp[i] = cand;
            skip[i] = false;
        }
    }

    vector<bool> used(N, false);

    for (i = N; i > 0; i--) {
        if (!skip[i]) {
            for (j = i-4; j < i; j++) used[j] = true;
            i -= 3;
        }
    }

    cout << dp[N].sum << '\n';

    for (i = 0; i < N; i++) {
        if (!used[i]) cout << a[i].second << '\n';
    }

    return 0;
}
