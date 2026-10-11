#include <stdio.h>

int main(){
    int score;
    scanf("%d", &score);

    char arr[4] = { 'A', 'G', 'C', 'U' };
    char last;
    int num = 0;

    for(int i = 0; i < 4; i++) {
        if(score & (1 << i)) {
            last = arr[i];
            printf("%c", last);
            score &= ~(1 << i);
            num++;
        }
    }

    for(int i = 0; i < 4 - num; i++) {
        printf("%c", last);
    }

    return 0;
}
