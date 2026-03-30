#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int N, maxLevel;

int board[102][102];
bool visited[102][102];

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

void BFS(int sy, int sx, int h)
{
	queue<pair<int, int>> q;
	q.push({ sy, sx });
	visited[sy][sx] = true;

	while (!q.empty())
	{
		auto [curY, curX] = q.front();
		q.pop();

		for (int dir = 0; dir < 4; ++dir)
		{
			int newY = curY + dy[dir];
			int newX = curX + dx[dir];

			if (newY < 0 || newX < 0 || newY >= N || newX >= N)
				continue;

			if (visited[newY][newX])
				continue;

			if (board[newY][newX] <= h)
				continue;

			visited[newY][newX] = true;
			q.push({ newY, newX });
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;

	for (int y = 0; y < N; ++y)
	{
		for (int x = 0; x < N; ++x)
		{
			cin >> board[y][x];
			maxLevel = max(maxLevel, board[y][x]);
		}
	}

	// 0부터 maxLevel - 1까지 반복
	int ans = 0;
	for (int h = 0; h < maxLevel; ++h)
	{
		fill(&visited[0][0], &visited[0][0] + 102 * 102, false);

		int safeCount = 0;
		for (int y = 0; y < N; ++y)
		{
			for (int x = 0; x < N; ++x)
			{
				if (!visited[y][x] && board[y][x] > h)
				{
					BFS(y, x, h);
					++safeCount;
				}
			}
		}

		ans = max(ans, safeCount);
	}

	cout << ans;
}