#include<iostream>
using namespace std;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int N, S, sum, sumOfList[100002] = { 0, },min=0; cin >> N >> S;
	for (int i = 1; i <= N; i++) { cin >> sumOfList[i]; sumOfList[i] += sumOfList[i - 1]; }
	int* start = sumOfList, * end = sumOfList;
	while (end != sumOfList + N + 1) {
		sum = *(end)-*(start);
		if (sum < S) end++;
		else {
			if (min == 0 || min > (end - start))min = (end - start);
			start++;
		}
	}
	cout << min;
	return 0;
}
