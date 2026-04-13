#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, n, p, a, b;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n >> p;
        for (int j = 0; j < p; j++) {
            cin >> a >> b;
        }
        cout << n - 1 << '\n';
    }

    return 0;
}