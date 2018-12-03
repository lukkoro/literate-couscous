#include <stdio.h>
#include <stdlib.h>

int izracunaj(int);
int nzd(int, int);

int main() {
    int n;
    scanf("%d", &n);
    int iz = izracunaj(n);
    printf("%d\n", iz);
    int nzd1 = nzd(125, 25);
    printf("%d", nzd1);
}

int izracunaj(int n) {
    if(n != 0) {
        return n % 10 + izracunaj(n/10); 
    }
    else {
        return 0;
    }
}

int nzd(int x, int y) {
    if(x == 0) {
        return y;
    }
    else {
        nzd(y % x, x);
    }
}