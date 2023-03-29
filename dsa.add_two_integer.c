#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* sum(char* a, char* b) {
    // Check which string has more digits
    int lenA = strlen(a);
    int lenB = strlen(b);
    if (lenA < lenB) {
        // Pad A with leading zeros
        char* tmp = (char*)malloc(lenB+1);
        memset(tmp, '0', lenB-lenA);
        strcpy(&(tmp[lenB-lenA]), a);
        a = tmp;
    } else if (lenA > lenB) {
        // Pad B with leading zeros
        char* tmp = (char*)malloc(lenA+1);
        memset(tmp, '0', lenA-lenB);
        strcpy(&(tmp[lenA-lenB]), b);
        b = tmp;
    }

    // Perform addition digit by digit
    int mem = 0;
    char* result = (char*)malloc(strlen(a)+2);
    int i;
    for (i=strlen(a)-1; i>=0; i--) {
        int digitA = a[i] - '0';
        int digitB = b[i] - '0';
        int digitSum = digitA + digitB + mem;
        int lastDigit = digitSum % 10;
        mem = digitSum / 10;
        result[i+1] = lastDigit + '0';
    }
    if (mem == 1) {
        result[i+1] = '1';
        result[strlen(a)+1] = '\0';
    } else {
        result++;
    }
    return result;
}

int main() {
    char a[100], b[100];
    scanf("%s %s", a, b);
    printf("%s\n", sum(a, b));
    return 0;
}
