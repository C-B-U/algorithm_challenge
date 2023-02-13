#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct a {
	char c;
	int con;
};
int main() {
	struct a answer[10];
	char s[251];
	int i;
	for (i = 0; i < 11; i++) {
		gets(s);
		if (s[0] == '#') break;
		answer[i].c = s[0];
		answer[i].con = 0;
		for (int j = 2; j < strlen(s); j++) {
			if (s[j] >= 65 && s[j] <= 90) {
				if (s[0] == s[j] || s[0] == s[j] + 32) {
					answer[i].con++;
				}
			}
			else if (s[j] >= 97 && s[j] <= 122) {
				if (s[0] == s[j] || s[0] == s[j] - 32) {
					answer[i].con++;
				}
			}
		}
	}
	for (int k = 0; k < i; k++) {
		printf("%c %d\n", answer[k].c, answer[k].con);
	}
	return 0;
}
