
// 3x3 부분 행렬 뒤집기 함수
static void Flip(int[,] A, int[,] B, int x, int y)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            A[x + i, y + j] = 1 - A[x + i, y + j];
        }
    }
}

// 입력
string[] inputs = Console.ReadLine()!.Split();
int N = int.Parse(inputs[0]);
int M = int.Parse(inputs[1]);

int[,] A = new int[N, M];
int[,] B = new int[N, M];

for (int i = 0; i < N; ++i)
{
    var row = Console.ReadLine()!.Select(c => c - '0').ToArray();
    for (int j = 0; j < M; ++j)
    {
        A[i, j] = row[j];
    }
}

for (int i = 0; i < N; ++i)
{
    var row = Console.ReadLine()!.Select(c => c - '0').ToArray();
    for (int j = 0; j < M; ++j)
    {
        B[i, j] = row[j];
    }
}

// A를 B로 변환
int flipCount = 0;
for (int i = 0; i <= N - 3; ++i)
{
    for (int j = 0; j <= M - 3; ++j)
    {
        if (A[i, j] != B[i, j])
        {
            Flip(A, B, i, j);
            ++flipCount;
        }
    }
}

// A와 B가 같은지 확인
bool bSame = true;
for (int i = 0; i < N; ++i)
{
    for (int j = 0; j < M; ++j)
    {
        if (A[i, j] != B[i, j])
        {
            bSame = false;
            break;
        }
    }
    if (!bSame) 
        break;
}

if (bSame)
{
    Console.WriteLine(flipCount);
}
else
{
    Console.WriteLine(-1);
}