#include <stdio.h>
#include <stdlib.h>

int main() 
{
    int h = 0, w = 0, sum = 0;
    scanf("%d %d", &h, &w);
    
    for (int i = 0; i < h; i++) {
        char* str = (char*)malloc(sizeof(char) * w);
        scanf("%s", str);
        for (int j = 0; j < w; j++) {
            if (str[j] != '.') { // mat slash (/ or \)
                sum += 1;
                j++;
                for (;j < w; j++) {
                    if (str[j] == '.') { // mat dot (.)
                        sum += 2;
                    }
                    else { // mat slash (/ or \)
                        sum += 1;
                        break;
                    }
                }
            }
        }
    }
    printf("%d\n", sum/2);

    return 0;
}
