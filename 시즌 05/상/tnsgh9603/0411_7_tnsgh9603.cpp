#include <bits/stdc++.h>

#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
typedef long long ll;
ll cnt[1001];
int main() {
    fastio;
    int n, m, x;
    ll sum = 0, ans = 0;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        sum += x;
        ++cnt[sum % m];
    }
    for (int i = 0; i <= 1000; ++i) {
        ans += cnt[i] * (cnt[i] - 1) / 2;
    }
    cout << cnt[0] + ans;
    return 0;
}
