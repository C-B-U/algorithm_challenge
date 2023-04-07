//방문을 기록, 반복문을 통해 방문하지 않은 좌표 bfs에 넣어주기
// bfs가 실행된 횟수 : 나줘진 영역의 수
// 영역의 넓이 : bfs구현시 다음좌표 탐색 cnt++, bfs 종료시 vector에 저장, 출력 전 오름차순 정렬

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int dx[] = { 0,0,-1,1 }; //좌우상하
int dy[] = { 1,-1,0,0 }; //좌우상하
int M, N, K; // M:세로, N:가로, K: 직사각형 개수
int a, b, c, d;
int ans = 0;
bool visit[101][101];
vector<int> area;

void bfs(int a1, int b1) {
	queue<pair<int, int>> q;
	q.push(make_pair(a1, b1));
    visit[a1][b1] = true;
    int cnt = 1;
    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int n_x = x + dx[i];
            int n_y = y + dy[i];
            if (n_x < N && n_x >= 0 && n_y < M && n_y >= 0) {
                if (!visit[n_y][n_x]) {
                    q.push(make_pair(n_y, n_x));
                    visit[n_y][n_x] = true;
                    cnt++; //영역넓이 + 1
                }
            }
        }
    }
    area.push_back(cnt);
}
int main() {
    cin >> M >> N >> K;
    for (int i = 0; i < K; i++) {
        cin >> a >> b >> c >> d;
        for (int r = b; r < d; r++) { // 좌표 환산 
            for (int l = a; l < c; l++) { // 좌표 환산
                visit[r][l] = true; //색칠 된 부분 방문처리
            }
        }
    }
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (!visit[i][j]) {
                bfs(i, j);
                ans++; //bfs 실행 횟수가 영역의 수
            }
        }
    }
    cout << ans << '\n';
    sort(area.begin(), area.end());
    for (int i = 0; i < area.size(); i++) {
        cout << area[i] << " ";
    }
    return 0;
}
