#include <iostream>
#include <array>
using namespace std;

int main()
{
	array<float, 5> components{ 350.34f, 230.90f, 190.55f, 125.30f, 180.90f };
	array<int, 5> counts;

	int N;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		float price = 0.f;
		cin >> counts[0] >> counts[1] >> counts[2] >> counts[3] >> counts[4];
		for (int j = 0; j < 5; ++j) {
			price += counts[j] * components[j];
		}
		printf("$%.2f\n", price);
	}
}