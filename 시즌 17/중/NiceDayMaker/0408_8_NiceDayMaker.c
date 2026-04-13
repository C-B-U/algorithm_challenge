#include <stdio.h>
#include <stdbool.h>

int N;
long long X, K;
int P[200200];

bool fn(int S)
{
    for(int i = 0; i <= N - S; i++)
    {
        if(X * P[i] + P[N] - P[i + S] >= K){
            return true;
        }
    }
    return false;
}

int main()
{
    scanf("%d %lld %lld", &N, &K, &X);
    int a[N];
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= N; i++)
    {
        P[i] = P[i - 1] + a[i - 1];
    }

    int low = 1, high = N - 1, ans = -1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (fn(mid))
        {
            ans = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    printf("%d", ans);
    return 0;
}