#include <bits/stdc++.h>

#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int D, P, T = 1, M = -1;

void f(int n, int a, int j) {
    if (a >= T) {
        return;
    }
    if (P == n) {
        M = max(M, a);
        return;
    }
    for (int i = j; i > 1; --i) {
        f(n + 1, a * i, i);
    }
}

int main() {
    fastio;
    cin >> D >> P;
    while (D--) {
        T *= 10;
    }
    f(0, 1, 9);
    cout << M;
}
