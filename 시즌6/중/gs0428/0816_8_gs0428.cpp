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
    int rectR, rectC;
    vector<pair<int, int>> v;
    set<pair<long long int, long long int>> s;
    cin >> n >> rectR >> rectC;
    for (int i = 0; i < n; i++) {
        long long int x, y;
        cin >> x >> y;
        v.push_back(make_pair(x, y));
        s.insert({x, y});
    }
    int a, b;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        a = v[i].first;
        b = v[i].second;

        if (s.find({ a + rectR,b }) == s.end())continue;
        if (s.find({ a,b + rectC }) == s.end())continue;
        if (s.find({ a + rectR,b + rectC }) == s.end())continue;
        ans++;
    }

    cout << ans;

    return 0;
}