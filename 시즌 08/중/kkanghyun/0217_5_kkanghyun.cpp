#include <iostream>
#include <array>
#include <algorithm>

using namespace std;

array<array<int, 3>, 1001> arr;

int main()
{
	int N;
	cin >> N;

    for (int i = 1; i <= N; ++i) 
    {
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];

        arr[i][0] += min(arr[i - 1][1], arr[i - 1][2]);
        arr[i][1] += min(arr[i - 1][0], arr[i - 1][2]);
        arr[i][2] += min(arr[i - 1][0], arr[i - 1][1]);
    }

    cout << min(arr[N][0], min(arr[N][1], arr[N][2]));
}