#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX 100000

int main() {
    bool visit[MAX + 1]{false};

	int n, k;
	cin >> n >> k;

	queue<pair<int, int>> q;
	q.push({ n, 0 });
	visit[n] = true;

    while (!q.empty()) {
        int current = q.front().first;
        int time = q.front().second;
        q.pop();

        if (current == k) {
            cout << time << endl;
            break;
        }

        if (current - 1 >= 0 && !visit[current - 1]) {
            q.push({ current - 1, time + 1 });
            visit[current - 1] = true;
        }
        if (current + 1 <= MAX && !visit[current + 1]) {
            q.push({ current + 1, time + 1 });
            visit[current + 1] = true;
        }
        if (current * 2 <= MAX && !visit[current * 2]) {
            q.push({ current * 2, time + 1 });
            visit[current * 2] = true;
        }
    }
}
