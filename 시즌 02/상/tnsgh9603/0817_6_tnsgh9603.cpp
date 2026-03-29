#include <bits/stdc++.h>

#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int parent[100'001];
int ans = 0;
int find(int x) {
	if (parent[x] == x) {
		return x;
	}
	return parent[x] = find(parent[x]);
}
void merge(int u, int v) {
	u = find(u);
	v = find(v);
	parent[u] = v;
}
int main() {
	int G, P, g_i;
	cin >> G >> P;
	
	for (int i = 1; i <= G; i++) {
		parent[i] = i;
	}
	for (int i = 1; i <= P; i++) {
		cin >> g_i;
		int docking = find(g_i);
		if (docking != 0) {
			merge(docking, docking - 1);
			ans++;
		}
		else {
			break;
		}
	}
	cout << ans;
	return 0;
}
