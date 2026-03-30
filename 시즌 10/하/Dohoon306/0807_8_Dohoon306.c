#include<stdio.h>
#define QUATER 25
#define DIME 10
#define NICKEL 5
#define PENNY 1

int main() {
    int n, change, quater, dime, nickel, penny;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &change);
        quater = change / QUATER;
        change = change - QUATER * quater;
        dime = change / DIME;
        change = change - DIME * dime;
        nickel = change / NICKEL;
        change = change - NICKEL * nickel;
        penny = change / PENNY;
        printf("%d %d %d %d\n", quater, dime, nickel, penny);
    }
}
