#include <stdio.h>

int cta(char chr) { // char to ascii
    int ascii = chr;
    return ascii;
}

int main() {
    int N, M, graph[128] = {-1};
    char a, b;
    int a_ascii, b_ascii;

    scanf("%d\n", &N);
    for (int i = 0; i < N; i++) {
        scanf("%c is %c\n", &a, &b);
        graph[cta(a)] = cta(b);
    }

    scanf("%d\n", &M);
    for (int i = 0; i < M; i++) {
        int visited[128] = {0}; // 배열 초기화 이런 방법이 있구나

        scanf("%c is %c\n", &a, &b);
        a_ascii = cta(a);
        b_ascii = cta(b);
        
        visited[a_ascii] = 1;
        
        while (a_ascii != b_ascii) {
            a_ascii = graph[a_ascii];
            if (a_ascii == -1) { break; }
            if (visited[a_ascii]) { break; }
            visited[a_ascii] = 1;
        }

        if (a_ascii == b_ascii) {
            printf("T\n");
        } else {
            printf("F\n");
        }
    }

    return 0;
}