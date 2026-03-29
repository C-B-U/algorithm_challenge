Console.SetOut(new StreamWriter(Console.OpenStandardOutput()));

static int GetMinRepaints(char[,] board, int x, int y)
{
    string[] patterns = { "WBWBWBWB", "BWBWBWBW" };
    int repaints1 = 0;
    int repaints2 = 0;

    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 8; ++j)
        {
            if (board[x + i, y + j] != patterns[i % 2][j])
                ++repaints1;
            if (board[x + i, y + j] != patterns[(i + 1) % 2][j])
                ++repaints2;
        }
    }

    return Math.Min(repaints1, repaints2);
}

string[] input = Console.ReadLine()!.Split();
int N = int.Parse(input[0]);
int M = int.Parse(input[1]);

char[,] board = new char[N, M];

for (int i = 0; i < N; ++i)
{
    string line = Console.ReadLine()!;
    for (int j = 0; j < M; j++)
    {
        board[i, j] = line[j];
    }
}

int minRepaints = int.MaxValue;

for (int i = 0; i <= N - 8; ++i)
{
    for (int j = 0; j <= M - 8; ++j)
    {
        minRepaints = Math.Min(minRepaints, GetMinRepaints(board, i, j));
    }
}

Console.WriteLine(minRepaints);

Console.Out.Flush();