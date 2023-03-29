#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct Stack {
    char data[MAX_SIZE];
    int top;
} stack;

void init(stack * s) {
    s->top = 0;
}

int is_empty(stack * s) {
    return s->top == 0;
}

int is_full(stack * s) {
    return s->top >= MAX_SIZE - 1;
}

void push(stack * s, char c) {
    if(is_full(s)) {
        printf("Stack is full!");
    } else {
        s->data[s->top++] = c;
    }
}

void pop(stack * s) {
    if(is_empty(s)) {
        printf("Stack is empty!");
    } else {
        s->top--;
    }
}

char peek(stack * s) {
    return s->data[s->top - 1];
}

int is_valid(char * str) {
    stack s;
    init(&s);
    for (int i = 0; i < strlen(str); i++) {
        char c = str[i];
        if (c == '(' || c == '[' || c == '{') {
            push(&s, c);
        } else if (c == ')' && !is_empty(&s) && peek(&s) == '(') {
            pop(&s);
        } else if (c == ']' && !is_empty(&s) && peek(&s) == '[') {
            pop(&s);
        } else if (c == '}' && !is_empty(&s) && peek(&s) == '{') {
            pop(&s);
        } else {
            return 0;
        }
    }
    return is_empty(&s);
}

int main() {
    char str[MAX_SIZE];
    scanf("%s", str);
    if (is_valid(str)) {
        printf("1\n");
    } else {
        printf("0\n");
    }
    return 0;
}
