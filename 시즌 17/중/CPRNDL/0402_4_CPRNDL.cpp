#include <iostream>
#include <string>
using namespace std;

typedef struct {
    string title;
    int scope;
} Condition;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    Condition con[100000];

    for (int i = 0; i < n; i++) {
        cin >> con[i].title >> con[i].scope;
        if (i > 0 && con[i].scope == con[i - 1].scope) {
            con[i].title = con[i - 1].title;
        }
    }

    for (int i = 0; i < m; i++) {
        int temp, mid, left{0}, right{n - 1}, ans{n - 1};
        cin >> temp;

        while (left <= right) {
            mid = (left + right) / 2;
            if (temp <= con[mid].scope) {
                ans = mid;
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }

        cout << con[ans].title << '\n';
    }

    return 0;
}