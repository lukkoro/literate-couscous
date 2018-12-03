#include <stdio.h>
#include <math.h>

double hipotenuza(double a, double b) {
    double c;

    c = sqrt(pow(a,2)+pow(b,2));

    return c;
}

int main() {
    double a, b, c;
    printf("Unesite katete a i b: ");
    scanf("%lf %lf", &a, &b);

    c = hipotenuza(a,b);

    printf("\tVrednost hipotenuze je: %.2lf\n", c);

    return 0;
}