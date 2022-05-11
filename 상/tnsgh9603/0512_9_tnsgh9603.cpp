#include <bits/stdc++.h>

#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

bool is_prime[4'000'001];

int main() {
    fastio;
    int N, sum = 0;
    cin >> N;
    vector<int> pSum;
    pSum.push_back(0);
    // Sieve of Eratosthenes
    for (int i = 2; i < sqrt(4'000'000); ++i) {
        for (int j = 2 * i; j <= 4'000'000; j += i) {
            is_prime[j] = 1;
        }
    }
    for (int i = 2; i <= 4'000'000; ++i) {
        if (!is_prime[i]) {
            sum += i;
            pSum.push_back(sum);
        }
    }
    int ans = 0, lo = 0, hi = 0;
    while (lo <= hi && hi < pSum.size()) {
        if (pSum[hi] - pSum[lo] > N) {
            ++lo;
        } else if (pSum[hi] - pSum[lo] < N) {
            ++hi;
        } else {
            ++ans;
            ++hi;
        }
    }
    cout << ans;
    return 0;
}
