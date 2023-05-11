#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct Node{
    int value;
    struct Node* next;
}Node;

Node* makeNode(int v){
    Node* p = (Node*)malloc(sizeof(Node));
    p->next = NULL;
    p->value = v;
    return p;
}

int checkExistence(Node* h, int v)
{
    if(h==NULL) return 0;
    if(h->value==v) return 1;
    return checkExistence(h->next, v);
}

Node* addLast(Node* h, int v){
    if (h==NULL) return makeNode(v);
    h->next = addLast(h->next, v);
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
    if(h==NULL) return NULL;
    if(h->value == u){
        Node* p = makeNode(v);
        p->next = h->next;
        h->next = p;
        return h;
    }
    h->next = addAfter(h->next, u, v);
    return h;
}

Node* addBefore(Node* h, int u, int v)
{
    if (h==NULL) return NULL;
    Node* p = h;
    Node* b = h->next;
    if (h->value == u) return addFirst(h, v);
    if (b->value == u){
        Node* n = makeNode(v);
        n->next = h->next;
        h->next = n;
        return h;
    }
    h->next = addBefore(h->next, u, v);
    return h;
}

Node* Remove(Node* h, int v)
{
    if(h==NULL)return NULL;
    if(h->value==v){
        Node* tmp = h;
        h = h->next;
        free(tmp);
        return h;
    }
    h->next = Remove(h->next, v);
    return h;
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

void printNode(Node* h){
    while(h!=NULL){

        printf("%d ", h->value);
        h = h->next;
    }
    printf("\n");
}

Node* head;

int main()
{
    int n;
    scanf("%d", &n);
    while(n--)
    {
        int d;
        scanf("%d", &d);
        head = addLast(head, d);
    }
    char query[20];
    do{
        scanf("%s", query);
        if (!strcmp(query, "#")) continue;
        if (!strcmp(query, "addlast"))
        {
            int pos;
            scanf("%d", &pos);
            if(!checkExistence(head, pos)) head=addLast(head, pos);
        }
        if (!strcmp(query, "addfirst"))
        {
            int pos;
            scanf("%d", &pos);
            head = addFirst(head, pos);
        }
        if (!strcmp(query, "addafter"))
        {
            int u, v;
            scanf("%d %d", &u,&v);
            if(checkExistence(head, v) && !checkExistence(head, u)) head=addAfter(head, v, u);
        }
        if (!strcmp(query, "addbefore"))
        {
            int u, v;
            scanf("%d %d", &u,&v);
            if(checkExistence(head, v) && !checkExistence(head, u)) head=addBefore(head, v, u);
        }
        if (!strcmp(query, "remove"))
        {
            int v;
            scanf("%d", &v);
            if(checkExistence(head, v)) head=Remove(head, v);
        }
        if (!strcmp(query, "reverse")) head=reverse(head);
    }while(strcmp(query, "#"));
    printNode(head);
}
