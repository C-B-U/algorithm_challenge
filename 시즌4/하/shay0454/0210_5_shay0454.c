#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main() {
	char *a= (char*)malloc(1000001),*x;
	gets(a);
	int count = 0;
	while (a!=NULL) {
		if (a[0] != ' '&&a[0]!='\0') count++;
		a = strstr(a, " ");
		if (a == NULL) break;
		else if (a[0] == ' ') a++;
	}
	printf("%d", count);
	free(a);
	return 0;
}
