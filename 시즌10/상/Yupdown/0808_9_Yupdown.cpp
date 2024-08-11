#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;
int xi[100000];

// 크기가 s인 슬라이딩 윈도우를 -s ~ n-1 까지 움직여 보면서 중복된 수 확인.
// 존재할 경우 i % s(i = 슬라이딩 윈도우의 위치)를 가능한 경우의 수에서 제거.
// 중복된 수가 3개 이상인 경우를 유의

int main()
{
	FASTIO();

	int t;
	cin >> t;
	while (t--)
	{
		int s, n;
		cin >> s >> n;
		for (int i = 0; i < n; ++i)
			cin >> xi[i];

		vector<int> c(s);
		vector<bool> r(s);
		int cf = 0;
		for (int q = 0; q < n + s; ++q)
		{
			if (q >= s)
			{
				if (--c[xi[q - s] - 1] == 1)
					--cf;
			}
			if (q < n)
			{
				if (++c[xi[q] - 1] == 2)
					++cf;
			}
			if (cf)
				r[q % s] = true;
		}

		cout << count(r.begin(), r.end(), false) << '\n';
	}
}