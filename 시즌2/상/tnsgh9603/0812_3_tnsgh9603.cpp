#include <bits/stdc++.h>

#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int n, mx;
vector<vector<int>> V;

vector<vector<int>> r(vector<vector<int>> v, int cnt) {
    if (!cnt) {
        return v;
    }
    vector<vector<int>> temp(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            temp[i][j] = v[n - j - 1][i];
        }
    }
    return r(temp, cnt - 1);
}

vector<vector<int>> p(vector<vector<int>> v) {
    vector<vector<int>> temp(n, vector<int>());
    for (int i = 0; i < n; ++i) {
        int flag = 0;
        for (int j = 0; j < n; ++j) {
            if (v[i][j]) {
                if (flag) {
                    if (flag == v[i][j]) {
                        temp[i].push_back(flag * 2);
                        flag = 0;
                    } else {
                        temp[i].push_back(flag);
                        flag = v[i][j];
                    }
                } else {
                    flag = v[i][j];
                }
            }
        }
        if (flag) {
            temp[i].push_back(flag);
        }
    }
    for (int i = 0; i < n; ++i) {
        while (temp[i].size() < n) {
            temp[i].push_back(0);
        }
    }
    return temp;
}

void f(int cnt, vector<vector<int>> v) {
    if (cnt == 5) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                mx = max(mx, v[i][j]);
            }
        }
        return;
    }
    for (int i = 0; i < 4; ++i) {
        f(cnt + 1, p(r(v, i)));
    }
}

int main() {
    fastio;
    cin >> n;
    V.resize(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> V[i][j];
        }
    }
    f(0, V);
    cout << mx;
    return 0;
}
