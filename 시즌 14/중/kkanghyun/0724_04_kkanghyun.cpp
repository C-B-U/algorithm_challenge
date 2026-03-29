#include <iostream>
#include <algorithm>
using namespace std;

int arr[10'000];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;

	for (int i = 0; i < N; ++i)
		cin >> arr[i];

	int M;
	cin >> M;

	sort(arr, arr + N);

    int start = 0;
    int end = arr[N - 1];   // 상한선
    int ans;
    while (start <= end) 
    {
        int mid = (start + end) / 2;
        int sum = 0;
        for (auto i = 0; i < N; i++) 
            sum += min(arr[i], mid);

        if (M >= sum)   // 예산 초과 X
        {
            ans = mid;
            start = mid + 1;
        }
        else // 예산 초과
        {
            end = mid - 1;
        }
    }

    cout << ans;
}