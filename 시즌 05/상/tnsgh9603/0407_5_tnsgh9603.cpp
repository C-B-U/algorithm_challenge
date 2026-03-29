#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
bool P[2501][2501];
int dp[2501];
int main() {
	fastio;
	string s;
	cin >> s;
	s = " " + s;
	int len = s.length() - 1;
	for (int i = 1; i <= len; ++i) {
		P[i][i] = 1;
	}
	for (int i = 1; i < len; ++i) {
		if(s[i] == s[i + 1]) {
			P[i][i + 1] = 1;
		}
	}
	for (int i = 3; i <= len; ++i) {
        for (int st = 1; st + i - 1 <= len; ++st){
            int en = st + i - 1;
            if (s[st] == s[en] && P[st + 1][en - 1]) {
				      P[st][en] = 1;
			      }
        }
  }
	for (int en = 1; en <= len; ++en){
        dp[en] = 987654321;
        for (int st = 1; st <= en; ++st){
            if (P[st][en]) {
                dp[en] = min(dp[en], dp[st - 1] + 1);
            }
        }
    }
    cout << dp[len];
	  return 0;
}
