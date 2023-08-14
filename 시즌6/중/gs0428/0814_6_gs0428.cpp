#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <deque>
#include <set>
#include <string>
#include <stack>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<pair<double, int>> v;
    for (int i = 0; i < n; i++) {
        double x, y, l;
        cin >> x >> y >> l;
        double distance = sqrt(pow(x, 2) + pow(y, 2));
        v.push_back(make_pair(distance / l, i + 1));
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++) {
        cout << v[i].second << "\n";
    }

    return 0;
}