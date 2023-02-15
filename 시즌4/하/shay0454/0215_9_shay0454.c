#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
int main() {
	int n, s = 0, b = 0;
	char c[10]=" ";
	scanf("%d", &n);
	getchar();
	for(int i=0;i<n;i++){
		c[0] = getchar();
		if (c[0] == 's') {
			s++;
			fgets(c, 8, stdin);
		}
		else if (c[0] == 'b') {
			b++;
			fgets(c, 7, stdin);
		}
	}
	if (s > b) printf("security!");
	else if (s < b) { printf("bigdata?"); }
	else { printf("bigdata? security!"); }
  return 0;
}
