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

const int GATE_SIZE = 100001;

std::vector<int> gate(GATE_SIZE);

int n, m;

int main(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int g, p;

    std::cin >> g >> p;

    int e;

    int result = 0;

    for (int i = 0; i < GATE_SIZE; i++)
    {
        gate[i] = i;
    }

    for (int i = 0; i < p; i++)
    {
        std::cin >> e;

        auto &&it = std::lower_bound(gate.begin(), gate.end(), e);

        if (*it > e || it == gate.end())
        {
            it--;
        }

        if (*it == 0) [[unlikely]]
        {
            break;
        }

        gate.erase(it);
    }

    std::cout << GATE_SIZE - gate.size() << "\n";
}