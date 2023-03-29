#include<stdio.h>

int main(){
    int n ;
    scanf("%d" , &n) ;
    int a[100001];
    int tong = 0 ;

    for( int i = 0 ; i< n ;i++)
        {
            scanf("%d" , &a[i]);
            tong+= a[i];
        }
    printf("%d" , tong);

}
