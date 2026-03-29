#include <iostream>

int main()
{
	int n;
	int hexa = 1, cnt = 1;

	std::cin >> n;

	if (n == 1)
		std::cout << 1 << std::endl;

	else {
		while (n > hexa) {
			hexa += (cnt * 6);
			cnt++;
		}
		std::cout << cnt << std::endl;
	}

	return 0;
}