#include <iostream>

int main()
{
	int n;


	std::cin >> n;

	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < n - i; ++j) {
			std::cout << " ";
		}
		for (int k = 0; k < i * 2 - 1; ++k) {
			std::cout << "*";
		}
		std::cout << std::endl;
	}

	for (int i = n-1; i > 0; --i) {
		for (int j = n - i; j > 0; --j) {
			std::cout << " ";
		}
		for (int k = 2 * i - 1; k > 0; --k) {
			std::cout << "*";
		}
		std::cout << std::endl;
	}

	return 0;
}