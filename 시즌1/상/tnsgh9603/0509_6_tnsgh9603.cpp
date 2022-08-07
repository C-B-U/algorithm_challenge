#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int parent[51], n, m, k;
vector<int> know;
vector<vector<int>> vec(50);
void init() {
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}
}
int get_parent(int x) {
	if (parent[x] == x) {
		return x;
	}
	return x = get_parent(parent[x]);
}
void union_parent(int x, int y) {
	x = get_parent(x);
	y = get_parent(y);
	parent[x] = y;
}
int main() {
	fastio;
	cin >> n >> m >> k;
	while (k--) {
		int t;
		cin >> t;
		know.push_back(t);
	}
	init();
	for (int i = 0; i < m; i++) {
		int p;
		cin >> p;
		int num, prev;
		for (int j = 0; j < p; j++) {
			if (j >= 1) {
				prev = num;
				cin >> num;
				union_parent(prev, num);
			}
			else {
				cin >> num;
			}
			vec[i].push_back(num);
		}
	}
	int cnt = 0;
	for (auto i : vec) {
		bool flag = 0;
		for (auto who : i) {
			if (flag) {
				break;
			}
			for (auto know_ : know) {
				if (get_parent(who) == get_parent(know_)) {
					flag = 1;
					break;
				}
			}
		}
		if (flag) {
			cnt++;
		}
	}
	cout << m - cnt;
	return 0;
}
