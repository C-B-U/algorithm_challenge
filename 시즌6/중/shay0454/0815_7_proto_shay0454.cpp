#include<iostream>
using namespace std;
bool truth_table[2000];
int main() {
	int N, L, num, count_ = 0; fill_n(truth_table, 1000, true);
	cin >> N >> L;
	for (int i = 0; i < N; i++) { cin >> num; truth_table[num - 1] = false; }
	for (int i = 0; i < 1000; i++) {
		if (truth_table[i] == false) { fill_n(truth_table + i, L,true); count_++;	 }
	}
	cout << count_;
	return 0;
}
