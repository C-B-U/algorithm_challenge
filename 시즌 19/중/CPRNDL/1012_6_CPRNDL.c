#include <stdio.h>
int arr[300001];
int main()
{
	int n, c = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	for (int i = n - 1; i > 0; i--)
	{
		if (arr[i - 1] > arr[i])
		{
			arr[i - 1] = arr[i];
			c++;
		}
	}
	printf("%d\n", c);
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}
