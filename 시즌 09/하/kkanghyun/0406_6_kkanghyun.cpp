#include <iostream>
using namespace std;

int main()
{
	int A, B, C, D, E;
	cin >> A >> B >> C >> D >> E;

    if (A < 0)
        std::cout << abs(A) * C + D + B * E << std::endl;
    else
        std::cout << (B - A) * E << std::endl;
}