#include <iostream>
#include <vector>
#include <algorithm>

// 배
/*
* 지민이는 항구에서 일한다. 그리고 화물을 배에 실어야 한다. 모든 화물은 박스에 안에 넣어져 있다. 항구에는 크레인이 N대 있고, 1분에 박스를 하나씩 배에 실을 수 있다. 모든 크레인은 동시에 움직인다.

각 크레인은 무게 제한이 있다. 이 무게 제한보다 무거운 박스는 크레인으로 움직일 수 없다. 모든 박스를 배로 옮기는데 드는 시간의 최솟값을 구하는 프로그램을 작성하시오.
*/

using namespace std;

int main() {
    int N, M;
    vector<int> crane;
    vector<int> box;

    // 입력
    cin >> N;
    for (int i = 0; i < N; i++) {
        int n;
        cin >> n;
        crane.push_back(n);
    }
    cin >> M;
    for (int i = 0; i < M; i++) {
        int m;
        cin >> m;
        box.push_back(m);
    }

    // 정렬
    sort(crane.begin(), crane.end());
    sort(box.begin(), box.end());

    // 불가능한 경우
    if (crane.back() < box.back()) {
        cout << -1;
        return 0;
    }

    int cnt = 0;
    while (!box.empty()) {
        cnt++;
        for (int i = crane.size() - 1; i >= 0; i--) {   // 가장 큰 무게부터
            for (int j = box.size() - 1; j >= 0; j--) { // 가장 큰 무게부터
                if (crane[i] >= box[j]) {               // 옮길 수 있으면 삭제
                    box.erase(box.begin() + j);
                    break;
                }
            }
        }
    }

    cout << cnt << endl;
}
