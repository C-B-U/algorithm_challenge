#include <iostream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    string s;
    cin >> s;

    if (n % 3 != 0) {
        cout << "mix\n";
        return 0;
    }

    int h_count = 0, o_count = 0;
    for (char c : s) {
        if (c == 'H') h_count++;
        else o_count++;
    }

    if (h_count != 2 * (n / 3) || o_count != n / 3) {
        cout << "mix\n";
        return 0;
    }

    int current_h = 0, current_o = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'H') current_h++;
        else current_o++;

        if (current_h < current_o) {
            cout << "mix\n";
            return 0;
        }
    }

    current_h = 0;
    current_o = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == 'H') current_h++;
        else current_o++;

        if (current_h < current_o) {
            cout << "mix\n";
            return 0;
        }
    }

    cout << "pure\n";

    return 0;
}