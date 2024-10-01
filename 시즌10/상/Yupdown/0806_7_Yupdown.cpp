#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

// "1 <= i <= n 인 i에 대해 이항 계수 (n, i)이 m으로 나누어 떨어지면 i는 불필요한 수의 index 이다."
// 
// 각 i에 대해 이항 계수를 구하면 풀 수 있는 문제이다. 그러나, 널리 알려진 다이나믹 프로그래밍 방식으로는 n <= 100000 에서 유효한 시간복잡도 이내에 정답을 구할 수 없다.
// 팩토리얼의 성질을 적절히 이용하여 (n, 1) ~ (n, n) 까지의 이항 계수를 곱하기와 나눗셈 연산으로 O(n) 만에 구하는 방식도 있다. 하지만, 연산 중 오버플로우가 발생할 수 있으며, 모듈로 연산이 있다고 해도 연산 중 나눗셈 연산이 포함되어 있기 때문에 불가능에 가까워진다.
// 파이썬에서는 BigInteger를 십분 활용할 수 있으나, 숫자가 수십만 자리까지 커질 우려가 있다.
// 
// 이 소스 코드에서 시도해 본 해결책은 소인수분해된 이항 계수와 m을 비교하여, m의 소인수들이 이항 계수의 소인수에 포함될 수 있는지 확인하는 것이다.
// 어떤 수 x의 소인수가 다른 수 y의 소인수에 포함된다면, y는 x로 나누어 떨어지기 때문이다. (y % x == 0)
// 이를 위해, m을 먼저 소인수분해하고, i를 증가시키며 곱할 수 n - i와 나눌 수 i를 소인수분해하여 테이블에 누적하고, m의 소인수들이 이 테이블에 포함되어 있는지 확인한다.
// 곱하는 경우 테이블에 각 소인수를 더하고, 나누는 경우 테이블에서 각 소인수를 빼는 방식으로 구현할 수 있다.
// 소인수분해 속도가 충분히 빠르다면 선형 시간복잡도만에 정답을 구할 수 있다.


// ~100000 이 가질 수 있는 소수의 목록들
int primes[] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317 };
int table[100000];

// 각 n을 소인수분해하고 나온 소수들을 테이블에 누적
void populate_primes(int n, int delta)
{
    for (int p : primes)
    {
        if (p * p > n)
            break;
        if (n % p == 0)
        {
            table[p] += delta;
            populate_primes(n / p, delta);
            return;
        }
    }
    table[n] += delta;
}

// m을 소인수분해
void get_primes(int n, map<int, int>& out)
{
    for (int p = 2; p * p <= n; ++p)
    {
        if (n % p == 0)
        {
            out[p]++;
            get_primes(n / p, out);
            return;
        }
    }
    out[n]++;
}

int main()
{
    FASTIO();

    int n, m;
	cin >> n >> m;

    map<int, int> target{};
    get_primes(m, target);

    vector<int> res{};
    for (int i = 1; i < n; ++i)
    {
        populate_primes(n - i, 1);
        populate_primes(i, -1);

        bool flag = true;
        for (const auto& [p, c] : target)
        {
            if (p > 100000 || table[p] < c)
            {
                flag = false;
                break;
            }
        }
        if (flag)
            res.push_back(i + 1);
    }

    cout << res.size() << '\n';
    for (int i : res)
        cout << i << '\n';
}