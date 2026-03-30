#include <iostream>
using namespace std;

// 1, 9, 17, 25, ..
// 2, 8, 10, 16, 18, ..
// 3, 7, 11, 15, ..
// 4, 6, 12, 14, ..
// 5, 13, 21, 29 ..

int main() 
{
	size_t n, m;
	cin >> n >> m;

	if (n == 1)
	{
		cout << 8 * m;
	}
	else if (n == 5)
	{
		cout << 8 * m + 4;
	}
	else 
	{
		size_t num;

		if (m & 1) 
			num = 4 - n;
		else 
			num = n - 2;

		cout << 4 * m + 1 + num;
	}
}