#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	node* next;
}Node;

int main()
{
	int n;
	scanf("%d", &n);

	Node* head = NULL;
	Node* tail = NULL;
	Node* p = NULL;

	for (int i = 1; i <= n; ++i) {
		Node* _new = (Node*)malloc(sizeof(Node));
		_new->data = i;
		_new->next = NULL;

		if (head == NULL)
			head = _new;
		else
			tail->next = _new;
		tail = _new;
	}

	if (head == NULL) return 0;
	else {
		p = head;
		printf("%d ", p->data);

		while (p->next != NULL) {
			tail->next = p->next;
			p = p->next->next;
			tail = tail->next;
			printf("%d ", p->data);

			if (tail->data == tail->next->data) break;
		}
	}

	return 0;
}