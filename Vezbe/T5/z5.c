#include <stdio.h>
#include <math.h>

void prost(int n);

int main() {
    int n;
    printf("Unesite n: ");
    scanf("%d", &n);

    prost(n);

    return 0;
}

void prost(int n) {
    int i;
    int jeProst;
    for(i = 1; i <= n; i++) {
        jeProst = 1;
            if(i == 1) {
                jeProst = 0;
            }
            else {
                for(int j = 2; pow(j,2) <= i; j++) {
                    if (i % j == 0) {
                        jeProst = 0;
                        break;
                    }
                }
            }
        if(jeProst) {
            printf("%d je prost\n", i);
        }
    }
}