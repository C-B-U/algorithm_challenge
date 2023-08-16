#include<iostream>
#include<vector>
#include<map>
using namespace std;
int main() {
	ios::sync_with_stdio(0);cin.tie(0);							//시간 줄이기 용
	int N, count_ = 0;
	pair<int, int> purpose,one,pairs[3]; cin >> N >> purpose.first >> purpose.second;	// pair 생성
	vector<pair<int, int>> v;								// 체크용 vector 생성
	multimap<pair<int, int>, bool> m;							// multimap 생성, map의 find 함수의 시간복잡도는 O(log n)
	for (int i = 0; i < N; i++) { cin >> one.first >> one.second; m.insert({ one,i }); v.push_back(one); }
	for (auto a = v.begin(); a != v.end(); a++) {
		pairs[0] = {a->first,a->second + purpose.second};
		pairs[1] = {a->first + purpose.first,a->second};
		pairs[2] = {a->first + purpose.first,a->second + purpose.second};
		if (m.find(pairs[0]) != m.end() && m.find(pairs[1]) != m.end() && m.find(pairs[2]) != m.end())count_++;
	}											// 현 점에 대해 관련 점들이 존재하는지 확인
	cout << count_;
	return 0;										// 최적의 방법은 아님, 시간 : 676ms
}												// 같은 언어의 최적 : 196ms, 평균 : 약 500ms
