#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main() {
    char S[1001], T[1001], answer[1001];
    scanf("%s %s", S, T);

    int slen = strlen(S);
    int left = 0;
    int right = strlen(T) - 1;
    bool is_reversed = false; 


    while ((right - left + 1) > slen) {
        if (!is_reversed) {

            if (T[right] == 'A') {
                right--;
            }
            else { 
                right--;
                is_reversed = true; 
            }
        }
        else {

            if (T[left] == 'A') {
                left++;
            }
            else { 
                left++;
                is_reversed = false;
            }
        }
    }

    int idx = 0;
    if (!is_reversed) {
        for (int i = left; i <= right; i++) answer[idx++] = T[i];
    }
    else {
        for (int i = right; i >= left; i--) answer[idx++] = T[i];
    }
    answer[idx] = '\0';

    if (strcmp(answer, S) == 0) printf("1\n");
    else printf("0\n");

    return 0;
}
