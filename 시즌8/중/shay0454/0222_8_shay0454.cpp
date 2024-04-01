#include<iostream> //                  2184KB, 376ms
#include<algorithm>
using namespace std;
void init_input(int &x, int*& list) {
	cin >> x; list = new int[x];
	for (int i = 0; i < x; i++)cin >> list[i];
}
int binary_search(int m,int search_x,int*& list) {
	int final = m-1,first=0;
	while(final-first>1) {
		((search_x >= list[(final + first+1) / 2])?first:final) = (first + final+1) / 2;
	}
	if (search_x < list[first])return -1;
	else return (search_x >= list[final] ? final : first);
}
void remove_x(int x, int*& list, int &m) {
	swap(list[x], list[--m]);
	sort(list, list + m);
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n, m, * crane_list, * box_list, answer = 0;
	init_input(n,crane_list);
	init_input(m, box_list);
	sort(crane_list, crane_list + n, greater<int>());
	sort(box_list, box_list + m);
	if (box_list[m - 1] > crane_list[0]) { cout << -1; return 0; }
	while (m) {
		for (int i = 0,temp; i < n && m; i++) {
			if ((temp= binary_search(m, crane_list[i], box_list)) == -1)break;
			remove_x(temp, box_list, m);
		}
		answer++;
	}
	cout << answer;
	return 0;
}
