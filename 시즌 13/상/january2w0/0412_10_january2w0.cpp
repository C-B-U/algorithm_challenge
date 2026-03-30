#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<int> L(N);
    for (int& len : L) cin >> len;

    int total = 1<<N;
    vector<double> dp(total);

    for (int mask = 0; mask < total; mask++) {
        for (int i = 0; i < N; i++) {
            for (int j = i+1; j < N; j++) {
                for (int k = j+1; k < N; k++) {
                    if (mask & ((1<<i) | (1<<j) | (1<<k))) continue;

                    int A = L[i], B = L[j], C = L[k];
                    if (A + B > C && C + A > B && B + C > A) {
                        int newMask = mask | (1<<i) | (1<<j) | (1<<k);
                        double p = (A + B + C)/2.0;
                        double S = sqrt(p*(p - A)*(p - B)*(p - C));
                        dp[newMask] = max(dp[newMask], dp[mask] + S);
                    }
        }   }   }
    }

    cout << setprecision(15) << *max_element(dp.begin(), dp.end());

    return 0;
}
