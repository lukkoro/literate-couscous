#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 30

double average(double *A, int n) {
    int i;
    int sum = 0;
    int value;
    for(i = 0; i < n; i++) {
        sum += A[i];
    }

    value = sum/n;

    return value;
}

int minVal(double *A, int n) {
    int i;
    int minIdx = 0;

    for(i = 0; i < n; i++) {
        if(A[i] < A[minIdx]) {
            minIdx = i;
        }
    }

   return minIdx; 
}

int maxVal(double *A, int n) {
    int i;
    int maxIdx = 0;

    for(i = 0; i < n; i++) {
        if(A[i] > A[maxIdx]) {
            maxIdx = i;
        }
    }

    return maxIdx;
}
double sum(double *A, int n) {
    int i;
    double sum = 0;
    for(i = 0; i < n; i++) {
        sum += A[i];
    }

    return sum;
}
int main() {
    double A[MAX_SIZE];
    int i, n;
    
    do {
        printf("Array size: ");
        scanf("%d", &n);
    } while(n < 0 || n > MAX_SIZE);

    for(i = 0; i < n; i++) {
        printf("A[%d] = ", i);
        scanf("%lf", &A[i]);
    }

    int operation = 1;
    double x;
    int idx;
    do {
        printf("List of operations: \t[0] Exit\t[1] Average\t[2] Min value\t[3] Max value\t[4] Sum of all numbers\nEnter a number to select operation: ");
        scanf("%d", &operation);
        switch (operation) {
            case 0:
                exit(-1);
            case 1:
                x = average(A, n);
                printf("Average value of this array is: %.2lf\n", x);
                break;
            case 2:
                idx = minVal(A, n);
                printf("Minimum value of this array is: %.2lf\n", A[idx]);
                break;
            case 3:
                idx = maxVal(A, n);
                printf("Maximum value of this array is: %.2lf\n", A[idx]);
                break;
            case 4:
                x = sum(A, n);
                printf("Sum of this array is: %.2lf\n", x);
                break;
        }

    } while(operation != 0);

    return 0;
}