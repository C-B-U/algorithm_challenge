#include <stdio.h>
#include <stdlib.h>
#define MAX_NODES 100

typedef struct {
	int node_count;
	int** list;
}Graph;

typedef struct {
	int queue[MAX_NODES];
	int front;
	int rear;
}Queue;

void queue_init(Queue* q) {
	q->front = 0;
	q->rear = 0;
}

bool is_empty(Queue* q) {
	return q->front == q->rear;
}

bool is_full(Queue* q) {
	return (q->rear + 1) % MAX_NODES == q->front;
}

void enqueue(Queue* q, int num) {
	if (is_full(q)) return;
	q->rear = (q->rear + 1) % MAX_NODES;
	q->queue[q->rear] = num;
}

int dequeue(Queue* q) {
	if (is_empty(q)) return -1;
	q->front = (q->front + 1) % MAX_NODES;
	return q->queue[q->front];
}

int bfs(Graph* g, int k) {
	int pre, count = 0, wave = 1;
	bool visit[MAX_NODES] = { false };
	Queue q;
	queue_init(&q);
	visit[k] = true;
	enqueue(&q, k);
	pre = k;
	while (!is_empty(&q)) {
		int cur = dequeue(&q);
		for (int i = 0; i < g->node_count; i++) {
			if (g->list[cur][i] && !visit[i]) {
				visit[i] = true;
				enqueue(&q, i);
				count += wave;
			}
		}
		if (pre == cur) {
			wave++;
			pre = q.queue[q.rear];
		}
	}
	return count;
}

int main() {
	int n, m, i, kevin_bacon, min = MAX_NODES;
	scanf("%d %d", &n, &m);
	Graph g;
	g.node_count = n;
	g.list = (int**)malloc(sizeof(int*) * n);
	for (i = 0; i < n; i++) g.list[i] = (int*)calloc(n, sizeof(int));
	for (i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		g.list[a - 1][b - 1] = 1;
		g.list[b - 1][a - 1] = 1;
	}
	for (i = 0; i < n; i++) {
		int x = bfs(&g, i);
		if (x < min) {
			kevin_bacon = i + 1;
			min = x;
		}
	}
	printf("%d\n", kevin_bacon);
	return 0;
}
