#include <stdio.h>

int get_length(char string[]) {
    int idx, length;
    idx = 0;
    length = 0;

    while (string[idx] != '\0') {
        length++;
        idx ++;
    }

    return length;
}

int main() {
    int N, ascii, code, length, word_leng, same;
    char encrypted[101];
    char words[20][21];
    
    scanf("%s", encrypted);
    scanf("%d", &N);
    for (int i = 0; i < N; i++) { scanf("%s", words[i]); }
    length = get_length(encrypted);

    for (int key = 0; key < 26; key++) {
        
        char decrypted[101];
        for (int j = 0; encrypted[j] != '\0'; j++) {
            ascii = encrypted[j];
            code = 97 + (((ascii - 97) + key) % 26);
            decrypted[j] = code;
        }

        for (int j = 0; j < N; j++) {
            word_leng = get_length(words[j]);
            
            for (int k = 0; k < length - word_leng + 1; k++) {
                same = 1;
                for (int l = 0; l < word_leng; l++) {
                    if (decrypted[k + l] != words[j][l]) {
                        same = 0;
                    }
                }
                if (same) {
                    printf("%s", decrypted);
                    return 0;
                }            
            }
            
        }
        
    }
    
    return 1;
}