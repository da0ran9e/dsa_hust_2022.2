#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node* next;
} Node;

typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;

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

void enqueue(Queue* queue, int v) {
    Node* newNode = makeNode(v);

    if (queue->front == NULL) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

int dequeue(Queue* queue) {
    if (queue->front == NULL) {
        printf("Queue is empty!\n");
        exit(EXIT_FAILURE);
    }

    Node* dequeuedNode = queue->front;
    int dequeuedValue = dequeuedNode->value;
    queue->front = queue->front->next;

    // If the front becomes NULL after dequeue, rear should also be set to NULL
    if (queue->front == NULL) {
        queue->rear = NULL;
    }

    free(dequeuedNode);
    return dequeuedValue;
}

int peek(Queue* queue) {
    if (queue->front == NULL) {
        printf("Queue is empty!\n");
        exit(EXIT_FAILURE);
    }

    return queue->front->value;
}

int isEmpty(Queue* queue) {
    return (queue->front == NULL);
}

void freeQueue(Queue* queue) {
    Node* current = queue->front;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
    queue->front = NULL;
    queue->rear = NULL;
}

int main() {
    Queue queue;
    queue.front = NULL;
    queue.rear = NULL;

    // Enqueue elements into the queue
    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);

    // Dequeue elements from the queue
    printf("Dequeued value: %d\n", dequeue(&queue));
    printf("Dequeued value: %d\n", dequeue(&queue));

    // Peek at the front of the queue
    printf("Front value: %d\n", peek(&queue));

    // Check if the queue is empty
    printf("Is the queue empty? %s\n", isEmpty(&queue) ? "Yes" : "No");

    // Free memory allocated for the queue
    freeQueue(&queue);

    return 0;
}

