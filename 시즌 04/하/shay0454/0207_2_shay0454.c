#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main() {
	int angle[3],i=0;
	for (int i = 0; i < 3; i++) {
		scanf("%d", angle + i);
	}
	if (angle[0] + angle[1] + angle[2] != 180) printf("Error");
	else {
		if (angle[0] == angle[1]&& angle[1]==angle[2]) printf("Equilateral");
		else if (angle[1] == angle[2]||angle[2]==angle[0]||angle[0]==angle[1]) printf("Isosceles");
		else printf("Scalene");
	}
	return 0;
}
