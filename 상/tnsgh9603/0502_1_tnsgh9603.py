#include <bits/stdc++.h>

#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int main() {
    fastio;
    int n;
    cin >> n;
    vector<long long> v(6);
    for (int i = 0; i < 6; ++i) {
        cin >> v[i];
    }
    if (n == 1) {
        cout << accumulate(v.begin(), v.end(), 0) - *max_element(v.begin(), v.end());
    } else {
        v[0] = min(v[0], v[5]);
        v[1] = min(v[1], v[4]);
        v[2] = min(v[2], v[3]);
        sort(v.begin(), v.begin() + 3);
        cout << ((v[0] + v[1]) * 4 + v[0] * 4 * (n - 2)) * (n - 1) + (v[0] + v[1] + v[2]) * 4 +
                (v[0] + v[1]) * 4 * (n - 2) + v[0] * (n - 2) * (n - 2);
    }
    return 0;
}
