#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    long N;
    cin >> N;

    long A, B, C, D, E, F;
    cin >> A >> B >> C >> D >> E >> F;

    if (N == 1) {
        int total = A + B + C + D + E + F;
        int M = max({ A, B, C, D, E, F });

        cout << total - M << '\n';
    }
    else {
        long m1 = min({ A, B, C, D, E, F });
        long m2 = min({ A+B, A+C, A+D, A+E, B+C, B+D, B+F, C+E, C+F, D+E, D+F, E+F });
        long m3 = min({ A+B+C, A+B+D, A+C+E, A+D+E, B+C+F, B+D+F, C+E+F, D+E+F });
        long res = 4*m3 + (8*N - 12)*m2 + (5*N*N - 16*N + 12)*m1;

        cout << res << '\n';
    }

    return 0;
}
