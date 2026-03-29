#include <iostream>
#include <algorithm>
using namespace std;

int woods[1'000'000];

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M;	// 나무 개수, 나무 길이
	cin >> N >> M;

	for (int i = 0; i < N; ++i)
	{
		cin >> woods[i];
	}

	sort(woods, woods + N);

	int left = 1, right = woods[N - 1], mid = 0, res = 0;
	while (left <= right)
	{
		mid = (left + right) / 2;

		res = 0;
		for (int len : woods)
		{
			if (len - mid > 0)
				res += len - mid;
		}

		if (res == M)
			break;
		else if (res < M)
			right = mid - 1;
		else
			left = mid + 1;
	}

	if (res < M)
		cout << mid - 1;	// 현재 필요한 나무의 값보다 작을 경우
	else
		cout << mid;
}
