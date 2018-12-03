#include <stdio.h>
#include <math.h>

void prost(int n);
int jeProst(int);

int main() {
    int n;
    do {
        printf("Unesite n: ");
        scanf("%d", &n);
    } while(n < 2 || n % 2 != 0);
    prost(n);
}

int jeProst(int n) {
    int i;
   
    for(i = 2; i <= sqrt(n); i++) {
        if(!(n % i)) {
            return 0;
        }
    }

    return 1;
}

void prost(int n) {
    for(int i = 2; i < n-1; i++) {
        if(jeProst(i) && jeProst(n-i)) {
            printf("%d + %d = %d\n", i, n-i, n);
            return;
        }
    }
}

