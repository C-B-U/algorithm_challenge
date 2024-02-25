#include <stdio.h>

int N, M;
int p[50], c[50];
int ans;

void init()
{
	scanf("%d", &N);
	for (int i = 0; i < N; ++i){
		
        scanf("%d", &p[i]);
		
        if (p[i] != -1) {
            ++c[p[i]];
        }
	}

	scanf("%d", &M);
}

void func(void)
{
	int i, j;

	--c[p[M]];
	for (i = 0; i < N; ++i)
	{
		if (i == M) {
            continue;
        }
		if (0 == c[i])
		{
			j = i;
			while (-1 != j && M != j) j = p[j];
			if (-1 == j) {
                ++ans;
            }
		}
	}	
}

int main(void)
{
	init();
	func();
	printf("%d\n", (N == 2) ? 1 : ans);

	return 0;
}