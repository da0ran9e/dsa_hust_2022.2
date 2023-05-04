#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct Node{
    int value;
    struct Node* next;
}Node;

Node* head;

Node* makeNode(int v){
    Node* p = (Node*)malloc(sizeof(Node));
    p->next = NULL;
    p->value = v;
    return p;
}

Node* addLast(Node* h, int v){
    if (h==NULL) return makeNode(v);
    h->next = addLast(h->next, v);
    return h;
}

void printNode(Node* h){
    while(h!=NULL){
        printf("%d ", h->value);
        h = h->next;
    }
    printf("\n");
}

Node* removeNodeRecursive(Node* h, int v){
    if(h==NULL) return NULL;
    if(h->value == v){
        Node* tmp = h;
        h = h->next;
        free(tmp);
        return h;
    }
    h->next = removeNodeRecursive(h->next, v);
    return h;
}
Node* addFirst(Node* h, int v)
{
    Node* p = makeNode(v);
    p->next = h;
    p->value = v;
    return p;
}
Node* addAfter(Node* h, int u, int v)
{
    Node* q =h;
    Node* p = makeNode(v);
    p->value = v;
    while(h!=NULL){
        if (h->value == u){
            p->next = h->next;
            h->next = p;
            break;
        }
        h=h->next;
    }
    return q;
}
Node* addAfterRecursive(Node* h, int u, int v)
{
    if(h==NULL) return NULL;
    if(h->value == u) {
        Node* p = makeNode(v);
        p->next = h->next;
        h->next = p;
        return h;
    }
    h->next = addAfterRecursive(h->next, u, v);
    return h;
}
int countNodeRecursive(Node* h, int v)
{
    int cnt = 0;
    if (h==NULL) return 0;
    if(h->value == v) cnt++;
    cnt += countNodeRecursive(h->next, v);
    return cnt;
}

Node* reverse(Node* h)
{
    Node* p = h;
    Node* prev_p = NULL;
    Node* next_p = NULL;

    while(p!=NULL){
        next_p = p->next;
        p->next = prev_p;
        prev_p = p;
        p = next_p;
    }
    return prev_p;
}

int main()
{
    head = NULL;
    for(int i=1; i<=10; i++){
        head = addLast(head, i);
    }
    printNode(head);
    head=addFirst(head, 20);
    head=addAfter(head, 10, 99);
    head=addAfterRecursive(head, 5, 99);
    removeNodeRecursive(head, 6);
    printNode(head);
    head = reverse(head);
    printNode(head);
    printf("%d", countNodeRecursive(head, 99));
}
