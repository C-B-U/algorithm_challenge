#include <iostream>

using namespace std;

int main()
{
    int i, N, a, b, d, f[50];

    cin >> N;
    for (i = 0; i < N; i++) cin >> f[i];

    if (N == 1) cout << 'A', exit(0);
    if (N == 2 && f[1] != f[0]) cout << 'A', exit(0);

    d = f[1] - f[0];

    for (i = 1; i < N; i++) {
        if (!d && f[i] != f[0]) cout << 'B', exit(0);
    }

    if (!d) cout << f[0], exit(0);
    if ((f[2] - f[1]) % d != 0) cout << 'B', exit(0);

    a = (f[2] - f[1])/d;
    b = f[1] - f[0]*a;

    for (i = 1; i < N; i++) {
        if (f[i] != f[i-1]*a + b) cout << 'B', exit(0);
    }

    cout << f[N-1]*a + b;

    return 0;
}
