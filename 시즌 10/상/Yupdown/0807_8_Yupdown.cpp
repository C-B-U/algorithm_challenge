#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;
int memo[128];

// 서로 동떨어져 있는 그룹 구성원들을 가장 뒤의 구성원 앞으로 연속해서 붙이면 그 구성원들의 총 이동거리만큼 시간이 절약된다.
// 물론 그 그룹간의 순서도 시간 절약의 요소이니 고려해야 하겠지만, 그 순서에 상관없이 총 시간 절약의 변화량은 없다나 뭐라나...

int main()
{
	FASTIO();

	int t;
	cin >> t;
	while (t--)
	{
		int n, r = 0;
		string s;
		cin >> n >> s;

		fill(begin(memo), end(memo), n);
		for (int i = n - 1; i >= 0; --i)
		{
			int c = s[i];
			if (memo[c] < n)
				r += --memo[c] - i;
			else
				memo[c] = i;
		}
		cout << r * 5 << '\n';
	}
}