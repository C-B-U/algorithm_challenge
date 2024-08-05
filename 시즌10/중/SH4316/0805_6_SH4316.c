#include <stdio.h>
#include <stdlib.h>

typedef struct stack Stack;

void push(Stack* s, int value);
int pop(Stack* s);

struct stack {
    int size;
    int maxSize;
    int* value;
    void (*push)(Stack* s, int value);
    int (*pop)(Stack* s);
};

void push(Stack* s, int value) {
    if (s->size < s->maxSize) {
        s->value[s->size] = value;
        s->size++;
        return;
    }
    int* newArr = (int*)malloc(sizeof(int) * (s->maxSize * 9 / 8));
    for (int i = 0; i < s->maxSize; i++) {
        newArr[i] = s->value[i];
    }
    free(s->value);
    s->value = newArr;
    s->maxSize = (s->maxSize * 9 / 8);
    
    s->value[s->size] = value;
    s->size++;
}
int pop(Stack* s) {
    if (s->size == 0) {
        return -1;
    }
    s->size--;
    return s->value[s->size];
}
Stack* newStack() {
    Stack* result = (Stack*)malloc(sizeof(Stack));
    result->size = 0;
    result->maxSize = 10;
    result->value = (int*)malloc(sizeof(int) * 10);
    result->push = push;
    result->pop = pop;
    return result;
}
void freeStack(Stack* s) {
    free(s->value);
    free(s);
} 

int main() {
    int n, temp;
    char command[6];
    Stack* stack = newStack();
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%s", command);
        switch(command[0]) {
            case 'p': // push, pop 
                if (command[1] == 'o') { // pop
                    printf("%d\n", stack->pop(stack));
                } else { //push
                    scanf("%d", &temp);
                    stack->push(stack, temp);
                }
                break;
            case 's': // size
                printf("%d\n", stack->size);
                break;
            case 'e': // empty
                if (stack->size == 0) {
                    printf("1\n");
                } else {
                    printf("0\n");
                }
                break;
            case 't': // top
                if (stack->size == 0) {
                    printf("-1\n");
                } else {
                    printf("%d\n", stack->value[stack->size-1]);
                }
                break;
        }
    }

    return 0;
}
