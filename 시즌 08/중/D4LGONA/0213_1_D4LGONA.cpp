#include <iostream>
#include <array>
using namespace std;

int main()
{
    array<pair<int, int>, 41> a;

    a.fill({0, 0});
    a[1].first = 1, a[1].second = 0;
    a[2].first = 1, a[2].second = 1;

    for (int i = 3; i < 41; ++i)
    {
        a[i].first = a[i - 1].first + a[i - 2].first;
        a[i].second = a[i - 1].second + a[i - 2].second;
    }

    a[0].second = 1;

    int T, N;
    cin >> T; // 테스트 케이스의 개수

    for (int i = 0; i < T; ++i)
    {
        cin >> N;
        cout << a[N].second << " " << a[N].first << endl;
    }
}