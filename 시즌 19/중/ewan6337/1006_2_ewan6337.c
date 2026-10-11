#include <stdio.h>
#include <stdbool.h>

int main() {
    int alphabet[26] = {0};
    char str[51];

    scanf("%50s", str);
    
    int str_len = 0;

    for(int i = 0; str[i] != '\0'; i++) {
        str_len++;
    }

    if(str_len == 1) {
        printf("%c", str[0]);
        return 0;
    }

    for(int i = 0; i < str_len; i++) {
        alphabet[str[i] - 65]++;
    }

    bool odd = false;

    for(int i = 0; i < 26; i++) {
        if(alphabet[i] % 2) {
            if(str_len % 2 && !odd) {
                odd = true;
                str[str_len / 2] = i + 65;
                alphabet[i]--;
            } else {
                printf("ERROR");
                return 0;
            }
        }
    }

    int pivot = 0;

    for(int i = 0; i < str_len / 2; i++) {
        while(alphabet[pivot] == 0) {
            pivot++;
        }
        str[i] = pivot + 65;
        str[str_len - i - 1] = pivot + 65;
        alphabet[pivot] -= 2;
    }

    printf("%s", str);
    return 0;
}
