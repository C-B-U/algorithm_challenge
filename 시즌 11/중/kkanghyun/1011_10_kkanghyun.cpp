#include <iostream>
using namespace std;

int N, M;
int map[50][50];
int visited[50][50];
int cnt;    // 방문 횟수

// 북 동 남 서
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int r, c, d;

void DFS()
{
    // 모든 방향(동서남북) 청소, 
    // 왼쪽으로 회전
    for (int i = 0; i < 4; ++i)
    {
        int dir = (d + 3 - i) % 4;
        int nextR = r + dx[dir];
        int nextC = c + dy[dir];

        // 왼쪽 방향에 청소할 곳이 없다면, 
        // 그 방향으로 회전하고 2번으로 회귀
        if (nextR < 0 || nextR >= N ||
            nextC < 0 || nextC >= M ||
            map[nextR][nextC] == 1)
        {
            continue;
        }

        // 왼쪽 방향에 청소를 안한 곳이 있다면,
        // 그 방향으로 회전하고 한 칸을 전진
        if (map[nextR][nextC] == 0 && visited[nextR][nextC] == 0)
        {
            visited[nextR][nextC] = 1;
            r = nextR;
            c = nextC;
            d = dir;

            ++cnt;
            DFS();
        }
    }

    int dir = d > 1 ? d - 2 : d + 2;
    int backR = r + dx[dir];
    int backC = c + dy[dir];
    // 모든 방향이 청소가 되어있거나 벽이라면,
    if (backR >= 0 && backR <= N || backC >= 0 || backC <= M)
    {
        // 바라보는 방향을 유지한 채로 한 칸 후진
        if (map[backR][backC] == 0)
        {
            r = backR;
            c = backC;
            DFS();
        }
        // 뒤쪽 방향이 벽이라 후진도 안된다면 멈춤
        else
        {
            cout << cnt << endl;
            exit(0);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    cin >> r >> c >> d;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            cin >> map[i][j];
        }
    }

    visited[r][c] = 1;
    ++cnt;

    DFS();
}