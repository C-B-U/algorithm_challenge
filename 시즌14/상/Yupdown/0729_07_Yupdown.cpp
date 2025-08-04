#include <bits/stdc++.h>

using namespace std;

int solution(int n, int a, int b, int c, int i, int d)
{
	if (i == n)
		return d == 0 ? a : 0;
	int ret = 0;
	if (d > 0)
		ret = max(ret, solution(n, static_cast<long long>(a) * c % 100000, b, c, i + 1, d - 1));
	ret = max(ret, solution(n, a + b % 100000, b, c, i + 1, d + 1));
	return ret;
}

int main()
{
	int n, a, b, c;
	cin >> n >> a >> b >> c;
	cout << solution(n * 2, a, b, c, 0, 0);
}