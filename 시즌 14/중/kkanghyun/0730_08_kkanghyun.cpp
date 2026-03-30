#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int N;
vector<int> nums;
int opers[4];	// index 0: +, 1: -, 2: *, 3: /
int minVal = numeric_limits<int>::max();
int maxVal = numeric_limits<int>::min();
int start;

void BackTracking(int n, int total)
{
	// N - 1: 첫 번째 값은 total
	// N - 1이라면 최댓값, 최소값을 갱신하고 return
	if (n == N - 1)
	{
		minVal = min(total, minVal);
		maxVal = max(total, maxVal);
		return;
	}

	// operator 소진
	for (int i = 0; i < 4; ++i)
	{
		if (opers[i] == 0)
			continue;

		opers[i]--;

		// total값이 바뀌면 안된다.
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

	cin >> start;	// 첫 번째 값 저장

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