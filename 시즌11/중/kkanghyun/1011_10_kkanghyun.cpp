#include <iostream>
using namespace std;

int N, M;
int map[50][50];
int visited[50][50];
int cnt;    // �湮 Ƚ��

// �� �� �� ��
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int r, c, d;

void DFS()
{
    // ��� ����(��������) û��, 
    // �������� ȸ��
    for (int i = 0; i < 4; ++i)
    {
        int dir = (d + 3 - i) % 4;
        int nextR = r + dx[dir];
        int nextC = c + dy[dir];

        // ���� ���⿡ û���� ���� ���ٸ�, 
        // �� �������� ȸ���ϰ� 2������ ȸ��
        if (nextR < 0 || nextR >= N ||
            nextC < 0 || nextC >= M ||
            map[nextR][nextC] == 1)
        {
            continue;
        }

        // ���� ���⿡ û�Ҹ� ���� ���� �ִٸ�,
        // �� �������� ȸ���ϰ� �� ĭ�� ����
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
    // ��� ������ û�Ұ� �Ǿ��ְų� ���̶��,
    if (backR >= 0 && backR <= N || backC >= 0 || backC <= M)
    {
        // �ٶ󺸴� ������ ������ ä�� �� ĭ ����
        if (map[backR][backC] == 0)
        {
            r = backR;
            c = backC;
            DFS();
        }
        // ���� ������ ���̶� ������ �ȵȴٸ� ����
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