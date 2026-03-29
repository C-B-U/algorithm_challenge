//제자리에 없으면 답을 1씩 증가
//제자리에 있으면 check값 1씩 감소
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N; //책의 개수
int main(void) {
	cin >> N;
	vector<int> n(N);
	for (int i = 0; i < N; i++) {
		cin >> n[i];
	}
	int check = N;
	int result = 0;
	for (int i = N - 1; i >= 0; i--) {
		if (n[i] == check) {
			check--;
		}
		else {
			result++;
		}
	}
	cout << result;
	return 0;
}
