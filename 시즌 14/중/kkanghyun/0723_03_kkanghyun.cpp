#include <iostream>
using namespace std;

int k;
int nums[13];
bool visited[13];

int arr[13];
void OutputCases(int n, int start)
{
	if (n == 6)
	{
		// output
		for (int i = 0; i < 6; ++i)
			cout << arr[i] << " ";
		cout << '\n';

		return;
	}

	// BackTracking
	for (int i = start; i < k; ++i)
	{
		if (visited[i])
			continue;

		visited[n] = true;
		arr[n] = nums[i];
		OutputCases(n + 1, i + 1);
		visited[n] = false;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	while (true)
	{
		cin >> k;

		if (k == 0)
			break;

		for (int i = 0; i < k; ++i)
		{
			cin >> nums[i];
			visited[i] = false;
		}

		OutputCases(0, 0);

		cout << '\n';
	}
}