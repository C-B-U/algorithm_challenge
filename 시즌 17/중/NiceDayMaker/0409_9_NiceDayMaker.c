#include <stdio.h>
#include <stdlib.h>

char arr[10][9];
int len[10];
int rep[26];

int compare(const void *a, const void *b)
{
    return(*(int*)b - *(int*)a);
}

int main()
{
    int n, cal, ans = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%s", arr[i]);
        len[i] = strlen(arr[i]);
    }
    
    for(int i=0; i<n; i++){
        cal = 1;
        for(int j=len[i]-1; j>=0; j--){
            rep[arr[i][j]-'A'] += cal;
            cal *= 10;
        }
    }
    qsort(rep, 10, sizeof(int), compare);

    for(int i=0; i<10; i++){
        ans += rep[i] * (9-i);
    }

    printf("%d", ans);
    return 0;
}
