#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main() {
    char s1[100], s2[100], t[1000], buf[1000];
    fgets(s2, 100, stdin);
    fgets(s1, 100, stdin);
    fgets(t, 1000, stdin);
    s1[strcspn(s1, "\n")] = 0;
    s2[strcspn(s2, "\n")] = 0;
    t[strcspn(t, "\n")] = 0;

    size_t pos = 0, prePos;
    buf[0] = '\0';

    while (1) {
        prePos = pos;
        char* found = strstr(t + pos, s2);
        if (found == NULL) {
            break;
        }
        
        strncat(buf, t + prePos, found - (t + prePos));
        strcat(buf, s1);
        pos = found - t + strlen(s2);
    }
    strcat(buf, t + prePos);

    strcpy(t, buf);

    printf("%s\n", t);  

    return 0;
}
