#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int i, H, Q, R;
    cin >> H >> Q >> R;

    vector<double> diff(H+3), prefix(H+2);

    while (Q--) {
        double a, b;
        cin >> a >> b;

        long h = ceil((-1 + sqrt(1 + 8*a))/2);
        long da = long(a) - h*(h-1)/2;
        long dh = (H-h+1) + 1;

        diff[da] += b/dh, diff[da + dh] -= b/dh;
    }

    for (i = 1; i <= H+1; i++) prefix[i] = prefix[i-1] + diff[i];
    for (i = 1; i <= H+1; i++) prefix[i] += prefix[i-1];

    while (R--) {
        int a, b;
        cin >> a >> b;
        cout << prefix[b] - prefix[a-1] << '\n';
    }

    return 0;
}
