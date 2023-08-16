#include<iostream>
#include<vector>
#include<map>
using namespace std;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int N, count_ = 0; pair<int, int> purpose,one; cin >> N >> purpose.first >> purpose.second;
	vector<pair<int, int>> v;
	multimap<pair<int, int>, bool> m;
	for (int i = 0; i < N; i++) { cin >> one.first >> one.second; m.insert({ one,i }); v.push_back(one); }
	for (auto a = v.begin(); a != v.end(); a++) {
		if (m.find({ a->first,a->second + purpose.second }) != m.end() && m.find({ a->first + purpose.first, a->second }) != m.end() && m.find({ a->first + purpose.first,a->second + purpose.second }) != m.end())count_++;
	}
	cout << count_;
	return 0;
}
