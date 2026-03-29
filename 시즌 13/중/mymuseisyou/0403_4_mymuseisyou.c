#include <stdio.h>

int main() {
    int finger;
    long int times;
    long long int result;
    scanf("%d %ld", &finger, &times);
    
    if (finger == 1){
        result = 8*times;
    }
    else if (finger == 5){
        result = 8*times + 4;
    }
    else {
        result = 4*times;
        if (times%2 == 0){
            result += finger - 1;
        }
        else {
            result += 5 - finger;
        }
    }
    
    printf("%lld", result);
    
    return 0;
}