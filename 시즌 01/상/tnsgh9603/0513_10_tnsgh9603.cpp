// 그동안 고생 많으셨습니다
#include <bits/stdc++.h>

#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int q[100'001], p[201][100'001];
long long a[100'001], D[100'001], E[100'001];

// Convex Hull Trick
void CHT(int k, int n) {
    if (k < 0) {
        return;
    }
    CHT(k - 1, p[k][n]);
    cout << n << " ";
}

int main() {
    fastio;
    int n, k, f, r;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        a[i] += a[i - 1];
        D[i] = -a[i] * a[i];
    }
    // DP
    for (int i = 1; i <= k; ++i) {
        q[f = r = 1] = i;
        for (int j = i + 1; j <= n; ++j) {
            while (f < r && a[q[f]] * a[j] + D[q[f]] <= a[q[f + 1]] * a[j] + D[q[f + 1]]) {
                ++f;
            }
            E[j] = a[q[f]] * a[j] + D[q[f]] - a[j] * a[j], p[i][j] = q[f];
            while (f < r &&
                   (D[q[r]] - D[q[r - 1]]) * (a[q[r - 1]] - a[j]) >= (D[j] - D[q[r - 1]]) * (a[q[r - 1]] - a[q[r]])) {
                --r;
            }
            q[++r] = j;
        }
        for (int j = i + 1; j <= n; ++j) {
            D[j] = E[j];
        }
    }
    cout << D[n] + a[n] * a[n] << "\n";
    CHT(k - 1, p[k][n]);
    return 0;
}
