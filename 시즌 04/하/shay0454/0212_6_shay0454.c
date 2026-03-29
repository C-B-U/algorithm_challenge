#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main() {
	char x[81], y[81];
	char* a = (char*)calloc(82, sizeof(char));
	char* b = (char*)calloc(82, sizeof(char));
	char* b1 = x, * b2 = y;
	int count = 0, m = 48, n = 0, nm = 0;
	char q;
	scanf("%s", x);
	scanf("%s", y);
	if (strlen(b1) < strlen(b2))  b1 = y, b2 = x;
	for (int i = 0; i < strlen(b1); i++) {
		a[i] = b1[strlen(b1) - i - 1];
	}
	for (int i = 0; i < strlen(b2); i++) {
		b[i] = b2[strlen(b2) - i - 1];
	}
	
	while (count<strlen(b1)) {
		a[count] += b[count] - m;
		if (a[count] > 49) {
			a[count] -= 2;
			a[count + 1]++;
		}
		count++;
		if (count == strlen(b2)) m = 0;
	}
	if (a[strlen(a) - 1] == 1) a[strlen(a) - 1] = '1';
	else if (a[strlen(a) - 1] == '2') a[strlen(a) - 1] = '0', a[strlen(a)] = '1';
	for (int i = 0; i < strlen(a) / 2; i++) {
		q = a[i];
		a[i] = a[strlen(a) - 1 - i];
		a[strlen(a) - 1 - i] = q;
	}
	int xm = strlen(a);
	for (int i = 0; i < xm; i++) {
		if (a[i] == '0') n++;
		else if (a[i] == '1') {
			nm++;  break;
		}
	}
	if (nm == 0) printf("0");
	else printf("%s",a+n);
	free(a);
	free(b);
	return 0;
	
}
