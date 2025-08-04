#include <iostream>
using namespace std;

#define MAX	9

int board[MAX][MAX];
bool row[MAX][MAX];	// row[i][j] == true : i번째 가로줄에 j라는 숫자는 존재한다.
bool col[MAX][MAX];	// col[i][j] == true : i번째 세로줄에 j라는 숫자는 존재한다.
bool square[MAX][MAX];	// square[i][j] == true : i번째 사각형에 j라는 숫자는 존재한다. 단, 사각형 번호는 왼쪽위부터 가로로 센다.

void Input()
{
	for (int i = 0; i < MAX; ++i)
	{
		for (int j = 0; j < MAX; ++j)
		{
			cin >> board[i][j];

			if (board[i][j] == 0)
				continue;

			row[i][board[i][j]] = true;
			col[j][board[i][j]] = true;
			square[(i / 3) * 3 + (j / 3)][board[i][j]] = true;
		}
	}
}

void Output()
{
	for (int i = 0; i < MAX; ++i)
	{
		for (int j = 0; j < MAX; ++j)
		{
			cout << board[i][j] << " ";
		}
		cout << '\n';
	}
}

void DFS(int cnt)
{
	int x = cnt / MAX;	// x 좌표
	int y = cnt % MAX;	// y 좌표

	if (cnt == 81)
	{
		Output();
		exit(0);
	}

	if (board[x][y] != 0)
	{
		DFS(cnt + 1);
		return;
	}

	for (int i = 1; i <= 9; ++i)
	{
		// 0이 아니라면 continue
		if (row[x][i] == true
			|| col[y][i] == true
			|| square[(x / 3) * 3 + (y / 3)][i] == true)
		{
			continue;
		}

		row[x][i] = true;
		col[y][i] = true;
		square[(x / 3) * 3 + (y / 3)][i] = true;
		board[x][y] = i;

		DFS(cnt + 1);

		row[x][i] = false;
		col[y][i] = false;
		square[(x / 3) * 3 + (y / 3)][i] = false;
		board[x][y] = 0;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	Input();
	DFS(0);
}

// https://yabmoons.tistory.com/88