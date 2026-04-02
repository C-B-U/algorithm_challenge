#include <stdio.h>

int main(void){
    int x;
    scanf("%d", &x);
    
    if (x % 2 == 1){
        printf("Goose");
    }
    else {
        printf("Duck");
    }
    return 0;
}
