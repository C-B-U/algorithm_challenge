#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	int N, i, loop;
    int A[200000] = { 0 };

	scanf("%d", &N);
	for (i = 0; i < N; i++)
		scanf("%d", &A[i]);
	
    loop = N - 2;
	while (loop)
	{
		if (loop == 1)
		{
			A[0]--;
			A[N - 1]--;
		}
		else
		{
			if (A[0] >= A[N - 1])
				A[0]--;
			else
				A[N - 1]--;
		}
		loop--;
	}

	if (A[0] >= A[N - 1]){
		printf("%d", A[0]);
    }
	else{
		printf("%d", A[N - 1]);
    }
	
    return 0;
}