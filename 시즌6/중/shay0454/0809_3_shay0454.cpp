#include<iostream>
#include<algorithm>
using namespace std;
int N,list[1000000];
int find_triangle() {
	for (int i = N - 1; i > 1; i--) {                  // 삼각형의 성립조건 : 세 변 중 가장 긴 변의 나머지 변들의 합 보다 작으면 삼각형이 성립 
		if (list[i] < list[i - 1] + list[i - 2])         // sort()함수로 정렬시키고 최대값을 찾아야하기에 가장 큰 빨대 3개 부터 찾기
			return list[i] + list[i - 1] + list[i - 2];
	}
	return -1;                                         // for문을 다 돌려도 안 나오면 return -1;
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0);               // 요약 : 시간 줄이기 용
	cin >> N;
	for (int i = 0; i < N; i++)cin >> list[i];
	sort(list, list + N);                              // sort()함수는 시작지점부터 종료시점-1까지 sort해주는 것을 기억하자
	cout << find_triangle();                           // 예시로 sort()함수를 사용해 stl vector(v라 선언)를 sort할려면 sort(v.begin(),v.end())이다.
	return 0;                                          // 이때 v.begin()은 v의 처음을 가리키고, v.end()는 v의 마지막+1을 가리킨다. 기억하자
}                                                    // 이 때문에 왜 안 되지 하고 시간 날리지 말자
