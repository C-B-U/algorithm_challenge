#include <iostream>
#include <algorithm>
// RGB거리
/*
RGB거리에는 집이 N개 있다. 거리는 선분으로 나타낼 수 있고, 1번 집부터 N번 집이 순서대로 있다.

집은 빨강, 초록, 파랑 중 하나의 색으로 칠해야 한다. 각각의 집을 빨강, 초록, 파랑으로 칠하는 비용이 주어졌을 때, 아래 규칙을 만족하면서 모든 집을 칠하는 비용의 최솟값을 구해보자.

1번 집의 색은 2번 집의 색과 같지 않아야 한다.
N번 집의 색은 N-1번 집의 색과 같지 않아야 한다.
i(2 ≤ i ≤ N-1)번 집의 색은 i-1번, i+1번 집의 색과 같지 않아야 한다.
*/

using namespace std;

int d[1001][3];

int main() {
    int N;
    cin >> N;

    d[0][0] = 0;
    d[0][1] = 0;
    d[0][2] = 0;
    int cost[3];
    for (int i = 1; i <= N; ++i)
    {
        cin >> cost[0] >> cost[1] >> cost[2];
        d[i][0] = min(d[i - 1][1], d[i - 1][2]) + cost[0];
        d[i][1] = min(d[i - 1][0], d[i - 1][2]) + cost[1];
        d[i][2] = min(d[i - 1][1], d[i - 1][0]) + cost[2];
    }

    cout << min(d[N][2], min(d[N][0], d[N][1])) << endl;
}