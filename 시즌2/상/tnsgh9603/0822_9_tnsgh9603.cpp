#include <bits/stdc++.h>

#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
typedef long long ll;
ll k, n, x, a[61];
priority_queue<pair<ll, int>> Q;
set<ll> S;

int main() {
    fastio;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    cin >> k;
    sort(a, a + n + 1);
    for (int i = 1; i <= n; ++i) {
        for (ll p = min(a[i] - a[i - 1] - 1, k); p; --p) {
            Q.push({-p * (a[i] - a[i - 1] - p), -a[i - 1] - p});
            Q.push({-p * (a[i] - a[i - 1] - p), -a[i] + p});
        }
        Q.push({-1, -a[i]});
    }
    for (; k && Q.size(); Q.pop()) {
        x = -Q.top().second;
        if (S.find(x) == S.end()) {
            S.insert(x);
            cout << x << ' ';
            --k;
        }
    }
    for (int i = 1; i <= k; ++i) {
        cout << a[n] + i << ' ';
    }
    return 0;
}
