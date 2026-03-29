#include <iostream>

int GCD(int b, int s)	//최대공약수
{
	int temp;
	while(1) {
		if (b % s == 0) {
			return s;
		}
		else {
			temp = b % s;
			b = s;
			s = temp;
		}
	}
}

int main()
{
	int a, b;
	int big, small;
	int gcd, lcm;

	std::cin >> a >> b;

	if (a > b) {
		big = a;
		small = b;
	}
	else {
		big = b;
		small = a;
	}
		
	gcd = GCD(big, small);
	lcm = (a*b) / gcd;

	std::cout << gcd << std::endl;
	std::cout << lcm << std::endl;


	return 0;
}