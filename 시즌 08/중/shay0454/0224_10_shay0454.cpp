#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int* table;
typedef struct Edge {
	int a, b;
	int value;
};
istream& operator >>(istream& is, Edge& e) {
	is >> e.a >> e.b >> e.value; return is;
}
bool compare(Edge a, Edge b) { return a.value > b.value; }
int get_Parent(int x) {
	if (table[x] == x)return x;
	else return table[x] = get_Parent(table[x]);
}
void Union(int a, int b) {
	a = get_Parent(a), b = get_Parent(b);
	if (a > b)table[a] = b;
	else table[b] = a;
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	vector<Edge> v; Edge x;
	int vertex, edge,answer=0; cin >> vertex >> edge;
	table = new int[vertex + 1]; for (int i = 0; i <= vertex; i++)table[i] = i;
	for (int i = 0; i < edge; i++) { cin >> x; v.push_back(x); }
	sort(v.begin(), v.end(), compare);
	while (!v.empty()) {
		x = v.back(); v.pop_back();
		if (get_Parent(x.a) != get_Parent(x.b)) {
			Union(x.a, x.b); answer += x.value;
		}
	}
	cout << answer;
	return 0;
}
