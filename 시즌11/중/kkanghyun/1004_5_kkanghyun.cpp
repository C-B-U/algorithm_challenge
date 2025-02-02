#include <iostream>
#include <array>
#include <algorithm>
using namespace std;

array<int, 500'000> arrTteok;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;

	for (int i = 0; i < N; ++i)
		cin >> arrTteok[i];

	sort(arrTteok.begin(), arrTteok.begin() + N);

	int max = 1;
	int cnt = 1;
	for (int i = 1; i < N; ++i)
	{
		if (arrTteok[i] == arrTteok[i - 1])
		{
			++cnt;

			max = std::max(cnt, max);
		}
		else
			cnt = 1;
	}

	cout << max;
}