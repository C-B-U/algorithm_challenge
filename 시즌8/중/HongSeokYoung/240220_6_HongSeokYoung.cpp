#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

char inArr[11];
char newArr[11];
int check[11];
int dupli[26];
int lenArr;
int result;

void checkLuck() {
    for (int i = 0; i < lenArr - 1; i++) {
        if (newArr[i] == newArr[i + 1])
            return;
    }
    result++;
}

void dfs(int cnt) {
    if (cnt == lenArr) {
        checkLuck();
        return;
    }

    for (int i = 0; i < lenArr; i++) {
        if (check[i])
            continue;
        newArr[cnt] = inArr[i];
        check[i] = 1;
        dfs(cnt + 1);
        check[i] = 0;
    }
}

int main() {
    int dup_num = 1;

    scanf("%s", inArr);
    lenArr = strlen(inArr);

    for (int i = 0; i < lenArr; i++) {
        newArr[0] = inArr[i];
        check[i] = 1;
        dfs(1);
        check[i] = 0;
    }

    for (int i = 0; i < lenArr; i++)
        dupli[inArr[i] - 'a']++;

    for (int i = 0; i < 26; i++) {
        for (int j = 2; j <= dupli[i]; j++)
            dup_num *= j;
    }

    printf("%d\n", result / dup_num);

    return 0;
}