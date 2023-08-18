#include<iostream>
using namespace std;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);							// 시간 줄이기용
	int N, S, sum, sumOfList[100002] = { 0, },min=0; cin >> N >> S;				// 입력
	for (int i = 1; i <= N; i++) { cin >> sumOfList[i]; sumOfList[i] += sumOfList[i - 1]; }	// 원소 입력 후 현 index에 index-1의 값 더하기
	int* start = sumOfList, * end = start;							// 비교용 포인터 (두 포인터)
	while (end != sumOfList + N + 1) {
		sum = *(end)-*(start);								// 두 포인터의 값 차이로 계산
		if (sum < S) end++;								// 작으면 end++
		else {
			if (min == 0 || min > (end - start))min = (end - start);		// 두 index의 차이가 min보다 낮거나 기록이 없으면 (0) min 초기화
			start++;								// 크면 start++
		}
	}
	cout << min;										// min 출력
	return 0;
}
