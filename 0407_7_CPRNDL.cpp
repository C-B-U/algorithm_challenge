#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string a, b;
    cin >> a >> b;
    
    while (a.length() < b.length()) {
        if (b.back() == 'A') {
            b.pop_back();
        }
        else {
            b.pop_back();
            reverse(b.begin(), b.end());
        }
    }

    if (a == b) cout << 1 << '\n';
    else cout << 0 << '\n';

    return 0;
}