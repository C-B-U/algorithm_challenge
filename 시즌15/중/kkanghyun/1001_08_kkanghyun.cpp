#include <iostream>
using namespace std;

int input[101][101];
bool visited[101][101];
int N;

void DFS(int top, int x, int y) 
{
    input[top][y] = 1;
    visited[top][y] = true;

    for (int i = 1; i <= N; i++) 
    {
        if (!visited[top][i] && input[y][i])
            DFS(top, y, i);
    }
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;

    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= N; ++j)
        {
            cin >> input[i][j];
        }
    }

    for (int i = 1; i <= N; ++i) 
    {
        for (int j = 1; j <= N; ++j) 
        {
            if (!visited[i][i] && input[i][j])
                DFS(i, i, j);
        }
    }

    for (int i = 1; i <= N; ++i) 
    {
        for (int j = 1; j <= N; ++j)
        {
            cout << input[i][j] << " ";
        }

        cout << '\n';
    }
}