#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char str[100];
    char f,e;
    scanf("%s %c %c", str , &f, &e);
    int len = strlen(str);
    
    for (int i = 0; i < len; i++) {
        if (str[i] == f) {
            printf("%c", e);
        }
        else
        {printf("%c", str[i]);}
    }
    return 0;
}
