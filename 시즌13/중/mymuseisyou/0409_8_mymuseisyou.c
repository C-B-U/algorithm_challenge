#include <stdio.h>

int makeKey (int x, int y){
    long long key = (((long long)(x + 1000000000)) << 32) | (y + 1000000000);
    return (int)(key % 1048583);
}

int main() {
    int n, a, b, i, j;
    int x, y;
    scanf("%d\n%d %d", &n, &a, &b);
    int hashmap[1048583][2] = { { 0, }, };
    int list[n][2];
    int key, key1, key2, key3;
    int check1, check2, check3;
    int count = 0;
    
    for(i=0;i<n;i++){
        scanf("%d %d", &x, &y);
        key = makeKey(x, y);
        j = 0;
        while (1){
            if(hashmap[key+j][0] == 0 && hashmap[key+j][1] == 0){
                hashmap[key+j][0] = x;
                hashmap[key+j][1] = y;
                break;
            }
            j++;
        }
        
        list[i][0] = x;
        list[i][1] = y;
    }
    
    for(i=0;i<n;i++){
        check1 = 0; check2 = 0; check3 = 0;
        
        key1 = makeKey(list[i][0]+a, list[i][1]);
        key2 = makeKey(list[i][0], list[i][1]+b);
        key3 = makeKey(list[i][0]+a, list[i][1]+b);
        
        if (list[i][0]+a == hashmap[key1][0] && list[i][1] == hashmap[key1][1]) check1 = 1;
        else{
            j = 0;
            while (1){
                if(hashmap[key1+j][0] == 0 && hashmap[key1+j][1] == 0) break;
                else if(list[i][0]+a == hashmap[key1+j][0] && list[i][1] == hashmap[key1+j][1]) check1 = 1;
                j++;
            }
        }
        
        if (list[i][0] == hashmap[key2][0] && list[i][1]+b == hashmap[key2][1]) check2 = 1;
        else{
            j = 0;
            while (1){
                if(hashmap[key2+j][0] == 0 && hashmap[key2+j][1] == 0) break;
                else if(list[i][0] == hashmap[key2+j][0] && list[i][1]+b == hashmap[key2+j][1]) check2 = 1;
                j++;
            }
        }
        
        if (list[i][0]+a == hashmap[key3][0] && list[i][1]+b == hashmap[key3][1]) check3 = 1;
        else{
            j = 0;
            while (1){
                if(hashmap[key3+j][0] == 0 && hashmap[key3+j][1] == 0) break;
                else if(list[i][0]+a == hashmap[key3+j][0] && list[i][1]+b == hashmap[key3+j][1]) check3 = 1;
                j++;
            }
        }
        
        if((check1 && check2) && check3) count++;
    }
    
    printf("%d", count);
}