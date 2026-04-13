#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    int a1{n};
    int a2{n / 2};
    int a3{(n + 1) / 2};
    int a4{(n + 2) / 3};

    int c{1};

    /*
    n=1
    0 -> 0
    1 -> 1
    
    n=2
    0 -> 00
    1 -> 11
    1 2 -> 10
    1 3 -> 01
    1 4 -> 01
    2 -> 01
    2 3 -> 11
    2 4 -> 11
    3 -> 10
    4 -> 10
    
    n>=3
    0 -> 000
    1 -> 111
    1 2 -> 101
    1 3 -> 010
    1 4 -> 011
    1 2 4 -> 001
    1 3 4 -> 110
    2 -> 010
    2 3 -> 111
    2 4 -> 110
    2 3 4 -> 011
    3 -> 101
    3 4 -> 001
    4 -> 100
    */
   
    if (n == 1) {
        if (m > 0) c++;
    }
    else if (n == 2) {
        if (min(a1 + a2, min(a1 + a4, a2)) <= m) c++;
        if (min(a1 + a2, min(a3, a4)) <= m) c++;
        if (min(a1, min(a2 + a3, a2 + a4)) <= m) c++;
    }
    else {
        if (min(a1 + a2 + a4, a3 + a4) <= m) c++;
        if (min(a1 + a3, a2) <= m) c++;
        if (min(a1 + a4, a2 + a3 + a4) <= m) c++;
        if (a4 <= m) c++;
        if (min(a1 + a2, a3) <= m) c++;
        if (min(a1 + a3 + a4, a2 + a4) <= m) c++;
        if (min(a1, a2 + a3) <= m) c++;
    }

    cout << c << '\n';

    return 0;
}