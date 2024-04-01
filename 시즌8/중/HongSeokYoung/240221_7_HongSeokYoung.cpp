#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int n, m;
int parent[1000001];

int getParent(int x) {
    if (parent[x] == x) return x;
    return parent[x] = getParent(parent[x]);
}

void unionParent(int a, int b) {
    a = getParent(a);
    b = getParent(b);
    if (a > b) parent[a] = b;
    else parent[b] = a;
}

void findParent(int a, int b) {
    a = getParent(a);
    b = getParent(b);
    if (a == b) printf("YES\n");
    else printf("NO\n");
}

int main() {
    scanf("%d %d", &n, &m);
    
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }
    
    for (int i = 0; i < m; i++) {
        int o, a, b;
        scanf("%d %d %d", &o, &a, &b);
        
        if (!o) {
            unionParent(a, b);
        }
        else {
            findParent(a, b);
        }
    }

    return 0;
}