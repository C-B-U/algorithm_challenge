#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int i;
  int j;
} Edge;

typedef struct {
  int edge_count;
  int *edge_arr;
} Page;

static inline bool is_queued(int *queue, int queue_tail, int page_number);

int main() {
  int E;
  scanf("%d", &E);

  Edge edge_arr[E];
  int N = 0;
  for (int i = 0; i < E; i++) {
    Edge *edge = &edge_arr[i];
    scanf("%d %d", &edge->i, &edge->j);
    if (edge->i > N) {
      N = edge->i;
    }
    if (edge->j > N) {
      N = edge->j;
    }
    edge->i--;
    edge->j--;
  }

  Page page_arr[N];
  for (int i = 0; i < N; i++) {
    Page *page = &page_arr[i];
    page->edge_count = 0;
    page->edge_arr = calloc(N, sizeof(int));
  }

  for (int i = 0; i < E; i++) {
    Edge *edge = &edge_arr[i];
    Page *page = &page_arr[edge->i];
    page->edge_arr[page->edge_count++] = edge->j;
  }

  int total_move = 0;
  int queue[N];
  int queue_head, queue_tail, click_count, depth_criteria;

  for (int i = 0; i < N; i++) {
    queue[0] = i;
    for (int j = 0; j < N; j++) {
      if (i == j) {
        continue;
      }
      queue_head = 0;
      queue_tail = 1;
      depth_criteria = 1;
      click_count = 1;
      while (true) {
        int target = queue[queue_head++];
        Page *page = &page_arr[target];
        for (int k = 0; k < page->edge_count; k++) {
          int next = page->edge_arr[k];
          if (next == j) {
            goto a;
          } else if (is_queued(queue, queue_tail, next)) {
            continue;
          } else {
            queue[queue_tail++] = next;
          }
        }
        if (queue_head == depth_criteria) {
          depth_criteria = queue_tail;
          click_count++;
        }
      }
    a:
      total_move += click_count;
    }
  }

  float answer = (float)total_move / (float)(N * (N - 1));

  printf("%.3f", answer);

  return 0;
}

static inline bool is_queued(int *queue, int queue_tail, int page_number) {
  for (int i = 0; i < queue_tail; i++) {
    if (queue[i] == page_number) {
      return true;
    }
  }
  return false;
}
