#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n - m - 1; i++) {
        cout << i << " " << i + 1 << "\n";
    }

    cout << "0 " << n - m << "\n";

    cout << (n - m - 1) << " " << n - m + 1 << "\n";

    for (int i = n - m + 2; i < n; i++) {
        cout << "0 " << i << "\n";
    }

    return 0;
}