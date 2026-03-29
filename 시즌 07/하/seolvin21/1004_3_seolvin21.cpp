#include <iostream>

int main()
{
	int t;
	int a = 0, b = 0, c = 0;

	std::cin >> t;

	if (t % 10 != 0)
		std::cout << -1;

	else {
		a = t / 300;
		t = t % 300;

		b = t / 60;
		t = t % 60;

		c = t / 10;

		std::cout << a << " " << b << " " << c << std::endl;
	}

	return 0;
}