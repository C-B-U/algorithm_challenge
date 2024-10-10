#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> Ai;
vector<bool> visited;

void DFS(int idx)
{
	if (idx < 1 || idx > n)
		return;

	visited[idx] = true;

	DFS(idx + Ai[idx]);
	DFS(idx - Ai[idx]);
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	Ai.resize(n + 1);
	visited.resize(n + 1);
	for (int i = 1; i <= n; ++i)
		cin >> Ai[i];

	int s;
	cin >> s;
	DFS(s);

	int cnt = 0;
	for (int i = 1; i <= n; ++i)
	{
		if (visited[i])
			++cnt;
	}

	cout << cnt;
}