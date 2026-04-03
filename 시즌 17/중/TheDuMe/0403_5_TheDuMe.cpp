#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Light {
    int id;
    int r;
    int c;
};

bool compareLights(const Light& a, const Light& b) {
    if (a.c == b.c) {
        return a.r < b.r;
    }
    return a.c < b.c;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int h, n;
    cin >> h >> n;

    vector<Light> lights(n);
    for (int i = 0; i < n; i++) {
        lights[i].id = i;
        cin >> lights[i].r >> lights[i].c;
    }

    sort(lights.begin(), lights.end(), compareLights);

    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        ans[lights[i].id] = i + 1; 
    }

    cout << "YES\n";
    for (int i = 0; i < n; i++) {
        cout << ans[i] << (i == n - 1 ? "" : " ");
    }
    cout << "\n";

    return 0;
}