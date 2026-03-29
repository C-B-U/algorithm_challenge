#include <iostream>

int main()
{
	int a1, a2, a3;

	std::cin >> a1;
	std::cin >> a2;
	std::cin >> a3;
	

	if (a1 == 60 && a2 == 60 && a3 == 60) {
		std::cout << "Equilateral" << std::endl;
	}
	else if (a1 + a2 + a3 == 180) {
		if (a1 == a2 || a1 == a3 || a2 == a3)
			std::cout << "Isosceles" << std::endl;
		else
			std::cout << "Scalene" << std::endl;
	}
	else
		std::cout << "Error" << std::endl;
}