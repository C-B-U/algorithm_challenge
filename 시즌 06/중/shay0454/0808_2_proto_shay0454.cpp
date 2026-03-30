#include<iostream>
using namespace std;
int main() {
	long long finger,sum,useLimit;
	cin >> finger>>useLimit;
	if (finger != 1 && finger != 5) {
		sum = 8 * (useLimit / 2);
		sum += 10 * (useLimit % 2) + (useLimit % 2 ? -1 : 1) * finger - 1;
	}
	else {
		sum = 8 * useLimit + finger - 1;
	}
	cout << sum;
}
