#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;

    vector<int> v(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    size_t exp = 0;
    for (int i = 0; i < n; ++i) 
    {
        exp += (size_t)v[i] * min(k, i);
    }

    cout << exp << endl;
}