#include <stdio.h>
#include<string.h>
#define _CRT_SECURE_NO_WARNINGS

int main(void) {

	int K = 0;
	
	scanf("%d", &K);

	int H[100000];
	
	for (int i = 0; i < K; ++i) {
		
		scanf("%d", &H[i]);
	
		char behavior[100];

		scanf("%s", behavior, 100);
		
		int len = strlen(behavior);

		for (int j = 0; j < len; ++j) {
			if (behavior[j] == 'c')
				++H[i];
			else if (behavior[j] == 'b')
				--H[i];
			if (H[i] <= 0)
				break;
		}
	}

	for (int i = 0; i < K; ++i) {
		if (i != 0)
			printf("\n\n");
		printf("Data Set %d:\n", i+1);
		printf("%d", H[i]);
	}

	return 0;
}