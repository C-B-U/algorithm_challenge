#include <iostream>
#include <queue>
#include <string>

using namespace std;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> mi;
int P[50], arr[50];

int main() 
{
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int N, M;
    cin >> N;
    for (int i = 0; i < N; i++) 
    {
        cin >> P[i];
        mi.push({ P[i], i });
    }
    cin >> M;

    pair<int, int> cur = mi.top(); // 가장 저렴한 방 번호 저장
    if (cur.second == 0) 
    {
        mi.pop();
        if (mi.top().first > M) // 구매 불가
        { 
            cout << 0;
            return 0;
        }
    }

    string ans;
    int cnt = 0;
    M -= mi.top().first; 
    arr[cnt] = mi.top().first;
    ans += to_string(mi.top().second);
    cnt++;

    // 제일 저렴한 숫자로 남은 부분 삽입
    while (M >= cur.first) 
    { 
        M -= cur.first;
        ans += to_string(cur.second);
        arr[cnt] = cur.first;
        cnt++;
    }

    // 앞에서부터 큰 수로 바꿀 수 있는지 확인,
    int j = 0;
    while (j < ans.length())
    {
        for (int i = N - 1; i > 0; --i)
        {
            // 구매할 필요가 없는 경우
            if ((int)ans[j] - '0' >= i) 
                break;

            // 갱신할 돈을 구매할 수 있으면 구매
            if (M + arr[j] >= P[i])
            { 
                ans[j] = (char)(i + 48);
                M = M - (P[i] - arr[j]);
                arr[j] = P[i];
                break;
            }
        }

        ++j;
    }

    for (char a : ans) 
        cout << a;
}

// https://today-knowlodge.tistory.com/7