#include<iostream>
using namespace std;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int T, k, list[41]; list[0] = 0; list[1] = 1;
	for (int i = 2; i <= 40; i++)list[i] = list[i - 1] + list[i - 2];
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> k;
		(k < 2)?cout << !k << ' ' << k: cout << list[k - 1] << ' ' << list[k];
		cout << '\n';
	}
	return 0;
	// fi(0) = b = 0
	// fi(1) = a = 1
	// fi(2) = fi(1) + fi(0) = a + b = 1
	// fi(3) = fi(2) + fi(1) = 2fi(1) + fi(0) = 2a + b = 2
	// fi(4) = fi(3) + fi(2) = 2fi(2) + fi(1) = 3fi(1) + 2fi(0) 3a + 2b = 3
	// fi(1) 의 개수(num_of_a) : 0 1 1 2 3 5 ....로 num_of_a(n) = num_of_a(n-1) + num_of_a(n-2) (n>=2) 가 성립
	// fi(0) 의 개수(num_of_b) : 1 0 1 1 2 3 5 ..로 num_of_b(n) = num_of_b(n-1) + num_of_b(n-2) (n>=2) 가 성립
}
