//https://www.acmicpc.net/problem/2108
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N;
	cin>>N;
	int sum = 0;
	int cntmax = 0;
	int val = 0;
	vector<int> n(N); // 값을 저장할 벡터
	vector<int> cnt(8001);//최빈값을 계산할 벡터
	for (int i = 0; i < N; i++) {
		cin >> n[i];
		sum += n[i];
		cnt[n[i] + 4000]++;
	}
	sort(n.begin(), n.end());
	//최빈값 중 가장 작은 값
	for (int i = 0; i <= 8000; ++i) {
		if (cnt[i] > cntmax) {
			cntmax = cnt[i];
			val = i;
		}
	}

	//두번쨰로 작은 최빈값
	for (int i = val + 1; i <= 8000; ++i) {
		if (cnt[i] == cntmax) {
			val = i;
			break;
		}
	}
	sum = round(double(sum) / N); // 산술평균 구하기
	cout << sum <<"\n";
	cout << n[(N-1)/2]<<"\n";
	cout << val - 4000 << "\n";
	cout << n[N-1]-n[0];
}
