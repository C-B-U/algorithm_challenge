#include<iostream>           // 2180KB, 52ms
#include<algorithm>
using namespace std;
void init_input(int& x, int*& list) {
	cin >> x; list = new int[x];
	for (int i = 0; i < x; i++)cin >> list[i];
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n, m, * crain_list, * box_list,*start_list,*check_list, answer = 0;
	init_input(n, crain_list);
	init_input(m, box_list);
	start_list = new int[n]; fill_n(start_list, n, 0);
	check_list = new int[m]; fill_n(check_list, m, 0);
	sort(crain_list, crain_list + n, greater<int>());
	sort(box_list, box_list + m,greater<int>());
	if (box_list[0] > crain_list[0]) { cout << -1; return 0; }
	while (start_list[0]<m) {
		for (int i = 0; i < n; i++) {
			while ((crain_list[i] < box_list[start_list[i]] || check_list[start_list[i]])&&start_list[i]<m)start_list[i]++;
			check_list[start_list[i]] = 1;
			fill(start_list + i, start_list + n, start_list[i]);
		}
		answer++;
	}
	cout << answer-1;
	return 0;
}
