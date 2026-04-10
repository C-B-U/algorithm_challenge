#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    if (!(cin >> N >> K)) return 0;

    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    if (K == N) {
        long long total_sum = 0;
        for (int x : a) total_sum += x;
        cout << total_sum << "\n";
        return 0;
    }
    long long current_sum = 0;
    for (int i = 0; i < K; i++) {
        current_sum += a[i];
    }

    long long max_sum = current_sum;

    for (int i = K; i < N + K - 1; i++) {
        current_sum = current_sum + a[i % N] - a[(i - K) % N];
        max_sum = max(max_sum, current_sum);
    }

    cout << max_sum << "\n";

    return 0;
}