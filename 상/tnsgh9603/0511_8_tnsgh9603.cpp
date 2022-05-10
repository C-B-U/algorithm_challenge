#include <bits/stdc++.h>

#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int parent[501];
bool treecheck[501];

int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}
void uni(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y || !treecheck[x] || !treecheck[y]) {
        treecheck[x] = false;
        treecheck[y] = false;
    }
    parent[y] = x;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int TC = 0;
    while (1) {

        int N, M, ans = 0;
        cin >> N >> M;
        if (N == 0 && M == 0) return 0;
        memset(treecheck, true, sizeof(treecheck));
        for (int i = 1; i <= N; i++) {
            parent[i] = i;
        }
        int from, to;
        for (int i = 0; i < M; i++) {
            cin >> from >> to;
            if (from != to) {
                uni(min(to, from), max(to, from));
            }
        }
        for (int i = 1; i <= N; i++) {
            int first = find(i);
            if (treecheck[first]) {
                treecheck[first] = false;
                ans++;
            }
        }


        cout << "Case " << ++TC << ": ";
        if (ans == 0)cout << "No trees.\n";
        else if (ans == 1)cout << "There is one tree.\n";
        else cout << "A forest of " << ans << " trees.\n";
    }
}
