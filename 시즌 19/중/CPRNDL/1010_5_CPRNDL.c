//명령을 받지 않는 정렬된 뒷부분 수를 셈
#include <stdio.h>
int main()
{
	int n, arr[100000], a = 1;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	int i = n - 1;
	while (arr[i - 1] < arr[i])
	{
		a++;
		i--;
	}
	printf("%d", n - a);
	return 0;
}
