#include <bits/stdc++.h>

#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

vector<tuple<int, int, int>> v;
int arr[2001];

int main() {
    fastio;
    int n, c, m;
    cin >> n >> c >> m;
    for (int i = 0; i < m; ++i) {
        int q, w, e;
        cin >> q >> w >> e;
        v.push_back({w, q, e});
    }
    sort(v.begin(), v.end());
    int sum = 0;
    for (int i = 0; i < v.size(); ++i) {
        auto& [from, to, size] = v[i];
        int max_truck = *max_element(arr + from, arr + to);
        int capacity = min(size, c - max_truck);
        for (int j = from; j < to; ++j) {
            arr[j] += capacity;
        }
        sum += capacity;
    }
    cout << sum;
    return 0;
}
