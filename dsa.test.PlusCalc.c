#include<stdio.h>
#include<string.h>

int IsDigit(char c){
    if (c>=48 && c<=57) return 1;
    else return 0;
}

int Check(char c[], int size){
    if(c[0]!=43 && c[size-1]!=43){
        for(int i=0; i<size; i++){
            if ((c[i]>=48&&c[i]<=57)||(c[i]==43&&c[i]!=c[i-1])) return 1;
        }
    }
    else return 0;
}

int main(){
    int stack = 0;
    int res = 0;
    char math[1000001];

    scanf("%s", math);
    int len = strlen(math);
    if(Check(math, len)){
       for(int i=strlen(math)-1; i>=0; i--){
            if(IsDigit(math[i])){
                int num = math[i]-48;
                for(int j=0; j<stack; j++) num *= 10;
                res+=num;
                stack++;
            }
            else{
                stack = 0;
            }
        }
        printf("%d", res);
    }
    else printf("NOT_CORRECT");
return 0;
}
