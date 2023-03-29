#include<stdio.h>

int main(){
    int t ;
    int a[1001] , b[1001];
    int check[101];
    scanf("%d" , &t);
    for( int i = 0 ; i<=101; i ++)
        check[i] = 1;
    int n,m;
    for( int k = 1 ; k<= t ;k++)
    {
        scanf("%d %d" , &n ,&m);
        for( int i = 1; i<= n ;i++)
            scanf("%d" , &a[i]);
        for( int i = 1 ; i<= m; i++ )
            scanf("%d" , &b[i]);
        if( n == m ){
            for( int i = 1 , j =1 ; i<= n , j<= m ; i++ , j ++ )
            if (a[i] != b[j] ){
                check[k] =  0;
                break;
            }
        }
        else check[k] = 0;
    }
    for( int i = 1; i<= t;i++)
        printf("%d\n", check[i]);
}
