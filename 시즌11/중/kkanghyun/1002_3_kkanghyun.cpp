#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	// N : ȭ�� ����
	// K : ȭ���� �ʱ� ����
	// A : ���� �� ���ӵ� ȭ���� ����
	// B : A ���� ȭ�п� ���� �� �� �����ϴ� ����
	int N, K, A, B;
	cin >> N >> K >> A >> B;

	vector<int> v(N, K);

	int day{};
	bool bDeath = false;
	int idx{};
	while (!bDeath)
	{
		++day;

		// �� �ֱ�
		for (int i = 0; i < A; ++i)
		{
			if (idx >= N)
				idx = 0;

			v[idx] += B;
			++idx;
		}

		// ���� ����, ���� ȭ�� üũ
		for (int& pot : v)
		{
			--pot;

			// ���� ȭ���� �ִٸ� ����
			if (pot <= 0)
			{
				bDeath = true;
				break;
			}
		}
	}

	cout << day;
}