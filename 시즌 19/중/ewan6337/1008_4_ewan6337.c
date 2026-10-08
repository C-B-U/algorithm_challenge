#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *str;
    int pivot;
} Name;

int compare(const void *a, const void *b);

int main() {
    int num;
    char buf[52];
    fgets(buf, sizeof(buf), stdin);
    sscanf(buf, "%d", &num);

    Name* arr = (Name *)malloc(num * sizeof(Name));

    for(int i = 0; i < num; i++) {
        char *str = malloc(52 * sizeof(char));
        arr[i].str = str;
        arr[i].pivot = 0;
        fgets(str, 52, stdin);
        str[strcspn(str, "\n")] = '\0';
        
        //for(int j = 0; str[j] != '\0'; j++) printf("%c", str[j]);
        //printf("\n");

        for(int j = 0; str[j] < 'A' || str[j] > 'Z'; j++) arr[i].pivot++;
    }

    qsort(arr, num, sizeof(Name), compare);

    for(int i = 0; i < num; i++) printf("%s\n", arr[i].str);
    return 0;
}

int compare(const void *a, const void *b) {
    const Name *x = (const Name *)a;
    const Name *y = (const Name *)b;
    int index = 0;
    for(int i = 0; x->str[x->pivot + i] == y->str[y->pivot + i]; i++) index++;
    return x->str[x->pivot + index] - y->str[y->pivot + index];
}
