// 백준 알고리즘 '10828번 스택' 문제

#include <stdio.h>
#include <string.h>

#define MAX 10000

int stack[MAX];
int stack_top = -1;

void push(int x) {
    stack[++stack_top] = x;
}

int pop() {
    if (stack_top == -1) {
        return -1;
    } else {
        return stack[stack_top--];
    }
}

int size() {
    return stack_top + 1;
}

int empty() {
    return stack_top == -1 ? 1 : 0;
}

int top() {
    if (stack_top == -1) {
        return -1;
    } else {
        return stack[stack_top];
    }
}

int main() {
    int n;
    scanf("%d", &n);

    char command[10];
    int value;

    for (int i = 0; i < n; i++) {
        scanf("%s", command);

        if (strcmp(command, "push") == 0) {
            scanf("%d", &value);
            push(value);
        } else if (strcmp(command, "pop") == 0) {
            printf("%d\n", pop());
        } else if (strcmp(command, "size") == 0) {
            printf("%d\n", size());
        } else if (strcmp(command, "empty") == 0) {
            printf("%d\n", empty());
        } else if (strcmp(command, "top") == 0) {
            printf("%d\n", top());
        }
    }

    return 0;
}
