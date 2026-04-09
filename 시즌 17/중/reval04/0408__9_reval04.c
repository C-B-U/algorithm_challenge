#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include<math.h>

int compare(const void* a, const void* b) {
	return *(int*)b - *(int*)a;
}
int main(){
	int n;
	int alpha[27] = {0};//weight[0] = A, weight[26] = Z
	char temp[9] = {0};
	int templen;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s", temp);
		templen = strlen(temp);
		for (int j = 0; j < templen;j++) {//A=65,Z:90
			alpha[temp[j] - 'A'] += (int)pow(10, (templen - j - 1));
		}
	}
	qsort(alpha, 26, sizeof(int),compare);

	int sum = 0;
	int weight = 9;
	for (int i = 0; i < 26; i++) {
		if (alpha[i] == 0)
			break;
		sum += alpha[i] * weight;
		weight--;
	}
	printf("%d\n", sum);
}
