#include <bits/stdc++.h>
using namespace std;

bool comp(const pair<char, int>& a, const pair<char, int>& b) {
    return a.second > b.second;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 종류를 파악하자
    // 기여도에 따라 9 - 1 순으로 배정
    int n; cin >> n;

    map<char, int> cont;

    for (int i = 0; i < n; i++) {
        string w;
        cin >> w;

        int len = w.size();

        for (int j = 0; j < len; j++) { // 기여도 계산
            int p = 1;
            for (int k = 0; k < len - 1 - j; k++) p *= 10;
            cont[w[j]] += p;
        }
    }

    // cont를 vector로 넘겨서 sort
    vector<pair<char, int>> s_cont(cont.begin(), cont.end());

    sort(s_cont.begin(), s_cont.end(), comp);

    int ans{0}, digit{9};

    // value를 s_cont 참조로 넘김
    for (auto& [ch, val] : s_cont) {
        ans += val * digit;
        digit--;
    }

    cout << ans << '\n';

    return 0;
}