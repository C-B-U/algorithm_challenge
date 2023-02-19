#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
struct date {
	int year, month, day;
};
int main() {
	struct date d, nd;
	int month[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	int count = 0, x = 0;;
	scanf("%d %d %d", &(d.year), &(d.month), &(d.day));
	scanf("%d %d %d", &(nd.year), &(nd.month), &(nd.day));
	while (1) {
		if (d.year % 4 == 0 && !(d.year % 100 == 0)||(d.year%400==0)) {
			month[1] = 29;
		}
		else {
			month[1] = 28;
		}
		if (d.year < nd.year) {
			if (d.year + 1000 <= nd.year) {
				if (d.month < nd.month || (d.month == nd.month && d.day <= nd.day)) {
					x = 1;
					break;
				}
			}
			count += month[d.month - 1] - d.day+1;
			d.month++;
			for (int i = d.month; i <= 12; i++) {
				count += month[i - 1];
			}
			d.day = 1;
			d.month = 1;
			d.year++;
		}
		else if (d.year == nd.year) {
			if (d.month < nd.month) {
				count += month[d.month - 1] - d.day+1;
				d.day = 1;
				d.month++;
				if (d.month > 12) {
					d.year++;
					d.month = 1;
				}
			}
			else if (d.month == nd.month) {
				if (d.day > nd.day) {
					x = 1;
					break;
				}
				count += nd.day - d.day;
				break;
			}
		}
	}
	if (x == 0) printf("D-%d", count);
	else printf("gg");
}
