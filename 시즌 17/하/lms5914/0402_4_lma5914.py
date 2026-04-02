#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long N, M;
    cin >> N >> M;

    long long total_sum = 0;
    
    for (int i = 0; i < N; i++) {
        long long A;
        cin >> A;
        total_sum += (A - 1);
    }

    if (total_sum >= M) {
        cout << "DIMI\n";
    } else {
        cout << "OUT\n";
    }

    return 0;
}