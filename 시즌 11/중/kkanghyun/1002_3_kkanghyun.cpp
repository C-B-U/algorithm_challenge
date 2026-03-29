#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	// N : 화분 갯수
	// K : 화분의 초기 수분
	// A : 물을 줄 연속된 화분의 갯수
	// B : A 개의 화분에 물을 줄 때 증가하는 수분
	int N, K, A, B;
	cin >> N >> K >> A >> B;

	vector<int> v(N, K);

	int day{};
	bool bDeath = false;
	int idx{};
	while (!bDeath)
	{
		++day;

		// 물 주기
		for (int i = 0; i < A; ++i)
		{
			if (idx >= N)
				idx = 0;

			v[idx] += B;
			++idx;
		}

		// 수분 감소, 죽은 화분 체크
		for (int& pot : v)
		{
			--pot;

			// 죽은 화분이 있다면 종료
			if (pot <= 0)
			{
				bDeath = true;
				break;
			}
		}
	}

	cout << day;
}