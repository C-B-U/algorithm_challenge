#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

const int MAX{ 10000 + 1 };

int vt, e, result;
int parent[MAX];
vector<pair<int, pair<int, int>>> v;

void solution();
int find(const int& x);
void Union(int x, int y);
bool sameParent(int x, int y);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solution();

	cout << result << endl;
}

void solution()
{
	// 입력
	cin >> vt >> e;
	for (int i = 0; i < e; ++i) {
		int start, end, cost;
		cin >> start >> end >> cost;

		v.push_back(make_pair(cost, make_pair(start, end)));

	}

	sort(v.begin(), v.end());

	// 알고리즘
	for (int i = 1; i <= vt; ++i) {
		parent[i] = i;
	}

	for (int i = 0; i < e; ++i) {
		if (sameParent(v[i].second.first, v[i].second.second) == false) {
			Union(v[i].second.first, v[i].second.second);
			result = result + v[i].first;
		}
	}
}

int find(const int& x)
{
	if (parent[x] == x) return x;
	else {
		parent[x] = find(parent[x]);
		return parent[x];
	}
}

void Union(int x, int y)
{
	x = find(x);
	y = find(y);

	if (x != y) parent[y] = x;
}

bool sameParent(int x, int y)
{
	x = find(x);
	y = find(y);

	if (x == y) return true;
	else return false;
}
