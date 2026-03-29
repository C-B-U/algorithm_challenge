#include <bits/stdc++.h>

#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int idx;

struct Node {
    int arr[26], finished;

    void init() {
        memset(arr, 0, sizeof(arr));
    }
} nodes[300'001];

Node *newNode() {
    nodes[idx].finished = 0;
    return &nodes[idx++];
}

int main() {
    int n;
    fastio;
    cin >> n;
    string input;
    Node *alpha = newNode();
    for (int i = 0; i < n; ++i) {
        cin >> input;
        int lng = input.length();
        bool flag = 0;
        string ans;
        Node *cur = alpha;
        for (int i = 0; i < lng; ++i) {
            if (!cur->arr[input[i] - 'a']) {
                Node *node = newNode();
                cur->arr[input[i] - 'a'] = idx - 1;
                if (!flag) {
                    flag = 1;
                    ans = input.substr(0, i + 1);
                }
            }
            cur = &nodes[cur->arr[input[i] - 'a']];
        }
        cur->finished++;
        cout << (!flag ? (cur->finished == 1 ? input : input + to_string(cur->finished)) : ans) << "\n";
    }
    return 0;
}
