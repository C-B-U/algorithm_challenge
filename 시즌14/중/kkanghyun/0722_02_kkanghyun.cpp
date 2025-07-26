#include <iostream>
#include <algorithm>
using namespace std;

int arr[100'000];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}

	sort(arr, arr + n);

	int x;
	cin >> x;

	int i = 0, j = n - 1;
	int cnt = 0;
	while (true)
	{
		if (i >= j)
			break;

		if (arr[i] + arr[j] < x)
		{
			++i;
		}
		else if (arr[i] + arr[j] == x)
		{
			++cnt;
			++i;
			--j;
		}
		else
		{
			--j;
		}
	}

	cout << cnt;
}