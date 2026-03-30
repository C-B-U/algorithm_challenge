#include <iostream>
#include <vector>
#include <string>
using namespace std;

int Size;
vector<string> Shapes;

// ...
// ...
// ...
bool IsDot(int x, int y)
{
	if (x <= 0 || y <= 0 || x >= Size || y >= Size)
		return false;

	for (int i = y - 1; i < y + 1; ++i)
	{
		for (int j = x - 1; j < x + 1; ++j)
		{
			if (Shapes[i][j] != '.')
				return false;
		}
	}
	
	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int N, M;
	cin >> N >> M;

	Size = max(N, M);
	Size *= 3;
	Shapes.resize(3 * N);
	const int row = 3 * N;
	const int column = 3 * M;
	for (int i = 0; i < row; ++i)
	{
		cin >> Shapes[i];
	}

	// Debug
	//Shapes[0] = "............";
	//Shapes[1] = ".##...###...";
	//Shapes[2] = ".#..........";
	//Shapes[3] = "....#.....#.";
	//Shapes[4] = "....##...##.";
	//Shapes[5] = "....#.....#.";
	//Shapes[6] = ".#.....#....";
	//Shapes[7] = ".##...##....";
	//Shapes[8] = ".#.....#....";
	//Shapes[9] = "..........#.";
	//Shapes[10] = "...###...##.";
	//Shapes[11] = "............";

	
	for (int i = 1; i < row; i += 3)
	{
		for (int j = 1; j < column; j += 3)
		{
			if (IsDot(j, i))
			{
				// # 위치 체크
				
				// Left
				if (j - 2 >= 0)
				{
					if (Shapes[i][j - 2] == '#')
					{
						Shapes[i][j] = '#';
						Shapes[i][j - 1] = '#';
					}
				}

				// Right
				if (j + 2 < column)
				{
					if (Shapes[i][j + 2] == '#')
					{
						Shapes[i][j] = '#';
						Shapes[i][j + 1] = '#';
					}
				}

				// Up
				if (i - 2 >= 0)
				{
					if (Shapes[i - 2][j] == '#')
					{
						Shapes[i][j] = '#';
						Shapes[i - 1][j] = '#';
					}
				}

				// Down
				if (i + 2 < row)
				{
					if (Shapes[i + 2][j] == '#')
					{
						Shapes[i][j] = '#';
						Shapes[i + 1][j] = '#';
					}
				}
			}
		}
	}

	for (int i = 0; i < row; ++i)
	{
		cout << Shapes[i] << '\n';
	}
}
