#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int N;
vector<int> nums;
int oper[4];	// +, -, *, /
int maxNum = INT_MIN;
int minNum = INT_MAX;
int res;

void Calc(int n)
{
	if (n == N)
	{
		maxNum = max(maxNum, res);
		minNum = min(minNum, res);

		return;
	}

	int tmp = res;

	// +
	if (oper[0])
	{
		oper[0]--;
		res += nums[n];
		Calc(n + 1);
		res = tmp;
		oper[0]++;
	}

	// -
	if (oper[1])
	{
		oper[1]--;
		res -= nums[n];
		Calc(n + 1);
		res = tmp;
		oper[1]++;
	}

	// *
	if (oper[2])
	{
		oper[2]--;
		res *= nums[n];
		Calc(n + 1);
		res = tmp;
		oper[2]++;
	}

	// /
	if (oper[3])
	{
		oper[3]--;
		res /= nums[n];
		Calc(n + 1);
		res = tmp;
		oper[3]++;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;

	nums.resize(N);
	for (int i = 0; i < N; ++i)
		cin >> nums[i];

	for (int i = 0; i < 4; ++i)
		cin >> oper[i];

	res = nums[0];
	Calc(1);

	cout << maxNum << '\n' << minNum;
}