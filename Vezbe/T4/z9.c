#include <stdio.h>
#define MAX 10
#define length 100+1

int main() {
    char string[MAX][length];
    int i, n;

    do {
        printf("Enter the size of strings (max 100): ");
        scanf("%d", &n);
    } while(n<0 || n>length);

    getchar();
    for(i = 0; i < MAX; i++) {
        printf("Enter string %d: ", i+1);
        fgets(string[i], n, stdin);
    }

    for(i = 0; i < MAX; i++) {
        printf("%s", string[i]);
    }

    return 0;
}