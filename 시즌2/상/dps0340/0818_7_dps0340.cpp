#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")

#include <algorithm>
#include <cmath>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <utility>
#include <vector>

#define lld long long int

constexpr int MAX_M = 100'001;
constexpr int MAX_LOG2_M = 31;

int nexts[MAX_M][MAX_LOG2_M];
std::vector<int> starts;

int n, k, m;

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    std::cin >> n >> k >> m;

    starts.resize(n);

    for (int& start : starts) {
        std::cin >> start;
    }

    for (int i = 1; i <= k; i++) {
        std::cin >> nexts[i][0];
    }

    for (int y = 1; y < MAX_LOG2_M; y++) {
        for (int x = 1; x <= k; x++) {
            // LCA
            nexts[x][y] = nexts[nexts[x][y - 1]][y - 1];
        }
    }

    for (int node : starts) {
        int time = m - 1;
        int exp2;
        for (int y = MAX_LOG2_M - 1; y >= 0; y--) {
            if (time >= (exp2 = (1 << y))) {
                time -= exp2;
                node = nexts[node][y];
            }
        }
        std::cout << node << " ";
    }

    std::cout << "\n";
}