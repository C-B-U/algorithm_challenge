#include<iostream>
using namespace std;
int GCD(int a, int b) {
	if (b == 0)return a;
	else return GCD(b, a % b);
}
int main() {
	int x, y; cin >> x >> y;
	int a = ((x > y) ? GCD(x, y) : GCD(y, x));
	cout << x + y - a;
	return 0;
}
