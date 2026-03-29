#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)
#define PRECISION(n) cout<<fixed,cout.precision(n)

// 순열을 돌리기엔 어림잡아 20조에 달하는 경우의 수가 나오므로 무리가 있다.
// 만들 수 있는 모든 삼각형을 구하는 데에는 최대 560개이므로 먼저 구한다. (헤론의 공식 참고, https://en.wikipedia.org/wiki/Heron%27s_formula)
// 비트필드 다이나믹 프로그래밍을 이용하여 여태 사용한 울타리들에 대한 비트필드를 구하고,
// 앞으로 만들 수 있는 삼각형들의 넓이에 대한 최적해를 memo[i]에 기록해둔다.
// 2^16 = 65536개의 부분 최적해를 구하는데 각각 최대 560번 연산을 수행하니 유효한 시간복잡도 내에 최적해를 구할 수 있다.

using namespace std;

double edge[16];
double memo[1 << 16];
vector<pair<double, int>> triangle;

inline double SizeOfTriangle(double e1, double e2, double e3)
{
	if (max(e1, max(e2, e3)) * 2 >= e1 + e2 + e3)
		return -1;
	double p = (e1 + e2 + e3) * 0.5;
	return sqrt(p * (p - e1) * (p - e2) * (p - e3));
}

double Function(int bitmask)
{
	if (memo[bitmask] > 0)
		return memo[bitmask];
	double result = 0;
	for (const auto& [size, bitadd] : triangle)
	{
		if (bitadd & bitmask)
			continue;
		result = max(result, Function(bitmask | bitadd) + size);
	}
	return memo[bitmask] = result;
}

int main()
{
	FASTIO();
	PRECISION(12);

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> edge[i];
	for (int i = 0; i < n; ++i)
	{
		for (int j = i + 1; j < n; ++j)
		{
			for (int k = j + 1; k < n; ++k)
			{
				double size = SizeOfTriangle(edge[i], edge[j], edge[k]);
				if (size < 0)
					continue;
				triangle.emplace_back(size, 1 << i | 1 << j | 1 << k);
			}
		}
	}
	cout << Function(0) << endl;
}