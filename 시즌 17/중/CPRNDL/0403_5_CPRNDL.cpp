#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

typedef struct {
    int row;
    int col;
    int index;
    int b;
} Lights;

bool comp1(Lights a, Lights b) {
    return a.col < b.col;
}

bool comp2(Lights a, Lights b) {
    return a.index < b.index;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Lights light[200000];
    int res_col[200000] = {0};

    int h, n;
    cin >> h >> n;

    for (int i = 0; i < n; i++) {
        cin >> light[i].row >> light[i].col;
        light[i].index = i;
    }

    sort(light, light + n, comp1);

    for (int i = 0; i < n; i++) {
        light[i].b = i + 1;
    }

    cout << "YES" << '\n';

    sort(light, light + n, comp2);

    for (int i = 0; i < n; i++) {
        cout << light[i].b << ' ';
    }

    return 0;
}