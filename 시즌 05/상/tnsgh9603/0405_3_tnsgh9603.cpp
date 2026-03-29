#include <bits/stdc++.h>
 
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int parent[1001];
void init() {
	for(int i = 1; i <= 1000; ++i) {
		parent[i] = i;
	}
}
int find_parent(int x) {
	return parent[x] == x ? x : find_parent(parent[x]);
}
 
void union_parent(int x, int y) {
    x = find_parent(x);
    y = find_parent(y);
    if (x != y) {
    	parent[y] = x;
    }
}
 
int main() {
    fastio;
    int n, m;
    cin >> n >> m;
    init();
    vector<pair<int,pair<int,int>>> v; 
    for(int i = 1; i <= m; ++i) {
    	int a, b, c;
    	cin >> a >> b >> c;
    	v.push_back({c, {a, b}});
    }
    sort(v.begin(), v.end());
    vector<int> ans;
    int sum = 0;
    for(int i = 0; i < m; ++i) {
    	int from = v[i].second.first, to = v[i].second.second;
    	if(find_parent(from) != find_parent(to)) {
    		union_parent(from, to);
    		ans.push_back(i);
    		sum += v[i].first;
    	}
    	if(ans.size() == n - 1) {
    		break;
    	}
    }
    cout << sum;
    return 0;
}
