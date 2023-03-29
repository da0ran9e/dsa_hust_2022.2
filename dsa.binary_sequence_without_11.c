#include <stdio.h>
#include <string.h>
#include <stdlib.h> 

void generate(int n, char* s) {
    if (n == 0) {
        printf("%s\n", s);
        return;
    }
    int len = strlen(s);

    if (s[len - 1] != '1') {
        char* s1 = (char*)malloc(len+2); // allocate memory for new string
        strcpy(s1, s);
        strcat(s1, "0");
        generate(n - 1, s1);

        char* s2 = (char*)malloc(len+2); // allocate memory for new string
        strcpy(s2, s);
        strcat(s2, "1");
        generate(n - 1, s2);

        free(s1); // Free dynamically allocated memory to prevent memory leak
        free(s2);

    } else {
        char* s3 = (char*)malloc(len+2); // allocate memory for new string
        strcpy(s3, s);
        strcat(s3, "0");
        generate(n - 1, s3);

        free(s3);
    }
}

int main() {
    int n;
    scanf("%d", &n);

    char* s = (char*)malloc(sizeof(char)); // allocate memory for initial empty string
    memset(s, '\0', 1); // initialize memory with null terminator

    generate(n, s);

    free(s); // Free dynamically allocated memory to prevent memory leak

    return 0;
}
