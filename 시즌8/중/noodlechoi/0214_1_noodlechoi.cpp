#include <iostream>
// 피보나치 함수
/*
* 문제
1은 2번 출력되고, 0은 1번 출력된다. 
N이 주어졌을 때, fibonacci(N)을 호출했을 때,
0과 1이 각각 몇 번 출력되는지 구하는 프로그램을 작성하시오.
*/

using namespace std;

int main()
{
	int T, N;
	int cnt[41]{ 0, 1 };
	for (int i = 2; i < 41; ++i) {
		cnt[i] = cnt[i - 1] + cnt[i - 2];
	}

	cin >> T;
	for (int i = 0; i < T; ++i) {
		cin >> N;

		if (N == 0) cout << "1 0" << endl;
		else if (N == 1) cout << "0 1" << endl;
		else cout << cnt[N - 1] << " " << cnt[N] << endl;
	}

}