#include<iostream>
using namespace std;

bool a[100][100];

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x, y;
    cin >> n;

    int sum = 0;
    while (n--) 
    {
        cin >> x >> y;
        for (int i = y; i < y + 10; i++) 
        {
            for (int j = x; j < x + 10; j++) 
            {
                if (!a[i][j]) 
                {
                    a[i][j] = true;
                    sum++;
                }
            }
        }
    }

    cout << sum;
}
