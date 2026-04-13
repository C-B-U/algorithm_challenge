#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, k, x;
    cin >> n >> k >> x;

    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<long long> p(n + 1, 0);
    vector<long long> suf(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        p[i] = p[i - 1] + a[i - 1];
        suf[i] = suf[i - 1] + a[n - i];
    }

    long long min_w = 1e18;

    for (long long u = 0; u < n; u++) {
        long long earned_before = p[u] * x;
        long long rem = k - earned_before;
        long long v = 0;

        if (rem > 0) {
            auto it = lower_bound(suf.begin(), suf.end(), rem);

            if (it == suf.end()) continue;

            v = distance(suf.begin(), it);
        }

        if (u + v <= n - 1) {
            min_w = min(min_w, u + v);
        }
    }

    if (min_w <= n - 1) {
        cout << n - min_w << "\n";
    }
    else {
        cout << -1 << "\n";
    }

    return 0;
}