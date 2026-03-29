// DFS보단 BFS를 선호하는데 큐는 구현이 복잡할 거 같아서 DFS로..

#include <stdio.h>

int main(void) {
    int N, S, stones[100001];
    scanf("%d", &N);
    for (int i = 0; i < N; i++) { scanf("%d", &stones[i]); }
    scanf("%d", &S);

    int stack[1024], visited[100001] = {0};
    int count, pointer, pos, next, jump;
    
    count = 0;
    
    stack[0] = S - 1;
    pointer = 1;
    
    while (pointer) {
        pos = stack[pointer - 1];
        pointer--;
        count++;

        jump = stones[pos];

        next = pos - jump;
        if ((0 <= next) && (next < N) && !visited[next]) {
            visited[next] = 1;
            stack[pointer] = next;
            pointer++;
        }

        next = pos + jump;
        if ((0 <= next) && (next < N) && !visited[next]) {
            visited[next] = 1;
            stack[pointer] = next;
            pointer++;
        }
    }

    printf("%d", count);
    
}