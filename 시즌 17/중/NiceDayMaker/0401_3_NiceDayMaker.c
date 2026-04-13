#include <stdio.h>

int main(){
    int n, m, t1, t2, t3, t4, res = 1;
    
    scanf("%d %d", &n, &m);

    t1 = n;
	t2 = n / 2;
	t3 = (n + 1) / 2;
	t4 = (n - 1) / 3 + 1;

	if (t1 <= m) res++;
	if (n > 1 && t2 <= m) res++;
	if (n > 1 && t3 <= m) res++;
	if (n > 2 && t4 <= m) res++;
	if (n >= 3 && t2 + t4 <= m) res++;
	if (n >= 3 && t3 + t4 <= m) res++;
	if (n >= 3 && t1 + t4 <= m) res++;

    printf("%d", res);
}