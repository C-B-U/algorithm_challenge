#include <iostream>
#include<algorithm>

// 집합의 표현

using namespace std;
int parent[1000001];

int find(int x) {
	if (parent[x] == x)
		return x;
	parent[x] = find(parent[x]);
	return parent[x];
}

void merge(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y) return;
	parent[y] = x;
}

int main() {
	// 표준 입출력과 버퍼 사이의 동기화를 비활성화
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < 1000000; ++i)
		parent[i + 1] = i + 1;

	for (int i = 0; i < m; ++i) {
		int a, b, c;
		cin >> c >> a >> b;
		if (c == 0) {
			merge(a, b);
		}
		else {
			if (find(a) == find(b))
				cout << "YES\n";	// 시간 초과 방지
			else
				cout << "NO\n";
		}
	}
}