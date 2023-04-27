#include<stdio.h>
#include<string.h>
#define N_MAX 9999999
#define N_MIN -9999999

int n;
int max = N_MIN;
int min = N_MAX;
int a[N_MAX];

int MinSegment(int x, int y){
    int minS = N_MAX;
    for(int i=x; i<=y; i++)
        if(minS>=a[i]) minS = a[i];
    return minS;
}

int MaxSegment(int x, int y){
    int maxS = N_MIN;
    for(int i=x; i<=y; i++)
        if(maxS<= a[i]) maxS = a[i];
    return maxS;
}

int main(){
    int sum = 0;
    scanf("%d", &n);
    for(int i=1; i<=n; i++){
            scanf("%d", &a[i]);
            if (a[i]>max) max = a[i];
            if (a[i]<min) min = a[i];
            sum+=a[i];
        }
    char query[200];
    do{
        scanf("%s", query);
        if (strcmp(query, "find-max")==0){
            printf("%d\n", max);
        }

        if (strcmp(query, "find-min")==0){
            printf("%d\n", min);
        }
        if (strcmp(query, "find-max-segment")==0){
            int x,y;
            scanf("%d %d" ,&x,&y);
            printf("%d\n", MaxSegment(x,y));
        }
        if (strcmp(query, "find-min-segment")==0){
            int x,y;
            scanf("%d %d" ,&x,&y);
            printf("%d\n", MinSegment(x,y));
        }
        if (strcmp(query, "sum")==0){
            printf("%d\n" , sum);
        }
    }while(strcmp(query, "***")!=0);
    return 0;
}
