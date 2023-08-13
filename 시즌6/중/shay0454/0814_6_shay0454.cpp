#include<iostream>
#include<math.h>
#include<algorithm>
using namespace std;
typedef struct point{
	double DurationOfTime;                                      // 소요시간
	int num;                                                    // 로봇의 번호
};
point pointList[100000];                                      // 로봇의 소요시간과 번호에 대한 배열
bool more_faster(point first, point second) {                 // 비교 함수
	if (first.DurationOfTime == second.DurationOfTime) {        // 같으면 로봇의 번호 비교
		return first.num < second.num;
	}
	else return first.DurationOfTime < second.DurationOfTime;   // 아니면 소요시간 비교
} 
int main() {
	ios::sync_with_stdio(0); cin.tie(0);                        // 대충 시간 줄이기용
	int N, x, y, v; cin >> N;                                   // 받을 변수
	for (int i = 0; i < N; i++) {
		cin >> x >> y >> v;                                       // 로봇의 위치와 미사일의 속도 입력
		pointList[i].num = i + 1;                                 // 로봇의 번호 부여
		pointList[i].DurationOfTime = sqrt(x * x + y * y) / v;    // 소요시간 초기화
	}
	sort(pointList, pointList + N,more_faster);                 // sort
	for (int i = 0; i < N; i++)cout << pointList[i].num<<'\n';  // sort된 배열 각각 출력
	return 0;
}
