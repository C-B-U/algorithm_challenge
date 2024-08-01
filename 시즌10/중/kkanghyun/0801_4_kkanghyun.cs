
int T = int.Parse(Console.ReadLine()!);
int[] N = new int[T];
for (int i = 0; i < T; i++)
{
    N[i] = int.Parse(Console.ReadLine()!);
}

// 최대 N 값 찾아서 그만큼 dp 배열을 계산
int maxN = 0;
for (int i = 0; i < T; i++)
{
    if (N[i] > maxN)
        maxN = N[i];
}

(int, int)[] dp = new (int, int)[maxN + 1];

dp[0] = (1, 0);
if (maxN > 0)
    dp[1] = (0, 1);

for (int i = 2; i <= maxN; i++)
{
    dp[i] = (dp[i - 1].Item1 + dp[i - 2].Item1, dp[i - 1].Item2 + dp[i - 2].Item2);
}

for (int i = 0; i < T; i++)
{
    Console.WriteLine($"{dp[N[i]].Item1} {dp[N[i]].Item2}");
}
