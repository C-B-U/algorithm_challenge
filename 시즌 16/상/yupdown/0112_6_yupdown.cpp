#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;
pair<int, int> table[200000];

int main()
{
	FASTIO();

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int t, w;
		cin >> t >> w;
		table[i] = make_pair(t, w);
	}
	sort(table, table + n, greater<>());
	int ret = 0;
	priority_queue<int> pq;
	for (int t = n, i = 0; t > 0; --t) {
		while (i < n && table[i].first >= t)
			pq.emplace(table[i++].second);
		if (!pq.empty()) {
			ret += pq.top();
			pq.pop();
		}
	}
	cout << ret;
}