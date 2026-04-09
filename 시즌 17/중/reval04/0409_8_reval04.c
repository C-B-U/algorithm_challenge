#include <stdio.h>

#define MAXN 200005

long long prefix_bonus[MAXN];
long long suffix[MAXN];       

int N;
long long K, X;
long long a[MAXN];

int canTake(int D) {
  for (int i = 0; i <= N - D; i++) {
        long long before = prefix_bonus[i];    
        long long after  = suffix[i + D + 1];   
        if (before + after >= K) return 1;     
    }
    return 0; 
}

int main(void) {
    scanf("%d %lld %lld", &N, &K, &X);
    for (int i = 1; i <= N; i++) {
        scanf("%lld", &a[i]);
    }


    prefix_bonus[0] = 0;
    for (int i = 1; i <= N; i++) {
        prefix_bonus[i] = prefix_bonus[i-1] + a[i] * X;
    }


    suffix[N+1] = 0;
    for (int i = N; i >= 1; i--) {
        suffix[i] = suffix[i+1] + a[i];
    }

    int lo = 1, hi = N - 1, ans = -1;


    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (canTake(mid)) {
            ans = mid;  
            lo = mid + 1;
        } else {
            hi = mid - 1; 
        }
    }

    printf("%d\n", ans);

    return 0;
}
