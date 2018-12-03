#include <stdio.h>
#define MAX_SIZE 100

int main() {
    int A[MAX_SIZE];
    int *p;
    int i, n;
    
    do {
        printf("Array size: ");
        scanf("%d", &n);
    } while (n < 0 || n > MAX_SIZE);

    for(i = 0; i < n; i++) {
        printf("A[%d] = ", i);
        scanf("%d", &A[i]);
    }

    p = A;
    int temp;
    printf("\n");
    for(i = 0; i < n/2; i++) {
        temp = *(p+i);
        *(p+i) = *(p+n-1-i);
        *(p+n-1-i) = temp;
    }

    for(i = 0; i < n; i++) {
        printf("A[%d] = %d\n", i, A[i]);
    }

    return 0;
}

