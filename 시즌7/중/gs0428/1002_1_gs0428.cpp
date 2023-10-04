#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, M;
    cin >> N >> M;
    char arr[N+1][M+1];
    int min = 32;

    for(int i = 1;i<=N;i++) {
        for(int k = 1;k<=M;k++) {
            cin >> arr[i][k];
        }
    }

    for(int i = 1;i<=N-7;i++) {
        for(int k = 1;k<=M-7;k++) {
            int cnt = 0;
            char start;
            if(start = 'W') {
                for(int x = i;x<=i+7;x++) {
                    for(int y = k;y<=k+7;y++) {
                        if(arr[x][y] != start)
                            cnt++;
                        if(y != k + 7)
                            start = start == 'W' ? 'B' : 'W';
                    }
                }
            }
            if(cnt < min)
                min = cnt;
            cnt = 0;
            if(start = 'B') {
                for(int x = i;x<=i+7;x++) {
                    for(int y = k;y<=k+7;y++) {
                        if(arr[x][y] != start)
                            cnt++;
                        if(y != k + 7)
                            start = start == 'W' ? 'B' : 'W';
                    }
                }
            }
            if(cnt < min)
                min = cnt;
        }
    }

    cout << min;


    return 0;
}

