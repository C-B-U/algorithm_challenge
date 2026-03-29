#include <iostream>
#include <map>
#include <utility>
#include <numeric>

using namespace std;

int main()
{
    int n, max = 0;
    long ox, oy, xi, yi;

    cin >> ox >> oy >> n;

    map<pair<long, long>, int> slope[2];

    while (n--)
    {
        cin >> xi >> yi;
        if (xi == ox || yi >= oy) continue;

        long p = (xi - ox)*(xi - ox);
        long q = yi - oy;
        long g = gcd(p, q);

        int num = ++slope[xi > ox][{ p/g, q/g }];
        if (num > max) max = num;
    }

    cout << max;

    return 0;
}
