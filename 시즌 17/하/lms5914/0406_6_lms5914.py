#include <iostream>
using namespace std;

int main() {
	int N;
	if (!(cin >> N)) return 0;

	int statements[50];
	for (int i = 0; i < N; i++) {
		cin >> statements[i];
	}
	int max_truth = -1;
	for (int k = 0; k <= N; k++) {
		int count = 0;
		for (int i = 0; i < N; i++) {
			if (statements[i] == k) {
				count++;
			}
		}
		if (k == count) {
			if (k > max_truth) {
				max_truth = k;
			}
		}
	}
	cout << max_truth << endl;
	return 0;
}
