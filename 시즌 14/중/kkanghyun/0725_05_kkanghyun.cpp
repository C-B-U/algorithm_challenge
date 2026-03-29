#include <iostream>
#include <algorithm>
using namespace std;

// 극이 다르다면, 반대 방향으로 회전
// 극이 같다면, 회전 X

string gear[5];	// N극(0), S극(1)

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	for (int i = 1; i <= 4; ++i)
		cin >> gear[i];

	int K;	// 회전 횟수
	cin >> K;

	int idx;
	int dir;	// 시계(1), 반시계(-1)
	int rot[5];	// 회전 방향 Left(-1), stop(0), right(1)
	while (K--)
	{
		cin >> idx >> dir;

		rot[idx] = dir;

		bool enable = true;
		int d = -dir;	// 회전 방향

		// 오른쪽 바퀴
		for (int i = idx + 1; i <= 4; ++i)
		{
			if (!enable)
			{
				rot[i] = 0;
				continue;
			}

			// 현재 바퀴 9시 vs 왼쪽 바퀴 3시
			if (gear[i][6] == gear[i - 1][2])
			{
				enable = false;
				rot[i] = 0;
			}
			else
			{
				rot[i] = d;
				d = -d;
			}
		}

		enable = true;
		d = -dir;	// 회전 방향

		// 왼쪽 바퀴
		for (int i = idx - 1; i >= 1; --i)
		{
			if (!enable)
			{
				rot[i] = 0;
				continue;
			}

			// 현재 바퀴 3시 vs 오른쪽 바퀴 9시
			if (gear[i][2] == gear[i + 1][6])
			{
				enable = false;
				rot[i] = 0;
			}
			else
			{
				rot[i] = d;
				d = -d;
			}
		}

		// 회전
		for (int i = 1; i <= 4; ++i)
		{
			if (rot[i] == 0)
				continue;

			if (rot[i] == 1)
				rotate(gear[i].begin(), gear[i].end() - 1, gear[i].end());
			else if (rot[i] == -1)
				rotate(gear[i].begin(), gear[i].begin() + 1, gear[i].end());
		}
	}

	// 점수
	int score = 0;
	if (gear[1][0] == '1') score += 1;
	if (gear[2][0] == '1') score += 2;
	if (gear[3][0] == '1') score += 4;
	if (gear[4][0] == '1') score += 8;

	cout << score;
}