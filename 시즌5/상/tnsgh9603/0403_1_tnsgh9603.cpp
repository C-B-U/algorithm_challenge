#include <bits/stdc++.h>

#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int main() {
    fastio;
    int n;
    cin >> n;
    int cnt = 0;
    int l = 1, r = n, Q, A;
    while (l + 1 < r) {
        ++cnt;
        Q = (l + r) / 2;
        cout << "? " << Q << endl;
        cin >> A;
        if (Q - A > A) {
            r = Q;
        } else if (Q - A == A) {
            cout << "! " << Q << endl;
            return 0;
        } else {
            l = Q;
        }
    }
    return 0;
}
