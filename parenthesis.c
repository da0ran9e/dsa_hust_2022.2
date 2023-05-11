#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node
{
    char c;
    struct Node* next;
} Node;

Node* top;
char line[1000001];
int match(char a, char b)
{
    if(a == '(' && b == ')') return 1;
    if(a == '[' && b == ']') return 1;
    if(a == '{' && b == '}') return 1;
    return 0;
}

int stackEmpty()
{
    return top == NULL;
}

Node* makeNode(char v)
{
    Node* newnode = (Node*)malloc(sizeof(Node));
    newnode->next = NULL;
    newnode->c = v;
    return newnode;
}

Node* push(char v)
{
    Node* p = makeNode(v);
    p->next = top;
    top = p;
    return top;
}

/*Node* pop()
{
    if(stackEmpty()) return NULL ;
    top = top->next;
    return top;
}*/

char pop()
{
    if(stackEmpty()) return ' ';
    char v = top->c;
    top = top->next;
    return v;
}
char front()
{
    if(stackEmpty()) return ' ';
    char v = top->c;
    //top = top->next;
    return v;
}
int check()
{
    int n = strlen(line);
    for( int i = 0 ; i< n ; i++)
    {
        if(line[i]=='(' || line[i] == '{' || line[i] == '[')
        {
            top = push(line[i]);
            //printf("input\n");
        }
        else
        {
            //if(stackEmpty()) top = push(line[i]);
            if(stackEmpty()) return 0;
            char v = pop();
            if(!match(v,line[i])) return 0;
        }
    }
    return stackEmpty();
}

void print(Node* top){
    for(Node *p = top; p != NULL ; p = p->next)
        printf("%c ", p->c);
    printf("\n");
}
int main()
{
    top = NULL;
    scanf("%s", line);
    printf("%d", check());
    return 0;
}
