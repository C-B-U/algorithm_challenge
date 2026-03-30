#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#define lld long long int

int calculate_max(std::vector<std::vector<int>> map)
{
    int result = 0;

    for (int i = 0; i < map.size(); i++)
    {
        for (int j = 0; j < map[i].size(); j++)
        {
            result = std::max(result, map[i][j]);
        }
    }

    return result;
}

std::vector<std::vector<int>> migrate(std::vector<std::vector<int>> map, int direction)
{
    std::vector<std::vector<int>> result(map.size());

    for (int i = 0; i < map.size(); i++)
    {
        for (int j = 0; j < map[i].size(); j++)
        {
            result[i].push_back(map[i][j]);
        }
    }

    std::vector<std::vector<bool>> is_merged(map.size());

    for (int i = 0; i < map.size(); i++)
    {
        for (int j = 0; j < map[i].size(); j++)
        {
            is_merged[i].push_back(false);
        }
    }

    if (direction == 8)
    {
        for (int t = 0; t < result.size(); t++)
        {
            for (int y = 0; y < result.size(); y++)
            {
                for (int x = 0; x < result[0].size(); x++)
                {
                    if (!(0 <= y - 1 && y - 1 < result.size()))
                    {
                        continue;
                    }
                    if (result[y][x] && result[y][x] == result[y - 1][x] && !is_merged[y][x] && !is_merged[y - 1][x])
                    {
                        is_merged[y - 1][x] = true;
                        result[y - 1][x] *= 2;
                        result[y][x] = 0;
                    }
                    else if (result[y][x] && !result[y - 1][x])
                    {
                        is_merged[y - 1][x] = is_merged[y][x];
                        result[y - 1][x] = result[y][x];
                        result[y][x] = 0;
                    }
                }
            }
        }
    }

    if (direction == 2)
    {
        for (int t = 0; t < result.size(); t++)
        {
            for (int y = result.size() - 1; y >= 0; y--)
            {
                for (int x = 0; x < result[0].size(); x++)
                {
                    if (!(0 <= y + 1 && y + 1 < result.size()))
                    {
                        continue;
                    }
                    if (result[y][x] && result[y][x] == result[y + 1][x] && !is_merged[y][x] && !is_merged[y + 1][x])
                    {
                        is_merged[y + 1][x] = true;
                        result[y + 1][x] *= 2;
                        result[y][x] = 0;
                    }
                    else if (result[y][x] && !result[y + 1][x])
                    {
                        is_merged[y + 1][x] = is_merged[y][x];
                        result[y + 1][x] = result[y][x];
                        result[y][x] = 0;
                    }
                }
            }
        }
    }

    if (direction == 4)
    {
        for (int t = 0; t < result.size(); t++)
        {
            for (int y = 0; y < result.size(); y++)
            {
                for (int x = 0; x < result.size(); x++)
                {
                    if (!(0 <= x - 1 && x - 1 < result[y].size()))
                    {
                        continue;
                    }
                    if (result[y][x] && result[y][x] == result[y][x - 1] && !is_merged[y][x] && !is_merged[y][x - 1])
                    {
                        is_merged[y][x - 1] = true;
                        result[y][x - 1] *= 2;
                        result[y][x] = 0;
                    }
                    else if (result[y][x] && !result[y][x - 1])
                    {
                        is_merged[y][x - 1] = is_merged[y][x];
                        result[y][x - 1] = result[y][x];
                        result[y][x] = 0;
                    }
                }
            }
        }
    }

    if (direction == 6)
    {
        for (int t = 0; t < result.size(); t++)
        {
            for (int y = 0; y < result.size(); y++)
            {
                for (int x = result[y].size() - 1; x >= 0; x--)
                {
                    if (!(0 <= x + 1 && x + 1 < result[y].size()))
                    {
                        continue;
                    }
                    if (result[y][x] && result[y][x] == result[y][x + 1] && !is_merged[y][x] && !is_merged[y][x + 1])
                    {
                        is_merged[y][x + 1] = true;
                        result[y][x + 1] *= 2;
                        result[y][x] = 0;
                    }
                    else if (result[y][x] && !result[y][x + 1])
                    {
                        is_merged[y][x + 1] = is_merged[y][x];
                        result[y][x + 1] = result[y][x];
                        result[y][x] = 0;
                    }
                }
            }
        }
    }

    return result;
}

int solve(std::vector<std::vector<int>> map, int cnt)
{
    if (cnt == 5)
    {
        return calculate_max(map);
    }

    int answer = 0;

    for (const int &direction : {2, 4, 6, 8})
    {
        std::vector<std::vector<int>> next = migrate(map, direction);

        answer = std::max(answer, solve(next, cnt + 1));
    }

    return answer;
}

int main(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int n;

    std::cin >> n;

    std::vector<std::vector<int>> map(n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int e;
            std::cin >> e;

            map[i].push_back(e);
        }
    }

    int result = solve(map, 0);

    std::cout << result;
}