#include<iostream>
#include<queue>
using namespace std;
int arr[1000001];
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	fill_n(arr, 1000001, -1);
	int num, temp; cin >> num; arr[num] = 0;
	queue<int> q; q.push(num);
	while (!(arr[1]+1)) {
		temp = q.front(); q.pop();
		if (temp % 2 == 0 && arr[temp / 2] < arr[temp]) { arr[temp / 2] = arr[temp] + 1; q.push(temp / 2); }
		if (temp % 3 == 0 && arr[temp / 3] < arr[temp]) { arr[temp / 3] = arr[temp] + 1; q.push(temp / 3); }
		if (arr[temp - 1] < arr[temp]) { arr[temp - 1] = arr[temp] + 1; q.push(temp - 1); }
	}
	cout << arr[1];
	return 0;
}
