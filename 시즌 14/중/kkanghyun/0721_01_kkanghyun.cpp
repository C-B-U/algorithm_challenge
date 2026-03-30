#include <iostream>
using namespace std;

int board[25][25];

int GetLineCount()
{
	int total = 0;

	int w, h;
	for (int i = 0; i < 5; ++i)
	{
		w = h = 0;
		for (int j = 0; j < 5; ++j)
		{
			if (board[i][j] == 0)
				++w;

			if (board[j][i] == 0)
				++h;
		}

		if (w == 5)
			total++;

		if (h == 5)
			total++;
	}

	// 대각선 체크
	int LT = 0, RT = 0;
	for (int i = 0; i < 5; ++i)
	{
		if (board[i][i] == 0)
			LT++;

		if (board[4 - i][i] == 0)
			RT++;
	}

	if (LT == 5)
		total++;

	if (RT == 5)
		total++;

	return total;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			cin >> board[i][j];
		}
	}

	int ans;
	bool bingo = false;
	int num;
	for (int i = 0; i < 25; ++i)
	{
		cin >> num;

		if (bingo)
			continue;

		for (int j = 0; j < 25; ++j)
		{
			bool check = false;
			for (int k = 0; k < 25; ++k)
			{
				if (board[j][k] == num)
				{
					board[j][k] = 0;
					check = true;
					break;
				}
			}

			if (check)
				break;
		}

		if (GetLineCount() >= 3)
		{
			ans = i + 1;
			bingo = true;
		}
	}

	cout << ans;
}