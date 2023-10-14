#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start;
    int end;
} Lec;

typedef struct {
    int* heap;
    int size;
} Heap;

void initHeap(Heap* h, int n) {
    h->heap = (int*)malloc(sizeof(int) * n);
    h->size = 0;
}

void push(Heap* h, int v) {
    int i = ++h->size;
    while ((i != 1) && (v < h->heap[i / 2])) {
        h->heap[i] = h->heap[i / 2];
        i /= 2;
    }
    h->heap[i] = v;
}

void pop(Heap* h) {
    int p = 1, c = 2, tmp;
    tmp = h->heap[h->size];
    h->size--;
    while (c <= h->size) {
        if ((c < h->size) && h->heap[c] > h->heap[c + 1]) c++;
        if (tmp <= h->heap[c]) break;
        h->heap[p] = h->heap[c];
        p = c;
        c *= 2;
    }
    h->heap[p] = tmp;
}

int comp(Lec* a, Lec* b) {
    if (a->start == b->start)
        return a->end - b->end;
    return a->start - b->start;
}

int main() {
    int n;
    scanf("%d", &n);

    Lec* lec = (Lec*)malloc(sizeof(Lec) * n);
    for (int i = 0; i < n; i++)
        scanf("%d %d", &lec[i].start, &lec[i].end);

    qsort(lec, n, sizeof(Lec), comp);

    Heap minQue;
    initHeap(&minQue, n);
    int size = 1;
    push(&minQue, lec[0].end);
    for (int i = 1; i < n; i++) {
        if (lec[i].start < minQue.heap[1])
            size++;
        else
            pop(&minQue);
        push(&minQue, lec[i].end);
    }

    printf("%d\n", size);
}
