#include <iostream>

int main()
{
	int a, b, c, d;

	std::cin >> a >> b >> c >> d;
	std::cout << abs((a + d) - (b + c)) << std::endl;

	return 0;
}