#include <stdio.h>

int main() {
    int n, m;

    printf("Unesite n: ");
    scanf("%d", &n);

    printf("Unesite m: ");
    scanf("%d", &m);

    for(int i = n; i < m; i++) {
        if(i % 4 == 0 && i % 100 > 0 || i % 400 == 0) {
            printf("Godina %d je prestupna godina.\n", i);
        }
    }

    return 0;
}