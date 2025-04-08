#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

// 가장 큰 수를 만들기 위해선 만들고자 하는 수의 자릿수 갯수가 우선시된다.
// 적용할 수 있는 숫자 중 가장 적은 가격을 가진 숫자를 가능한 한 많이 선택한다.
// leading digit을 선택할 때는 0이 아닌 숫자 중 가장 적은 가격을 가진 숫자를 선택하는 것을 주의한다.

// 그 후에 남은 금액을 이용하여 방 번호를 수정한다.
// 가장 큰 자리부터 시작하여, 현재 자릿수의 숫자를 남은 금액을 이용하여 가능한 가장 큰 숫자로 바꾼다.

// ※ 이미 제출한 코드가 존재하여 이로 갈음합니다.

using namespace std;

int main()
{
	FASTIO();

	string s;
	int n, m, pi[10];
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> pi[i];
	cin >> m;

	if (n <= 1)
	{
		cout << '0';
		return 0;
	}

	int imin = 1;
	for (int i = 2; i < n; ++i)
	{
		if (pi[i] <= pi[imin])
			imin = i;
	}

	if (pi[imin] > m)
	{
		cout << '0';
		return 0;
	}

	s.push_back(imin + '0');
	m -= pi[imin];
	imin = pi[imin] <= pi[0] ? imin : 0;
	while (m >= pi[imin])
	{
		s.push_back(imin + '0');
		m -= pi[imin];
	}

	for (auto iter = s.begin(); iter != s.end() && m > 0; ++iter)
	{
		int cpi = *iter - '0';
		int ip = 0;
		for (int i = 0; i < n; ++i)
		{
			if (pi[i] - pi[cpi] <= m)
				ip = i;
		}
		*iter = ip + '0';
		m -= pi[ip] - pi[cpi];
	}

	cout << s;
}