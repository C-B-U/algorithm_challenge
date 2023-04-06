//DP 이용
//큰 문제를 작은 단위의 문제로 쪼개고,
//작은 문제들의 결과값을 배열에 저장하여 사용하는 방법을 배우기
//https://www.acmicpc.net/problem/1149

#include <iostream>
#include <algorithm>
using namespace std;
int house[1001][3]; //최소 비용 저장하기 위한 2차원 배열 생성

int main() {
    int N;// 집의 수
    int cost[3]; // rgb 칠하는 비용
    //초기화
    house[0][0] = 0;
    house[0][1] = 0;
    house[0][2] = 0;
    cin >> N;
    for (int i = 1; i <= N; ++i)
    {
        cin >> cost[0] >> cost[1] >> cost[2];
        house[i][0] = min(house[i - 1][1], house[i - 1][2]) + cost[0]; // i번집 r 칠하는 최소 비용
        house[i][1] = min(house[i - 1][0], house[i - 1][2]) + cost[1]; // i번집 g 칠하는 최소 비용
        house[i][2] = min(house[i - 1][1], house[i - 1][0]) + cost[2]; // i번집 b 칠하는 최소 비용
    }
    cout << min({ house[N][0], house[N][1], house[N][2] }); // 총 최소 비용 값 구하기
}
