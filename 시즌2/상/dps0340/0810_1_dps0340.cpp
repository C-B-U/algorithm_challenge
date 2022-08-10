// https://www.acmicpc.net/problem/2437
// https://www.acmicpc.net/source/47469711

#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")

#include <iostream>
#include <vector>
#include <algorithm>
#define lld long long int

int main(void)
{
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    int n;

    std::cin >> n;

    std::vector<lld> v;

    lld sum = 0;

    for (int i = 0; i < n; i++)
    {
        lld e;
        std::cin >> e;

        sum += e;

        v.push_back(e);
    }

    std::sort(v.begin(), v.end());

    int x = 1;

    for (const auto &e : v)
    {
        if (x < e)
        {
            break;
        }
        x += e;
    }

    std::cout << x << "\n";
}