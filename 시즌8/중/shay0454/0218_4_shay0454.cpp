#include<iostream>
#include<math.h>
#include<algorithm>
using namespace std;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int N, A, B, arr[50]; cin >> N;
	for (int i = 0; i < N; i++) { cin >> A >> B; arr[i] = A - B; }
	sort(arr, arr + N);
	cout << ((N % 2) ? 1 : abs(arr[N / 2] - arr[N / 2 - 1])+1);
	return 0;
}
