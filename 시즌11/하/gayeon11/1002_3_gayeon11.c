#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main() {
	int K = 0, h = 0, data[1000];
	char action[101] = "";
	scanf("%d", &K);
	for (int i = 0; i < K; i++) {
		scanf("%d", &h);
		scanf("%s", &action);
		
		for (int j = 0; j < strlen(action); j++) {
			//strlen()는 문자열 실제 길이 함수(null값 제외)
			if (action[j] == 'c') {
				h = h + 1;
			}
			else if (action[j] == 'b') {
				h = h - 1;
			}
		}
		data[i] = h;
		h = 0;
		char action[101] = "";
	}

	for (int i = 0; i < K; i++) {
		printf("Data Set %d:\n%d\n", i + 1, data[i]);
		printf("\n");
	}
	return 0;
}