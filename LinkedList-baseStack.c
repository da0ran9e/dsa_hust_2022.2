#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node* next;
} Node;

typedef struct Stack {
    Node* top;
} Stack;

Node* makeNode(int v) {
    Node* p = (Node*)malloc(sizeof(Node));
    if (p == NULL) {
        printf("Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    p->next = NULL;
    p->value = v;
    return p;
}

void push(Stack* stack, int v) {
    Node* newNode = makeNode(v);
    newNode->next = stack->top;
    stack->top = newNode;
}

int pop(Stack* stack) {
    if (stack->top == NULL) {
        printf("Stack is empty!\n");
        exit(EXIT_FAILURE);
    }

    Node* poppedNode = stack->top;
    int poppedValue = poppedNode->value;
    stack->top = stack->top->next;
    free(poppedNode);

    return poppedValue;
}

int peek(Stack* stack) {
    if (stack->top == NULL) {
        printf("Stack is empty!\n");
        exit(EXIT_FAILURE);
    }

    return stack->top->value;
}

int isEmpty(Stack* stack) {
    return (stack->top == NULL);
}

void freeStack(Stack* stack) {
    Node* current = stack->top;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
    stack->top = NULL;
}

int main() {
    Stack stack;
    stack.top = NULL;

    // Push elements onto the stack
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    // Pop elements from the stack
    printf("Popped value: %d\n", pop(&stack));
    printf("Popped value: %d\n", pop(&stack));

    // Peek at the top of the stack
    printf("Top value: %d\n", peek(&stack));

    // Check if the stack is empty
    printf("Is the stack empty? %s\n", isEmpty(&stack) ? "Yes" : "No");

    // Free memory allocated for the stack
    freeStack(&stack);

    return 0;
}

