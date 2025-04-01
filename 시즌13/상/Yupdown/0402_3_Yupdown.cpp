#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

// - 왜 인접한 층으로 이동하는데 하필 100초가 걸릴까?
// - 왜 호의 개수(W)의 최대값이 100일까?
// > 한번 올라오면 다시 내려올 일이 무조건 없을 것이라는 것을 시사한다.

// 1층에서부터 올라가면서 해당 층의 방문하고자 하는 방을 모두 방문한다.
// 해당 층에서 방문하고자 하는 방들을 왼쪽에서 오른쪽으로, 또는 왼쪽에서 오른쪽으로 방문하는것이 가장 빠를 것이다.
// 각각의 층에서 방문하는 방향만 잘 설정하면 최적해가 나온다.

// std::pair<int, int> room_range[x] x+1번째 층에서 방문하고자 하는 (가장 왼쪽 방, 가장 오른쪽 방) - second가 0일 경우 방문할 방 없음
// solution(h, x, y, c) -> x+1번째 층 y번째 호에서 c(0: 왼쪽, 1: 오른쪽) 방향으로 방문을 수행하였을 때, 앞으로 걸릴 시간의 최소값 반환
// memo[x][c] -> x+1번째 층에서 c(0: 왼쪽, 1: 오른쪽) 방향으로 방문을 수행하였을 때, 앞으로 걸릴 시간의 최소값을 메모이제이션

// 다음 층으로 넘어갈 때의 가중치는 "다음 층에서 방문하는 동안 걸린 시간 + 다음 층에서 방문을 시작할 방에 가는 동안 걸린 시간"
// 다음 층에 방문하고자 할 방이 없으면 가중치를 100으로 설정하고 y와 c를 유지한 채 그 다음 층으로 넘어간다.

// 시간복잡도 O(N + H)

pair<int, int> room_range[1000];
int memo[1000][2];

int solution(int h, int x, int y, int c)
{
	if (x == h)
		return -100;
	if (memo[x][c] < 0xF0F0F0F0)
		return memo[x][c];
	if (room_range[x].second == 0)
		return memo[x][c] = solution(h, x + 1, y, c) + 100;
	return memo[x][c] = min(
		solution(h, x + 1, room_range[x].first, 0) + abs(room_range[x].second - y),
		solution(h, x + 1, room_range[x].second, 1) + abs(room_range[x].first - y))
		+ 100 + room_range[x].second - room_range[x].first;
}

int main()
{
	FASTIO();

	int n, h, w;
	cin >> n >> h >> w;
	memset(memo, 0xF0, sizeof(memo));
	room_range[0] = make_pair(1, 1);
	for (int i = 1; i < h; ++i)
		room_range[i] = make_pair(w, 0);
	int xmax = 0;
	for (int i = 0; i < n; ++i)
	{
		int x, y;
		cin >> x >> y;
		xmax = max(xmax, x);
		room_range[x - 1].first = min(room_range[x - 1].first, y);
		room_range[x - 1].second = max(room_range[x - 1].second, y);
	}
	cout << solution(xmax, 0, 1, 0);
}