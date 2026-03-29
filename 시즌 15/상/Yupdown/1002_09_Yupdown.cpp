#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;
int memo[256][256];

// 문자열의 [lhs, rhs) 부분문자열에 RLE를 적용한 후의 최소 길이로 다이나믹 프로그래밍 수행
// Pivot을 두며 좌우 최적해를 서로 더한 길이와 연속 문자열을 압축한 길이를 대조하면서 최적해 기록

int solution(const string& s, int lhs, int rhs)
{
	if (memo[lhs][rhs] >= 0)
		return memo[lhs][rhs];
	int ret = rhs - lhs;
	if (rhs - lhs <= 1)
		return memo[lhs][rhs] = ret;
	for (int mid = lhs + 1; mid < rhs; ++mid)
		ret = min(ret, solution(s, lhs, mid) + solution(s, mid, rhs));
	for (int step = 1; step <= (rhs - lhs) / 2; ++step)
	{
		int cnt = 1;
		for (int k = lhs + step; k + step <= rhs; k += step)
		{
			if (s.substr(lhs, step) == s.substr(k, step))
				++cnt;
			else
				break;
		}
		if (cnt > 1)
		{
			int l = 2;
			for (int k = cnt; k > 0; k /= 10)
				l++;
			ret = min(ret, l + solution(s, lhs, lhs + step) + solution(s, lhs + step * cnt, rhs));
		}
	}
	return memo[lhs][rhs] = ret;
}

int main()
{
	FASTIO();

	string s;
	cin >> s;
	memset(memo, -1, sizeof(memo));
	cout << solution(s, 0, s.size());
}