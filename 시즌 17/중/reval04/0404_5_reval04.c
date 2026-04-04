#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int r, c;  
    int idx;   
} Light;

int cmp(const void* a, const void* b) {
    Light* la = (Light*)a;
    Light* lb = (Light*)b;
    if (la->c != lb->c) return (la->c > lb->c) - (la->c < lb->c);
    return (la->r > lb->r) - (la->r < lb->r);
}

int main(void) {
    int H, N;
    scanf("%d %d", &H, &N);

    Light* lights = (Light*)malloc(N * sizeof(Light));
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &lights[i].r, &lights[i].c);
        lights[i].idx = i;
    }

    qsort(lights, N, sizeof(Light), cmp);

    int* ans = (int*)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        ans[lights[i].idx] = i + 1;
    }

    printf("YES\n");
    for (int i = 0; i < N; i++) {
        printf("%d", ans[i]);
        if (i < N - 1) printf(" ");
    }
    printf("\n");

    free(lights);
    free(ans);
    return 0;
}
