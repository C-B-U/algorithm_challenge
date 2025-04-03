#include <iostream>
#include <vector>
#include <array>
#include <numeric>
using namespace std;

int N;
vector<int> nums;
array<int, 4> opers;	// index 0: +, 1: -, 2: *, 3: /
int minVal = numeric_limits<int>::max();
int maxVal = numeric_limits<int>::min();
int start;

void BackTracking(int n, int total)
{
	// N - 1: ù ��° ���� total
	// N - 1�̶�� �ִ�, �ּҰ��� �����ϰ� return
	if (n == N - 1)
	{
		minVal = min(total, minVal);
		maxVal = max(total, maxVal);
		return;
	}

	// operator ����
	for (int i = 0; i < 4; ++i)
	{
		if (opers[i] == 0)
			continue;

		opers[i]--;

		// total���� �ٲ�� �ȵȴ�.
		int temp = total;

		switch (i)
		{
		case 0:
			temp += nums[n];
			break;
		case 1:
			temp -= nums[n];
			break;
		case 2:
			temp *= nums[n];
			break;
		case 3:
			temp /= nums[n];
			break;
		}

		BackTracking(n + 1, temp);

		opers[i]++;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;

	cin >> start;	// ù ��° �� ����

	nums.reserve(N - 1);
	for (int i = 0; i < N - 1; ++i)
	{
		int num;
		cin >> num;
		nums.push_back(num);
	}

	for (int i = 0; i < 4; ++i)
		cin >> opers[i];

	BackTracking(0, start);

	cout << maxVal << '\n';
	cout << minVal << '\n';
}