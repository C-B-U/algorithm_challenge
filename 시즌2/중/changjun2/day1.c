#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


void main()
{
	int num;
	

	scanf("%d",&num);

	int* arr = malloc(sizeof(int) * num);

	for (int i = 0; i < num; i++) //배열 입력
	{
		int a;
		scanf("%d",&a);

		arr[i] = a;

	}

	
	for (int i = 0; i < num; i++) 
	{
		int count = 0;
		for (int j = 0; j < num; j++) //작은 좌표갯수 세기
		{		
			if (arr[i] > arr[j])
			{
				count++;
			}
			
		}
		int* arr2 = malloc(sizeof(int) * count); //중복좌표제거 배열생성

		int a = 0;
		for (int j = 0; j < num; j++) //중복좌표배열 입력
		{
			for (int k = 0; k < num; k++)
			{
				if (arr[j] > arr[k])
				{
					arr2[a] = arr[k];
					a++;
				}
			}
		}
		int c_n = count; 
		for (int k = 0; k < c_n-1; k++) //중복좌표 제거
		{
			if (arr2[k] == arr2[k + 1])
			{
				count--;
			}
		}
		
		printf("%d ", count);
	}



	return 0;
}
