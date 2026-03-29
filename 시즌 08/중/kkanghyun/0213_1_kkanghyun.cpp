#include <iostream>
#include <array>

using namespace std;

int main()
{
	array<int, 41> arr{ 0, 1, 1 };

	for (int i = 3; i < arr.size(); ++i) 
	{
		arr[i] = arr[i - 1] + arr[i - 2];
	}

	int T;
	cin >> T; 

	int N;
	for (int i = 0; i < T; ++i) 
	{
		cin >> N;
		if (N == 0)
		{
			cout << 1 << ' ' << 0 << '\n';
		}
		else if (N == 1)
		{
			cout << 0 << ' ' << 1 << '\n';
		}
		else
		{
			cout << arr[N - 1] << ' ' << arr[N] << '\n';
		}
	}
}