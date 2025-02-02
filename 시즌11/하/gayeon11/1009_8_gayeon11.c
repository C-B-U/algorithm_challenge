#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//
//int main() {
//	int t_y, t_m, t_d, d_y, d_m, d_d;
//
//	scanf("%d %d %d", &t_y, &t_m, &t_d);
//	scanf("%d %d %d", &d_y, &d_m, &d_d);
//
//
//	return 0;
//}

#include <stdio.h>

int leap_year(int year) {
    if (year % 400 == 0) return 1;
    if (year % 100 == 0) return 0;
    if (year % 4 == 0) return 1;
    return 0;
}

int days_month(int year, int month) {
    int days_months[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (month == 2 && leap_year(year)) {
        return 29;
    }
    return days_months[month - 1];
}

int date_days(int y, int m, int d) {
    int days = 0;
    for (int i = 1; i < y; i++) {
        days += leap_year(i) ? 366 : 365; // 삼항 연산자. 조건식 ? 참일 때 값 : 거짓일 때 값; 
    }
    for (int i = 1; i < m; i++) {
        days += days_month(y, i);
    }
    days += d;
    return days;
}

int main() {
    int t_y, t_m, t_d, d_y, d_m, d_d;

    scanf("%d %d %d", &t_y, &t_m, &t_d);
    scanf("%d %d %d", &d_y, &d_m, &d_d);

    int today = date_days(t_y, t_m, t_d);
    int dday = date_days(d_y, d_m, d_d);

    int diff = dday - today;

    if (diff < 0) {
        printf("gg\n");
    }
    else if (diff > 1000) {
        printf("gg\n");
    }
    else {
        printf("D-%d\n", diff);
    }

    return 0;
}