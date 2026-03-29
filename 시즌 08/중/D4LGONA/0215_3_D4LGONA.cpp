#include <iostream>
using namespace std;

int arr[1000'001]{};

int main()
{
	arr[10] = 3;
	int n;
	int a = 0;
	for (int i = 2; i <= 1000'001; ++i)
	{
		n = 2147483647;

		if (i == 10) continue;
		
		if (i % 3 == 0)
		{
			a = arr[i / 3] + 1;
			if (n > a)
				n = arr[i / 3] + 1;
		}

		if (i % 2 == 0)
		{
			a = arr[i / 2] + 1;
			if (n > a)
				n = arr[i / 2] + 1;
		}
		
		a = arr[i - 1] + 1;
		if (n > a)
			n = arr[i - 1] + 1;

		arr[i] = n;
	}
	int N;
	cin >> N;

	cout << arr[N] << endl;
}