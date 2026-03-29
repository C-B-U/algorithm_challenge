#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {

	int N;
	cin >> N;

	vector<int> arr;
	for (int i = 0; i < N; i++) {
		int A, B;
		cin >> A >> B;
		arr.push_back(A - B);
	}

	sort(arr.begin(), arr.end());
	if (N % 2 == 1)
		cout << 1;
	else
		cout << arr[N / 2] - arr[N / 2 - 1] + 1;
}