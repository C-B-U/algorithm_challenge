#include <bits/stdc++.h>

#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int main(d) {
    fastio;
    int N;
    cin >> N;
    vector<int> v(N);
    for (int i = 0; i < N; ++i) cin >> v[i];
    sort(v.begin(), v.end());
    if (v[0] != 1) {
        cout << 1 << '\n';
        return 0;
    }
    int total = v[0];
    for (int i = 1; i < N; ++i) {
        if (total + 1< v[i]) {
            cout << total + 1 << '\n';
            return 0;
        }
        total += v[i];
    }
    cout << total + 1 << '\n';
    return 0;
}
