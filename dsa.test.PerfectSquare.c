#include<stdio.h>
#include<math.h>

int a[100001];
int IsSquare(int x){
    if((int)sqrt(x)*(int)sqrt(x) == x) return 1;
    else return 0;
}
int main(){
    int n;
    scanf("%d" , &n);
    int count = 0;
    for(int i = 1; i<= n; i++){
            scanf("%d" , &a[i]);
            if(IsSquare(a[i])) count++;
        }
    printf("%d\n" , count);
}
