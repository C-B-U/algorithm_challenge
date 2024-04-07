//10246

#include <stdio.h>
#define MAX 1000000

int main()
{
    int arr[MAX+1] = {0};
    int i,j;

    for(i = 2; i <= MAX; i++){
        int buffer = 0;
        for(j = i; j <= MAX; j++){
            buffer += j;
            if(buffer > MAX){
                break;
            }
            arr[buffer] += 1;
        }
    }

    while(1){
        int price;
        
        scanf("%d", &price);
        
        if(price == 0){
            break;
        }
        printf("%d\n", arr[price]);
    }

    return 0;
}