#include <iostream>
using namespace std;

int main()
{
	size_t a, b;
	cin >> a >> b;

	size_t sum = 0;
	for (int i = a + (a & 1); i <= b; i += 2) 
	{
		if (i == 2) 
			continue;

		sum += i;
	}

	cout << sum;
}