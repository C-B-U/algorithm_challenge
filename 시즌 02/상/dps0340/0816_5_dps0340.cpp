#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <functional>
#include <utility>
#include <map>

#define lld long long int

const int MAX_COST = 10001;

int n, m;

std::vector<std::vector<char>> matrix;
std::vector<std::vector<int>> cost;

int bfs()
{
    std::deque<std::vector<int>> q;

    q.push_back({0, 0, 1});
    cost[0][0] = 1;

    int dx[] = {0, 0, -1, 1};
    int dy[] = {-1, 1, 0, 0};

    int result = 0;
    int cnt = 0;

    while (!q.empty())
    {
        const auto &v = q.front();

        const int x = v[0];
        const int y = v[1];
        const int c = v[2];

        if (c >= MAX_COST)
        {
            return -1;
        }

        result = std::max(result, c);

        const int weight = matrix[x][y] - '0';

        q.pop_front();

        for (int i = 0; i < 4; i++)
        {
            int x2 = x + dx[i] * weight;
            int y2 = y + dy[i] * weight;

            if (!(0 <= x2 && x2 < n))
            {
                continue;
            }
            if (!(0 <= y2 && y2 < m))
            {
                continue;
            }

            if (matrix[x2][y2] == 'H')
            {
                continue;
            }

            if (cost[x2][y2] >= c + 1)
            {
                continue;
            }

            cost[x2][y2] = c + 1;

            q.push_back({x2, y2, c + 1});
        }
    }

    return result;
}

int main(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    std::cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        std::string s;

        std::cin >> s;

        matrix.push_back({});
        cost.push_back({});

        for (const auto &c : s)
        {
            matrix[i].push_back(c);
            cost[i].push_back(0);
        }
    }

    std::cout << bfs() << "\n";
}