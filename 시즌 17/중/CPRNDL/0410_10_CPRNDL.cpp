#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    string water;
    cin >> water;

    int ch = count(water.begin(), water.end(), 'H');
    int co = count(water.begin(), water.end(), 'O');

    if (ch != co * 2) {
        cout << "mix\n";
        return 0;
    }
    
    int ph{0}, po{0};

    for (char c : water) {
        if (c == 'H') ++ph;
        else ++po;
        
        if (ph < po) {
            cout << "mix\n";
            return 0;
        }
    }

    ph = 0; po = 0;

    for (int i = n - 1; i >= 0; --i) {
        if (water[i] == 'H') ++ph;
        else ++po;

        if (ph < po) {
            cout << "mix\n";
            return 0;
        }
    }

    cout << "pure\n";

    return 0;
}