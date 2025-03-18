#include <stdio.h> 
#include <stdlib.h> 

struct list {
    int data;
    struct list* next;
};

typedef struct stack {
    struct list* top;
}Stack;

Stack* create() {
    Stack* S;
    S = (Stack*)malloc(sizeof(Stack));
    S->top = NULL;
    return S;
}

int empty(Stack* S) {
    return(S->top == NULL);
}

char top(Stack* S) {
    return(S->top->data);
}

char pop(Stack* S) {
    char a;
    struct list* p;
    p = S->top;
    a = p->data;
    S->top = p->next;
    free(p);
    return a;
}

void push(Stack* S, int a) {
    struct list* p;
    p = (struct list*)malloc(sizeof(struct list));
    p->data = a;
    p->next = S->top;
    S->top = p;
}

int main() {
    char x;
    Stack* stack = create();

    while (scanf("%c", &x) == 1) {
        if (x == '\0' || x == '\n') {
            break;
        }
        if (x == '+' || x == '-') {
            if (empty(stack) || top(stack) == '(') {
                push(stack, x);
            }
            else {
                printf("%c", pop(stack));
                if (empty(stack) || top(stack) == '(') {
                    push(stack, x);
                }
                else {
                    printf("%c", pop(stack));
                    push(stack, x);
                }
            }
        }
        else if (x == '*' || x == '/') {
            if (empty(stack)  || top(stack) == '(' || top(stack) == '+' || top(stack) == '-') {
                push(stack, x);
            }
            else {
                printf("%c", pop(stack));
                push(stack, x);
            }
        }
        else if (x == ')') {
            while (top(stack) != '(') {
                printf("%c", pop(stack));
            }
            pop(stack);
        }
        else if (x == '(') {
            push(stack, x);
        }
        else {
            printf("%c", x);
        }
    }
    while (empty(stack) == 0) {
        printf("%c", pop(stack));
    }
    return 0;
}



