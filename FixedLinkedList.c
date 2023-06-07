#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct Node {
    int value;
    struct Node* next;
} Node;

Node* head;

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

Node* addLast(Node* h, int v) {
    if (h == NULL) return makeNode(v);
    h->next = addLast(h->next, v);
    return h;
}

void printNode(Node* h) {
    while (h != NULL) {
        printf("%d ", h->value);
        h = h->next;
    }
    printf("\n");
}

Node* removeNodeRecursive(Node* h, int v) {
    if (h == NULL) return NULL;
    if (h->value == v) {
        Node* tmp = h;
        h = h->next;
        free(tmp);
        return h;
    }
    h->next = removeNodeRecursive(h->next, v);
    return h;
}

Node* addFirst(Node* h, int v) {
    Node* p = makeNode(v);
    p->next = h;
    return p;
}

Node* addAfter(Node* h, int u, int v) {
    Node* q = h;
    Node* p = makeNode(v);
    while (h != NULL) {
        if (h->value == u) {
            p->next = h->next;
            h->next = p;
            return q;
        }
        h = h->next;
    }
    free(p); // Clean up if u is not found
    printf("Node with value %d not found!\n", u);
    return q;
}

Node* addAfterRecursive(Node* h, int u, int v) {
    if (h == NULL) {
        printf("Node with value %d not found!\n", u);
        return h;
    }
    if (h->value == u) {
        Node* p = makeNode(v);
        p->next = h->next;
        h->next = p;
        return h;
    }
    h->next = addAfterRecursive(h->next, u, v);
    return h;
}

int countNodeRecursive(Node* h, int v) {
    if (h == NULL) return 0;
    int cnt = (h->value == v) ? 1 : 0;
    cnt += countNodeRecursive(h->next, v);
    return cnt;
}

Node* reverse(Node* h) {
    Node* p = h;
    Node* prev_p = NULL;
    Node* next_p = NULL;

    while (p != NULL) {
        next_p = p->next;
        p->next = prev_p;
        prev_p = p;
        p = next_p;
    }
    return prev_p;
}

void freeList(Node* h) {
    while (h != NULL) {
        Node* tmp = h;
        h = h->next;
        free(tmp);
    }
}

int main() {
    head = NULL;
    for (int i = 1; i <= 10; i++) {
        head = addLast(head, i);
    }
    printNode(head);
    head = addFirst(head, 20);
    head = addAfter(head, 10, 99);
    head = addAfterRecursive(head, 5, 99);
    head = removeNodeRecursive(head, 6);
    printNode(head);
    head = reverse(head);
    printNode(head);
    printf("%d\n", countNodeRecursive(head, 99));

    // Clean up memory
    freeList(head);
    return 0;
}

