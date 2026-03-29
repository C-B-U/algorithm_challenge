#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

// 인터렉티브 문제는 출력이 자신이 임의로 설정한 입력이 되는 것이고, 입력이 그 설정한 입력에 대해 "반응하는" 테스트케이스의 출력이 된다.
// 이런 맥락으로, 출력은 질의가 되고, 입력은 그 질의에 대한 응답이 되는 것이다.
// 테스트 케이스의 전체가 기정되어 한번에 입력으로 주어지는 일반적인 프로그래밍 문제랑 그 양식이 상이하다.
// 그래서, 인터렉티브 문제의 메인 골은 어떻게 출력(질의)을 구성하는지가 된다.
// 어떤 문제는 받은 응답에 대해서 내부적인 처리 후에 적절한 질의를 구성해야 하는 경우도 있다.
// 항상 질의 후 응답을 받기 전 cout << flush 를 하여야 한다.

int main()
{
	FASTIO();

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 1 - i % 2; j < m; j += 2)
		{
			cout << "? " << i + 1 << " " << j + 1 << "\n" << flush;
			int ret;
			if ((cin >> ret) && ret)
				return 0;
		}
	}
}