#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<int> a(26, 0);

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        int pow_val = 1;

        for (int j = s.length() - 1; j >= 0; j--) {
            a[s[j] - 'A'] += pow_val;
            pow_val *= 10;
        }
    }

    sort(a.begin(), a.end(), greater<int>());

    int ans = 0;
    int num = 9;

    for (int i = 0; i < 26; i++) {
        if (a[i] == 0) break;

        ans += a[i] * num;
        num--;
    }

    cout << ans << '\n';

    return 0;
}