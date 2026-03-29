#include<iostream>
using namespace std;
int* set;
void init(int n) {
	set = new int[n + 1]; for (int i = 0; i < n + 1; i++)set[i] = i;
}
int get_Parent(int x) {
	if (set[x] == x)return x;
	else return set[x] = get_Parent(set[x]);
}
bool check_Parent(int a, int b) {
	return (get_Parent(a) == get_Parent(b) ? true : false);
}
void Union(int a, int b) {
	a = get_Parent(a), b = get_Parent(b);
	if (a < b)set[b] = a;
	else set[a] = b;
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n, m; cin >> n>> m; init(n);
	for (int i = 0,cmd,a,b; i < m; i++) {
		cin >> cmd >> a >> b;
		if (cmd) { cout << (check_Parent(a, b) ? "YES" : "NO")<<'\n'; }
		else Union(a, b);
	}
	return 0;
}
