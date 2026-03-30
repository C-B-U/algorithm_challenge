#include <iostream>
using namespace std;

typedef long long ll;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m;
    cin >> n >> m;
    ll t = 1;

    if (n >= m) {
        cout << 0 << '\n';
    }
    else {
        for (ll i = 1; i <= n; i++) {
            t = (t * i) % m;
        }
        cout << t << '\n';
    }


    return 0;
}