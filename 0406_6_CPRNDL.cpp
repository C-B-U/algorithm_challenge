#include<iostream>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int f, o;
    ll first{1}, add{0}, mul{1}, t;
    cin >> f;
    for (int i = 0; i < f; i++) {
        cin >> o;
        switch (o) {
            case 0:
                cin >> t;
                add += t;
                break;
            case 1:
                cin >> t;
                mul *= t;
                add *= t;
                break;
            case 2:
                cin >> t;
                first += t;
                break;
            case 3:
                cout << first * mul + add << '\n';
                break;
        }
    }
}